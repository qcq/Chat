#include <algorithm>
#include <sstream>

#include <util/StringUtils.hpp>
#include "LsHandler.hpp"

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
    if (str == "ls")
    {
        for (const auto& connection : connections_)
        {
            out << connection.second << "\n";
        }
        wsServer_.send(hdl, out.str(), websocketpp::frame::opcode::text);
        return;
    }
    // remove the ls plus space
    str.erase(0, 3);
    auto names = util::StringUtils::splitStringBy(str, " ");

    for (const auto& connection : connections_)
    {
        auto iter =
            std::find_if(names.begin(), names.end(), [&connection](const std::string& name) {
                return connection.second.find(name) != std::string::npos;
            });
        if (iter != names.end())
        {
            out << connection.second << "\n";
        }
    }
    wsServer_.send(hdl, out.str(), websocketpp::frame::opcode::text);
}
}  // namespace handler

}  // namespace server
