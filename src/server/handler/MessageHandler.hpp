#ifndef CHAT_SERVER_HANDLER_MESSAGEHANDLER_HPP
#define CHAT_SERVER_HANDLER_MESSAGEHANDLER_HPP

#include <websocketpp/config/asio.hpp>
#include <websocketpp/server.hpp>

#include "../interface/IHandler.hpp"
#include "../interface/IWebSocketFacade.hpp"

namespace server
{
namespace handler
{
class MessageHandler : public interface::IHandler
{
public:
    MessageHandler(
        const websocketpp::server<websocketpp::config::asio>& wsServer,
        const interface::IWebSocketFacade::Connection& connections);
    ~MessageHandler();
    void handle(
        const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message) override;
private:
    const websocketpp::server<websocketpp::config::asio>& wsServer_;
    const interface::IWebSocketFacade::Connection& connections_;
};
}
}
#endif
