#ifndef BRAINIAC_SESSION_MANAGER_HPP
#define BRAINIAC_SESSION_MANAGER_HPP

#include <brainiac/Config.hpp>
#include <brainiac/ProxySession.hpp>

#include <set>

namespace brainiac {

class SessionManager
{
public:
    SessionManager();

    void start(ProxySessionPtr session);

    void stop(ProxySessionPtr session);

    void stop_all();

private:
    // Prevent copying
    SessionManager(const SessionManager&) = delete;
    SessionManager& operator=(const SessionManager&) = delete;

    std::set<ProxySessionPtr> sessions_;
};
    
} // namespace brainiac


#endif // BRAINIAC_SESSION_MANAGER_HPP
