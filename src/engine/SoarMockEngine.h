// src/engine/SoarMockEngine.h
#pragma once

#include "ISoarMockEngine.h"
#include "IApiRouter.h"
#include <atomic>
#include <functional>
#include <memory>
#include <string>
#include <thread>

namespace httplib {
    class Server;
    struct Request;
    struct Response;
}

struct HttplibServerDeleter {
    void operator()(httplib::Server* p) const noexcept;
};

class SoarMockEngine : public ISoarMockEngine {
public:
    explicit SoarMockEngine(IApiRouter& router);
    ~SoarMockEngine() override;

    void configure(const std::string& ip, uint16_t port, bool useTLS) override;
    void setRequestCallback(RequestCallback cb) override;
    void start() override;
    void stop()  override;
    [[nodiscard]] SoarEngineState getState()  const override;
    [[nodiscard]] bool            isRunning() const override {
        return m_state.load(std::memory_order_acquire) == SoarEngineState::Running;
    }

private:
    void dispatch(const httplib::Request& req, httplib::Response& res,
                  const std::string& rawBody);
    void registerHandlers();
    void runLoop();

    std::string  m_ip     = "0.0.0.0";
    uint16_t     m_port   = 8080;
    bool         m_useTLS = false;

    std::unique_ptr<httplib::Server, HttplibServerDeleter> m_server;
    std::thread                      m_thread;
    std::atomic<bool>                m_running{false};
    std::atomic<SoarEngineState>     m_state{SoarEngineState::Idle};

    IApiRouter&      m_router;
    RequestCallback  m_requestCallback;
};
