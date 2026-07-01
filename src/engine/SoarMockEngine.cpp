// src/engine/SoarMockEngine.cpp
#include "SoarMockEngine.h"
#include "ApiRouter.h"
#include "logging/Logger.h"
#include <httplib.h>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <utility>
#include <unordered_map>

// URL-decode helper
static std::string urlDecode(const std::string& src) {
    std::string out;
    out.reserve(src.size());
    for (size_t i = 0; i < src.size(); ++i) {
        if (src[i] == '%' && i + 2 < src.size()) {
            const char hi = src[i + 1];
            const char lo = src[i + 2];
            auto hexVal = [](char c) -> int {
                if (c >= '0' && c <= '9') return c - '0';
                if (c >= 'A' && c <= 'F') return c - 'A' + 10;
                if (c >= 'a' && c <= 'f') return c - 'a' + 10;
                return -1;
            };
            const int h = hexVal(hi), l = hexVal(lo);
            if (h >= 0 && l >= 0) {
                out += static_cast<char>((h << 4) | l);
                i += 2;
                continue;
            }
        } else if (src[i] == '+') {
            out += ' ';
            continue;
        }
        out += src[i];
    }
    return out;
}

// Parse query string helper
static void parseQueryString(const std::string& qs,
                             std::unordered_map<std::string, std::string>& out) {
    std::istringstream ss(qs);
    std::string token;
    while (std::getline(ss, token, '&')) {
        if (token.empty()) continue;
        const auto eq = token.find('=');
        if (eq != std::string::npos)
            out.insert_or_assign(urlDecode(token.substr(0, eq)),
                                 urlDecode(token.substr(eq + 1)));
        else
            out.insert_or_assign(urlDecode(token), "");
    }
}

void HttplibServerDeleter::operator()(httplib::Server* p) const noexcept {
    delete p;
}

SoarMockEngine::SoarMockEngine(IApiRouter& router)
    : m_router(router)
{}

static std::string nowToString() {
    const auto now = std::chrono::system_clock::now();
    const std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm_buf{};
#ifdef _WIN32
    localtime_s(&tm_buf, &t);
#else
    localtime_r(&t, &tm_buf);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm_buf, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

static uint64_t nowEpochMs() {
    return static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
}

SoarMockEngine::~SoarMockEngine() {
    stop();
}

void SoarMockEngine::configure(const std::string& ip, uint16_t port, bool useTLS) {
    m_ip     = ip;
    m_port   = port;
    m_useTLS = useTLS;
    LOG_INFO("SOAR", "SoarMockEngine configured: " + ip + ":" + std::to_string(port)
        + (useTLS ? " [TLS]" : ""));
}

void SoarMockEngine::setRequestCallback(RequestCallback cb) {
    m_requestCallback = std::move(cb);
}

void SoarMockEngine::dispatch(const httplib::Request& req, httplib::Response& res,
                              const std::string& rawBody) {
    // ---- 요청 로그 ----
    std::ostringstream rawLog;
    rawLog << req.method << " " << req.path << "\n";
    for (const auto& h : req.headers)
        rawLog << "  [header] " << h.first << ": " << h.second << "\n";
    rawLog << "  [body] " << (rawBody.empty() ? "(empty)" : rawBody);
    LOG_WARN("RAW", rawLog.str());

    ApiRequest apiReq;
    apiReq.method = req.method;
    apiReq.body   = rawBody;

    for (const auto& h : req.headers)
        apiReq.headers[h.first] = h.second;

    // ----- [추가된 쿼리 파라미터 파싱 로직] -----
    const auto qpos = req.target.find('?');
    if (qpos != std::string::npos) {
        apiReq.path = req.target.substr(0, qpos);
        parseQueryString(req.target.substr(qpos + 1), apiReq.params);
    } else {
        apiReq.path = req.target;
    }

    // httplib가 기본 파싱한 파라미터(폼 데이터 등) 병합
    for (const auto& p : req.params) {
        apiReq.params.insert_or_assign(p.first, p.second);
    }
    // ---------------------------------------------

    if (m_requestCallback) {
        ApiRequestEntry entry;
        entry.timestamp   = nowToString();
        entry.timestampMs = nowEpochMs();
        entry.method      = apiReq.method;
        entry.path        = apiReq.path;
        entry.body        = apiReq.body;
        entry.sourceIp    = req.remote_addr;
        m_requestCallback(entry);
    }

    const ApiResponse apiResp = m_router.route(apiReq);

    // ---- 응답 로그 ----
    {
        // body가 길면 512자까지만 출력
        static constexpr size_t kMaxBodyLog = 512;
        const std::string& b = apiResp.body;
        const std::string bodySnippet = (b.size() > kMaxBodyLog)
            ? (b.substr(0, kMaxBodyLog) + "...(truncated)")
            : b;
        std::ostringstream respLog;
        respLog << req.method << " " << req.path
                << " -> " << apiResp.statusCode << "\n"
                << "  [body] " << (bodySnippet.empty() ? "(empty)" : bodySnippet);
        LOG_INFO("RESP", respLog.str());
    }

    res.status = apiResp.statusCode;
    for (const auto& h : apiResp.headers)
        res.set_header(h.first.c_str(), h.second.c_str());
    res.set_content(apiResp.body, apiResp.contentType);
}

void SoarMockEngine::registerHandlers() {
    auto withBody = [this](const httplib::Request& req, httplib::Response& res,
                           const httplib::ContentReader& reader) {
        std::string body;
        reader([&](const char* data, size_t len) {
            body.append(data, len);
            return true;
        });
        dispatch(req, res, body);
    };

    auto noBody = [this](const httplib::Request& req, httplib::Response& res) {
        dispatch(req, res, req.body);
    };

    m_server->Post(".*",    withBody);
    m_server->Put(".*",     withBody);
    m_server->Patch(".*",   withBody);
    m_server->Delete(".*",  withBody);
    m_server->Get(".*",     noBody);
    m_server->Options(".*", noBody);
}

void SoarMockEngine::start() {
    if (m_state.load(std::memory_order_acquire) == SoarEngineState::Running) {
        LOG_WARN("SOAR", "SoarMockEngine::start() called while already running");
        return;
    }

    if (m_thread.joinable()) {
        m_thread.join();
        LOG_INFO("SOAR", "SoarMockEngine stale thread joined before restart");
    }

    m_server.reset(new httplib::Server());
    registerHandlers();

    m_running.store(true, std::memory_order_release);
    m_state.store(SoarEngineState::Running, std::memory_order_release);

    LOG_INFO("SOAR", "SoarMockEngine starting: " + m_ip + ":" + std::to_string(m_port));
    m_thread = std::thread(&SoarMockEngine::runLoop, this);
}

void SoarMockEngine::stop() {
    if (m_state.load(std::memory_order_acquire) == SoarEngineState::Idle) {
        if (m_thread.joinable()) m_thread.join();
        return;
    }
    m_running.store(false, std::memory_order_release);
    if (m_server) m_server->stop();
    if (m_thread.joinable()) {
        m_thread.join();
        LOG_INFO("SOAR", "SoarMockEngine thread joined");
    }
    m_server.reset();
    m_state.store(SoarEngineState::Idle, std::memory_order_release);
    LOG_INFO("SOAR", "SoarMockEngine stopped");
}

SoarEngineState SoarMockEngine::getState() const {
    return m_state.load(std::memory_order_acquire);
}

void SoarMockEngine::runLoop() {
    LOG_INFO("SOAR", "SoarMockEngine HTTP server listening on "
        + m_ip + ":" + std::to_string(m_port));

    if (!m_server || !m_server->listen(m_ip.c_str(), m_port)) {
        LOG_ERROR("SOAR", "httplib::Server::listen() failed on "
            + m_ip + ":" + std::to_string(m_port));
        m_running.store(false, std::memory_order_release);
        m_state.store(SoarEngineState::Idle, std::memory_order_release);
        return;
    }

    m_running.store(false, std::memory_order_release);
    m_state.store(SoarEngineState::Idle, std::memory_order_release);
    LOG_INFO("SOAR", "SoarMockEngine HTTP server stopped");
}
