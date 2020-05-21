#include <algorithm>
#include <sstream>

#include <util/AnsiColors.hpp>
#include <util/StringUtils.hpp>

#include <spdlog/spdlog.h>

#include "CdHandler.hpp"

namespace server
{
namespace handler
{
CdHandler::CdHandler(
    websocketpp::server<websocketpp::config::asio>& wsServer,
    interface::IWebSocketFacade::Connection& connections)
    : wsServer_(wsServer), connections_(connections)
{}

CdHandler::~CdHandler()
{}

void CdHandler::handle(const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message)
{
    auto str = util::StringUtils::removeDupilcateSpace(message);
    str = util::StringUtils::trim(str);
    // remove the username prefix
    str.erase(0, str.find(":") + 1);
    SPDLOG_DEBUG(str);
    if (str == "cd")
    {
        wsServer_.send(
            hdl,
            util::AnsiColors::RED + "plese indicate one user who you want talk to.",
            websocketpp::frame::opcode::text);
        return;
    }
    // remove the 'cd ' from the message
    str.erase(0, 3);
    auto names = util::StringUtils::splitStringBy(str, " ");
    if (names.size() > 1)
    {
        wsServer_.send(
            hdl,
            util::AnsiColors::RED + "plese indicate one user who you want talk to.",
            websocketpp::frame::opcode::text);
        return;
    }
    // exit the talk
    if (names[0] == "..")
    {
        if (connections_[hdl].talkingTo.empty())
        {
            wsServer_.send(
                hdl,
                util::AnsiColors::RED + "not talking to anyone, illegal",
                websocketpp::frame::opcode::text);
            return;
        }
        connections_[hdl].talkingTo = "";
        wsServer_.send(
            hdl,
            util::AnsiColors::YELLOW + "you closed the talk.",
            websocketpp::frame::opcode::text);
        return;
    }
    // here should record who talk who
    auto iter =
        std::find_if(connections_.begin(), connections_.end(), [&names](const auto& connection) {
            return connection.second.userName == names[0];
        });
    if (iter == connections_.end())
    {
        wsServer_.send(
            hdl,
            util::AnsiColors::RED + "plese indicate one exit user who you want talk to.",
            websocketpp::frame::opcode::text);
        return;
    }
    connections_[hdl].talkingTo = names[0];
    wsServer_.send(
        hdl,
        util::AnsiColors::YELLOW + "Me: going talk to " + names[0],
        websocketpp::frame::opcode::text);
}
}  // namespace handler

}  // namespace server
