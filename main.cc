#include <iostream>
#include <boost/asio.hpp>

class ProxySession
{
public:
    ProxySession(std::shared_ptr<boost::asio::ip::tcp::socket> socketPtr)
    {
    }

    void start()
    {
    }
};

class ProxyServer
{
public:
    ProxyServer(boost::asio::io_context& ioContext, std::uint16_t portNumber)
        : _acceptor{ioContext}, _ioContext{ioContext}
    {
        initialize(portNumber);
        startAccept();
    }

private:
    void initialize(std::uint16_t portNumber)
    {
        boost::asio::ip::tcp::endpoint endpoint {
            boost::asio::ip::tcp::v4(),
            portNumber
        };

        _acceptor.open(endpoint.protocol());
        _acceptor.bind(endpoint);
        _acceptor.listen();
    }

    void startAccept()
    {
        auto socketPtr = std::make_shared<boost::asio::ip::tcp::socket>(_ioContext);

        _acceptor.async_accept(*socketPtr.get(),
            [this, socketPtr](const boost::system::error_code& errCode)
            {
                if (!errCode)
                    std::make_shared<ProxySession>(socketPtr)->start();
                else
                    std::cerr << "Failed to accept: " << errCode.value()
                        << ". Message: " << errCode.message();
                startAccept();
            });
    }

private:
    boost::asio::ip::tcp::acceptor _acceptor;
    boost::asio::io_context& _ioContext;
};

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: proxy_server <port>\n";
        return -1;
    }
    std::uint16_t portNumber = std::atoi(argv[1]);

    try
    {
        boost::asio::io_context ioContext{};
        ProxyServer server{ioContext, portNumber};

        ioContext.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
        return -1;
    }
}
