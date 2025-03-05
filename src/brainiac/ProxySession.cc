#include <brainiac/ProxySession.hpp>
#include <brainiac/SessionManager.hpp>

#include <boost/asio/write.hpp>

namespace brainiac {

ProxySession::ProxySession(
    net::ip::tcp::socket downStream,
    SessionManager& sessionManager)
    : downStream_(std::move(downStream))
    , sessionManager_(sessionManager)
{
}

void ProxySession::start()
{
    read();
}

void ProxySession::stop()
{
    boost::system::error_code ec;
    /* downStream_.shutdown(); */
    ec = downStream_.close(ec);
    if (ec)
    {
        // TODO: implement logic to propagete the error
    }
}

void ProxySession::read()
{
    auto self = shared_from_this();
    downStream_.async_read_some(net::buffer(buffer_),
        [this, self](const boost::system::error_code& ec,
            std::size_t bytes_transferred)
        {
            if (!ec)
            {
                // buffer_ has data client data
            }
            else if (ec != net::error::operation_aborted)
            {
                // TODO: log error and terminate the current proxy session
                sessionManager_.stop(shared_from_this());
            }
        });
}

void ProxySession::write()
{
    auto self = shared_from_this();
    net::async_write(downStream_, reply_,
        [this, self](const boost::system::error_code& ec,
            std::size_t bytes_transferred)
        {
            if (!ec)
            {
                // reply_ was sent to client
                boost::system::error_code error;
                downStream_.shutdown(net::ip::tcp::socket::shutdown_both, error);
            }
            else if (ec != net::error::operation_aborted)
            {
                // TODO: log error and terminate the current proxy session
                sessionManager_.stop(shared_from_this());
            }
        });
}

} // namespace brainiac
