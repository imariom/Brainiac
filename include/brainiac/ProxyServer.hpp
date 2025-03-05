#ifndef BRAINIAC_PROXY_SERVER_HPP
#define BRAINIAC_PROXY_SERVER_HPP

#include <brainiac/Config.hpp>
#include <brainiac/ServerConfig.hpp>
#include <brainiac/SessionManager.hpp>

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/signal_set.hpp>
#include <memory>

namespace brainiac {

class ProxyServer
{
public:
    ProxyServer();
    void run();

private:
    void accept();
    void await_stop();

    net::io_context ioCtx_;
    net::signal_set signals_;
    net::ip::tcp::acceptor acceptor_;
    std::shared_ptr<ServerConfig> config_;
    SessionManager sessionManager_;
};

} // namespace brainiac

#endif // BRAINIAC_PROXY_SERVER_HPP
