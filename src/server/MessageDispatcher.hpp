#ifndef CHAT_SERVER_MESSAGEDISPATCHER_HPP
#define CHAT_SERVER_MESSAGEDISPATCHER_HPP

#include <memory>
#include <string>

#include <websocketpp/config/asio.hpp>
#include <websocketpp/server.hpp>

#include <spdlog/spdlog.h>

#include "handler/CdHandler.hpp"
#include "handler/LsHandler.hpp"
#include "handler/MessageHandler.hpp"

#include "interface/IWebSocketFacade.hpp"

namespace server
{
class MessageDispatcher
{
public:
    MessageDispatcher(
        websocketpp::server<websocketpp::config::asio>& wsServer,
        interface::IWebSocketFacade::Connection& connections);
    ~MessageDispatcher();

    void handleMessage(
        const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message);

private:
    std::shared_ptr<handler::LsHandler> lsHandler;
    std::shared_ptr<handler::CdHandler> cdHandler;
    std::shared_ptr<handler::MessageHandler> messageHandler;
};

}  // namespace server

#endif
