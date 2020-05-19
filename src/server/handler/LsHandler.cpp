#include <algorithm>
#include <sstream>

#include "LsHandler.hpp"
#include <util/StringUtils.hpp>

namespace server
{
namespace handler
{
LsHandler::LsHandler(
    websocketpp::server<websocketpp::config::asio>& wsServer,
    const interface::IWebSocketFacade::Connection& connections)
    : wsServer_(wsServer), connections_(connections)
{}

LsHandler::~LsHandler()
{}

void LsHandler::handle(const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message)
{
    auto str = util::StringUtils::removeDupilcateSpace(message);
    str = util::StringUtils::trim(message);
    std::stringstream out;
    out << "current online user list below: \n";
    if (message == "ls")
    {
        for (const auto& connection : connections_)
        {
            out << connection.second << "\n";
        }
        wsServer_.send(hdl, out.str(), websocketpp::frame::opcode::text);
    }

}
}  // namespace handler

}  // namespace server
