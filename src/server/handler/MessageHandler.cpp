#include "MessageHandler.hpp"

#include "MessageHandler.hpp"

namespace server
{
namespace handler
{
MessageHandler::MessageHandler(
    websocketpp::server<websocketpp::config::asio>& wsServer,
    interface::IWebSocketFacade::Connection& connections)
    : wsServer_(wsServer), connections_(connections)
{}

MessageHandler::~MessageHandler()
{}

void MessageHandler::handle(const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message)
{}
}  // namespace handler

}  // namespace server
