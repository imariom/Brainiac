#include <brainiac/ProxyServer.hpp>

namespace brainiac {

ProxyServer::ProxyServer()
    : ioCtx_()
    , signals_(ioCtx_)
    , acceptor_(ioCtx_)
    , config_(std::make_shared<ServerConfig>())
{
    signals_.add(SIGINT);
    signals_.add(SIGTERM);
#if defined(SIGQUIT)
    signals_.add(SIGQUIT);
#endif // defined(SIGQUIT)

    await_stop();

    boost::json::string host = config_->get<boost::json::string>(ConfigHint::host)
        .value();
    std::int64_t port = config_->get<std::int64_t>(ConfigHint::port)
        .value();

    net::ip::tcp::resolver resolver(ioCtx_);
    net::ip::tcp::endpoint endpoint =
        *resolver.resolve(std::string(host), std::to_string(port)).begin();

    acceptor_.open(endpoint.protocol());
    acceptor_.set_option(net::ip::tcp::acceptor::reuse_address(true));
    acceptor_.bind(endpoint);
    acceptor_.listen();

    accept();
}

void ProxyServer::run()
{
    ioCtx_.run();
}

void ProxyServer::accept()
{
    acceptor_.async_accept(
        [this](const boost::system::error_code& ec,
            net::ip::tcp::socket socket)
        {
            if (!acceptor_.is_open())
            {
                return;
            }
            if (!ec)
            {
                sessionManager_.start(
                    std::make_shared<ProxySession>(std::move(socket),
                        sessionManager_));
            }
            else
            {
                // TODO: log connection failure to be viewed in the Proxy Server UI
            }

            accept();
        });
}

void ProxyServer::await_stop()
{
    signals_.async_wait(
        [this](const boost::system::error_code& ec, int signo)
        {
            acceptor_.close();
            sessionManager_.stop_all();
        });
}

} // namespace brainiac
