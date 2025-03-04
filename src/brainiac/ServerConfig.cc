#include <brainiac/ServerConfig.hpp>
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
        std::cout << "Not loaded" << std::endl;
    }
    else
    {
        std::string content((std::istreambuf_iterator<char>(configFile)),
            std::istreambuf_iterator<char>());
        boost::json::value value = boost::json::parse(content);
        // server
        // logging
        // cache
        // rateLimiting
        // authentication
        // isFiltering
        // ssl
        // loadBalancing
        // metrics
    }
}

} // namespace brainiac
