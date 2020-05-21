#include "MessageHandler.hpp"

#include "MessageHandler.hpp"

#include "util/AnsiColors.hpp"

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
{
    auto talkingTo = connections_[hdl].talkingTo;
    auto iter = std::find_if(
        connections_.begin(), connections_.end(), [&talkingTo](const auto& connection) {
            return !talkingTo.empty() && (connection.second.userName == talkingTo);
        });
    if (iter == connections_.end())
    {
        wsServer_.send(
            hdl,
            util::AnsiColors::RED + "user you are talking to non-exist current.",
            websocketpp::frame::opcode::text);
        connections_[hdl].talkingTo = "";
        return;
    }
    wsServer_
        .send(iter->first, util::AnsiColors::GREEN + message, websocketpp::frame::opcode::text);
}
}  // namespace handler

}  // namespace server
