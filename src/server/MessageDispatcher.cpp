#include "MessageDispatcher.hpp"

namespace server
{
MessageDispatcher::MessageDispatcher(/* args */)
{
    ldHandler = std::make_shared<handler::LdHandler>();
    cdHandler = std::make_shared<handler::CdHandler>();
}

MessageDispatcher::~MessageDispatcher()
{}

std::string MessageDispatcher::handleMessage(const std::string& message)
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
        return ldHandler->handle(message);
    }
    if (message.find("cd") != std::string::npos)
    {
        SPDLOG_INFO("cd command received.");
        return cdHandler->handle(message);
    }

    // take as usual message
    return "";
}
}  // namespace server
