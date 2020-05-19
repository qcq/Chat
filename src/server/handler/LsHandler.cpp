#include <algorithm>

#include "LsHandler.hpp"
#include <util/StringUtils.hpp>

namespace server
{
namespace handler
{
LsHandler::LsHandler(
    const websocketpp::server<websocketpp::config::asio>& wsServer,
    const interface::IWebSocketFacade::Connection& connections)
    : wsServer_(wsServer), connections_(connections)
{}

LsHandler::~LsHandler()
{}

void LsHandler::handle(const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message)
{
    auto str = util::StringUtils::removeDupilcateSpace(message);
    str = util::StringUtils::trim(message);
}
}  // namespace handler

}  // namespace server
