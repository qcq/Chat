#include "CdHandler.hpp"

namespace server
{
namespace handler
{
CdHandler::CdHandler()
{}

CdHandler::~CdHandler()
{}

std::string CdHandler::handle(
    const interface::IWebSocketFacade::ConnHdl& hdl, const std::string& message)
{
    return "";
}
}  // namespace handler

}  // namespace server
