#ifndef CHAT_SERVER_MESSAGEDISPATCHER_HPP
#define CHAT_SERVER_MESSAGEDISPATCHER_HPP

#include <memory>
#include <string>

#include <spdlog/spdlog.h>

#include "handler/CdHandler.hpp"
#include "handler/LdHandler.hpp"

namespace server
{
class MessageDispatcher
{
public:
    MessageDispatcher(/* args */);
    ~MessageDispatcher();

    std::string handleMessage(const std::string& message);

private:

    std::shared_ptr<handler::LdHandler> ldHandler;
    std::shared_ptr<handler::CdHandler> cdHandler;
};

}  // namespace server

#endif
