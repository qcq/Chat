#include "LdHandler.hpp"

namespace server
{
namespace handler
{
LdHandler::LdHandler()
{}

LdHandler::~LdHandler()
{}

std::string LdHandler::handle(
    const interface::IWebSocketFacade::ConnHdl& hdl, const std::string& message)
{
    return "";
}
} // namespace handler

} // namespace server
