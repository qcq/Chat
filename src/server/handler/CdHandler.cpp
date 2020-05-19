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

void CdHandler::handle(
    const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message)
{
    ;
}
}  // namespace handler

}  // namespace server
