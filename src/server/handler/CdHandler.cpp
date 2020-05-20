#include <algorithm>
#include <sstream>

#include <util/StringUtils.hpp>

#include "CdHandler.hpp"

namespace server
{
namespace handler
{
CdHandler::CdHandler(
    websocketpp::server<websocketpp::config::asio>& wsServer,
    const interface::IWebSocketFacade::Connection& connections)
    : wsServer_(wsServer), connections_(connections)
{}

CdHandler::~CdHandler()
{}

void CdHandler::handle(const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message)
{
    auto str = util::StringUtils::removeDupilcateSpace(message);
    str = util::StringUtils::trim(message);
    if (str == "cd")
    {
        wsServer_.send(
            hdl, "plese indicate one user who you want talk to.", websocketpp::frame::opcode::text);
        return;
    }
    // remove the 'cd ' from the message
    str.erase(0, 3);
    auto names = util::StringUtils::splitStringBy(str, " ");
    if (names.size() > 1)
    {
        wsServer_.send(
            hdl, "plese indicate one user who you want talk to.", websocketpp::frame::opcode::text);
        return;
    }
    // exit the talk
    if (names[0] == "..")
    {
        wsServer_.send(hdl, "you closed the talk.", websocketpp::frame::opcode::text);
    }
    // here should record who talk who
    auto iter =
        std::find_if(connections_.begin(), connections_.end(), [&names](const auto& connection) {
            return connection.second == names[0];
        });
    if (iter == connections_.end())
    {
        wsServer_.send(
            hdl,
            "plese indicate one exit user who you want talk to.",
            websocketpp::frame::opcode::text);
        return;
    }
    wsServer_.send(hdl, names[0] + ": you are going talk to " + names[0], websocketpp::frame::opcode::text);
}
}  // namespace handler

}  // namespace server
