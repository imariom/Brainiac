#ifndef BRAINIAC_PROXY_SESSION_HPP
#define BRAINIAC_PROXY_SESSION_HPP

#include <brainiac/Config.hpp>
#include <brainiac/SessionManager.hpp>

namespace brainiac {

class ProxySession
{
public:
    ProxySession(net::ip::tcp::socket downStream,
        SessionManager& sessionManager);

    void start();

    void stop();

private:
    net::ip::tcp::socket downStream_;
    net::ip::tcp::socket upStream_;
    SessionManager& sessionManager_;
};

using ProxySessionPtr = std::shared_ptr<ProxySession>;

} // namespace brainiac

#endif // BRAINIAC_PROXY_SESSION_HPP
