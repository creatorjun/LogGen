// src/infrastructure/HttpReceiver.h
#pragma once

#include <thread>
#include <atomic>
#include <memory>
#include "infrastructure/IReceiver.h"

namespace httplib { class Server; }

class IApiRouter;

class HttpReceiver : public IReceiver {
public:
    explicit HttpReceiver(IApiRouter& router);
    ~HttpReceiver() override;

    [[nodiscard]] bool start(uint16_t port, RequestCallback cb,
                             int threadCount = 4)   override;
    void               stop()                       override;
    [[nodiscard]] bool isRunning() const            override;

private:
    IApiRouter&                      m_router;
    RequestCallback                  m_callback;
    std::unique_ptr<httplib::Server> m_svr;
    std::thread                      m_thread;
    std::atomic<bool>                m_running{false};
};
