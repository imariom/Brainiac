#ifndef BRAINIAC_PROXY_SERVER_HPP
#define BRAINIAC_PROXY_SERVER_HPP

#include <brainiac/ServerConfig.hpp>
#include <brainiac/ConfigHint.hpp>

namespace brainiac {

class ProxyServer
{
public:
    ProxyServer();
    void run();
};

} // namespace brainiac

#endif // BRAINIAC_PROXY_SERVER_HPP
