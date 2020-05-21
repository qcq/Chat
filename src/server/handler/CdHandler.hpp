#ifndef CHAT_SERVER_HANDLER_CDHANDLER_HPP
#define CHAT_SERVER_HANDLER_CDHANDLER_HPP

#include <websocketpp/config/asio.hpp>
#include <websocketpp/server.hpp>

#include "../interface/IHandler.hpp"
#include "../interface/IWebSocketFacade.hpp"

namespace server
{
namespace handler
{
class CdHandler : public interface::IHandler
{
public:
    CdHandler(
        websocketpp::server<websocketpp::config::asio>& wsServer,
        interface::IWebSocketFacade::Connection& connections);
    ~CdHandler();

    void handle(const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message) override;

private:
    websocketpp::server<websocketpp::config::asio>& wsServer_;
    interface::IWebSocketFacade::Connection& connections_;
};
}  // namespace handler
}  // namespace server
#endif
