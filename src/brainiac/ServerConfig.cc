#include <brainiac/ServerConfig.hpp>
#include <brainiac/ConfigHint.hpp>
#include <boost/json/src.hpp>

#include <fstream>
#include <iostream>

namespace brainiac {

ServerConfig::ServerConfig()
{
    std::ifstream configFile("./brainiac.json");
    if (!configFile)
    {
        // TODO: if the file does not exist generate it with default values
        return;
    }

    std::string content((std::istreambuf_iterator<char>(configFile)),
        std::istreambuf_iterator<char>());

    boost::system::error_code ec;
    boost::json::value value = boost::json::parse(content, ec);

    if (!ec)
    {
        // TODO: if the configruation file is invalid
        std::cerr << "Error: " << ec.what()
            << ". Message: " << ec.message() 
            << ". Code: " << ec.value() << '\n';
        return;
    }

    // server configurations
    boost::json::object server = value.at("server").as_object();

    config_[ConfigHint::port] = server.at("port").as_int64();
    config_[ConfigHint::host] = server.at("host").as_string();
    config_[ConfigHint::timeout] = server.at("timeout").as_int64();
    config_[ConfigHint::max_connections] = server.at("maxConnections").as_int64();
}

} // namespace brainiac
