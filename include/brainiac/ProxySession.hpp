#ifndef BRAINIAC_PROXY_SESSION_HPP
#define BRAINIAC_PROXY_SESSION_HPP

#include <brainiac/Config.hpp>

#include <boost/asio/ip/tcp.hpp>
#include <memory>

namespace brainiac {

class SessionManager;

class ProxySession
    : public std::enable_shared_from_this<ProxySession>
{
public:
    explicit ProxySession(net::ip::tcp::socket downStream,
        SessionManager& sessionManager);

    void start();

    void stop();

private:
    // Prevent copying
    ProxySession(const ProxySession&) = delete;
    ProxySession& operator=(const ProxySession&) = delete;

    void read();
    void write();

    net::ip::tcp::socket downStream_;
    SessionManager& sessionManager_;
    std::array<char, 8192> buffer_;
    // request
    // request_parser
    // reply
};

using ProxySessionPtr = std::shared_ptr<ProxySession>;

} // namespace brainiac

#endif // BRAINIAC_PROXY_SESSION_HPP
