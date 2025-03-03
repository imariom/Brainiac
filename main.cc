#include <boost/asio.hpp>
#include <boost/json.hpp>
#include <boost/json/src.hpp>

#include <fstream>
#include <iostream>
#include <cstdint>
#include <optional>

namespace brainiac {

namespace net = boost::asio;

enum class config_hint : unsigned short
{
    unknown = 0,

    allowed_ips,
    allowed_ports,
};

class ServerConfig
{
public:
    ServerConfig()
    {
        // load the default "brainiac.yaml" configuration file
        std::ifstream configFile("brainiac.json");
        if (configFile)
        {
        }
    }

    template<typename ConfigValue>
    void set(config_hint hint, const ConfigValue& value)
    {
        config_[hint] = value;
    }

    template<typename ConfigValue>
    void set(config_hint hint, ConfigValue&& value)
    {
        config_[hint] = std::forward<ConfigValue>(value);
    }

    template<typename ConfigValue>
    std::optional<ConfigValue> get(config_hint hint) const
    {
    }


private:
    using config_value = std::variant<
        std::size_t
    >;

    std::unordered_map<config_hint, config_value> config_;
};

class ProxySession
{
public:
    ProxySession()
    {
    }

    void start()
    {
    }
};

class ProxyServer
{
public:
    ProxyServer(ServerConfig config)
        : config_(config)
    {
        // if user provided a list of IPs to use
        // if the user didn't provide the IP (use all available IPs in the host)
        // if user provided port number use it otherwise 5437

        // pass the endpoint
        net::ip::tcp::endpoint endpoint();

        acceptor_ = std::make_shared<net::ip::tcp::acceptor>(endpoint);
    }

    void run()
    {
        start_accept();
    }

private:
    void start_accept()
    {
        acceptor_->async_accept()
    }

    const ServerConfig& config_;
    std::shared_ptr<net::ip::tcp::acceptor> acceptor_;
    std::shared_ptr<net::ip::tcp::socket> socket_;
};


} // namespace brainiac

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: brainiac <port>\n"
            << "    Example: brainiac 5437\n";
        return EXIT_FAILURE;
    }
    std::uint16_t portNumber = std::atoi(argv[1]);

    // load the default "brainiac.yaml" configuration file
    brainiac::ServerConfig config;
    config.allowed_ips();
    config.allowed_port();

    brainiac::ProxyServer server(config);
    server.run();

    return EXIT_SUCCESS;
}

