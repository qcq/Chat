#include "MessageDispatcher.hpp"

namespace server
{
MessageDispatcher::MessageDispatcher(
    const websocketpp::server<websocketpp::config::asio>& wsServer,
    const interface::IWebSocketFacade::Connection& connections)
{
    lsHandler = std::make_shared<handler::LsHandler>(wsServer, connections);
    cdHandler = std::make_shared<handler::CdHandler>(wsServer, connections);
}

MessageDispatcher::~MessageDispatcher()
{}

void MessageDispatcher::handleMessage(
    const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message)
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
        lsHandler->handle(hdl, message);
    }
    if (message.find("cd") != std::string::npos)
    {
        SPDLOG_INFO("cd command received.");
        cdHandler->handle(hdl, message);
    }

    // take as usual message

}
}  // namespace server
