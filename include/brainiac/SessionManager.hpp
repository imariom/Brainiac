#ifndef BRAINIAC_SESSION_MANAGER_HPP
#define BRAINIAC_SESSION_MANAGER_HPP

#include <brainiac/Config.hpp>
#include <brainiac/ProxySession.hpp>

namespace brainiac {

class SessionManager
{
public:
    SessionManager();

    void start(ProxySessionPtr ptr);

    void stop();

    void stop_all();

private:
};
    
} // namespace brainiac


#endif // BRAINIAC_SESSION_MANAGER_HPP