#include <brainiac/SessionManager.hpp>

namespace brainiac {

SessionManager::SessionManager()
{
}

void SessionManager::start(ProxySessionPtr session)
{
    sessions_.insert(session);
    session->start();
}

void SessionManager::stop(ProxySessionPtr session)
{
    sessions_.erase(session);
    session->stop();
}

void SessionManager::stop_all()
{
    for (auto session : sessions_)
        session->stop();
    sessions_.clear();
}

} // namespace brainiac
