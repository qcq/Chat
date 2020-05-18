#include "MessageDispatcher.hpp"

namespace server
{
MessageDispatcher::MessageDispatcher(
    const websocketpp::server<websocketpp::config::asio>& wsServer,
    const interface::IWebSocketFacade::Connection& connection)
    : wsServer_(wsServer), connections_(connection)
{
    ldHandler = std::make_shared<handler::LdHandler>();
    cdHandler = std::make_shared<handler::CdHandler>();
}

MessageDispatcher::~MessageDispatcher()
{}

void MessageDispatcher::handleMessage(
    const interface::IWebSocketFacade::ConnHdl& hdl, const std::string& message)
{
    /*
    which helps to manage the connection.
    one idea, with linux like command to chat with person
    ls -- list current online user, can with options to query the user if the online
    user too many cd -- get the user who you want talk with, and current the clinet
    should check to that user channel
    */
    if (message.find("ls") != std::string::npos)
    {
        SPDLOG_INFO("ls command received.");
        ldHandler->handle(hdl, message);
    }
    if (message.find("cd") != std::string::npos)
    {
        SPDLOG_INFO("cd command received.");
        cdHandler->handle(hdl, message);
    }

    // take as usual message
}
}  // namespace server
