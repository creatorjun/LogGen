// src/infrastructure/HttpReceiver.cpp
#include "HttpReceiver.h"
#include "engine/IApiRouter.h"
#include "engine/ApiRouter.h"
#include <httplib.h>
#include <chrono>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include "logging/Logger.h"

// URL-decode a percent-encoded string (e.g. %2F -> /, %3D -> =)
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

// Parse key=value&... query string into an unordered_map, URL-decoding both keys and values.
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

static ApiRequest buildApiRequest(const httplib::Request& req) {
    ApiRequest apiReq;
    apiReq.method = req.method;
    apiReq.body   = req.body;

    // req.target holds the original request-URI exactly as it came over the wire.
    // httplib skips query-string parsing when Content-Type is application/json,
    // so we always parse req.target ourselves and URL-decode the values.
    const auto qpos = req.target.find('?');
    if (qpos != std::string::npos) {
        apiReq.path = req.target.substr(0, qpos);
        parseQueryString(req.target.substr(qpos + 1), apiReq.params);
    } else {
        apiReq.path = req.target;
    }

    // Also merge whatever httplib put into req.params (form-encoded body, etc.)
    for (const auto& p : req.params)
        apiReq.params.insert_or_assign(p.first, p.second);

    for (const auto& hdr : req.headers)
        apiReq.headers[hdr.first] = hdr.second;

    return apiReq;
}

HttpReceiver::HttpReceiver(IApiRouter& router)
    : m_router(router)
{}

HttpReceiver::~HttpReceiver() {
    stop();
}

bool HttpReceiver::start(uint16_t port, RequestCallback cb, int threadCount) {
    if (m_running.load()) return false;

    m_callback = std::move(cb);
    m_svr      = std::make_unique<httplib::Server>();

    const int tc = (threadCount > 0) ? threadCount : 4;
    m_svr->new_task_queue = [tc] {
        return new httplib::ThreadPool(tc);
    };

    m_svr->set_default_headers(httplib::Headers{
        {"Access-Control-Allow-Origin", "*"}
    });

    m_svr->set_logger([](const httplib::Request& req, const httplib::Response& res) {
        std::string raw = "[TCP-RAW] " + req.method + " " + req.target + "\n";
        for (const auto& h : req.headers)
            raw += "  [hdr] " + h.first + ": " + h.second + "\n";
        if (!req.params.empty()) {
            raw += "  [params-by-httplib]";
            for (const auto& p : req.params)
                raw += " " + p.first + "=" + p.second;
            raw += "\n";
        } else {
            raw += "  [params-by-httplib] (empty)\n";
        }
        if (req.body.empty())
            raw += "  [raw-body] (empty)\n";
        else
            raw += "  [raw-body] " + req.body + "\n";
        raw += "  [response] status=" + std::to_string(res.status);
        LOG_WARN("RAW", raw);
    });

    auto handler = [this](const httplib::Request& req, httplib::Response& res) {
        const auto reqStart = std::chrono::steady_clock::now();

        const ApiRequest  apiReq  = buildApiRequest(req);

        {
            std::string raw = "[PARSED] " + req.method + " " + apiReq.path + "\n";
            if (!apiReq.params.empty()) {
                raw += "  [params]";
                for (const auto& p : apiReq.params)
                    raw += " " + p.first + "=" + p.second;
                raw += "\n";
            } else {
                raw += "  [params] (empty)\n";
            }
            if (req.body.empty())
                raw += "  [body] (empty)";
            else
                raw += "  [body] " + req.body;
            LOG_WARN("RAW", raw);
        }

        const ApiResponse apiResp = m_router.route(apiReq);

        const auto    reqEnd = std::chrono::steady_clock::now();
        const int64_t lat    = std::chrono::duration_cast<std::chrono::milliseconds>(
                                   reqEnd - reqStart).count();

        res.status = apiResp.statusCode;
        res.set_content(apiResp.body,
            apiResp.contentType.empty() ? "application/json"
                                        : apiResp.contentType.c_str());

        for (const auto& hdr : apiResp.headers)
            res.set_header(hdr.first.c_str(), hdr.second.c_str());

        if (m_callback) {
            auto now = std::chrono::system_clock::now();
            auto t   = std::chrono::system_clock::to_time_t(now);
            struct tm tm_buf{};
#ifdef _WIN32
            localtime_s(&tm_buf, &t);
#else
            localtime_r(&t, &tm_buf);
#endif
            char tsBuf[20];
            std::strftime(tsBuf, sizeof(tsBuf), "%H:%M:%S", &tm_buf);

            ApiRequestEntry entry;
            entry.timestamp   = tsBuf;
            entry.timestampMs = static_cast<uint64_t>(
                std::chrono::duration_cast<std::chrono::milliseconds>(
                    now.time_since_epoch()).count());
            entry.method      = req.method;
            entry.path        = apiReq.path;
            entry.sourceIp    = req.remote_addr;
            entry.body        = req.body;
            entry.statusCode  = apiResp.statusCode;
            entry.latencyMs   = lat;
            m_callback(entry);
        }
    };

    m_svr->Get(".*",    handler);
    m_svr->Post(".*",   handler);
    m_svr->Put(".*",    handler);
    m_svr->Delete(".*", handler);
    m_svr->Options(".*", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Methods",
                       "GET, POST, PUT, DELETE, OPTIONS");
        res.set_header("Access-Control-Allow-Headers",
                       "Content-Type, Authorization, authorization, AuthKey, Cookie");
        res.status = 204;
    });

    if (!m_svr->bind_to_port("0.0.0.0", port)) {
        std::cerr << "[HttpReceiver] Failed to bind port " << port << std::endl;
        m_svr.reset();
        return false;
    }

    m_running.store(true);
    m_thread = std::thread([this]() {
        const bool ok = m_svr->listen_after_bind();
        if (!ok)
            std::cerr << "[HttpReceiver] listen_after_bind() failed." << std::endl;
        m_running.store(false);
    });

    std::cout << "[HttpReceiver] Listening on port " << port
              << " with " << tc << " threads" << std::endl;
    return true;
}

void HttpReceiver::stop() {
    if (!m_running.load()) return;
    m_svr->stop();
    if (m_thread.joinable()) m_thread.join();
    m_running.store(false);
    m_svr.reset();
}

bool HttpReceiver::isRunning() const {
    return m_running.load();
}
