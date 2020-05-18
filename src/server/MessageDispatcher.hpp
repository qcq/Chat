#ifndef CHAT_SERVER_MESSAGEDISPATCHER_HPP
#define CHAT_SERVER_MESSAGEDISPATCHER_HPP

#include <memory>
#include <string>

#include <websocketpp/config/asio.hpp>
#include <websocketpp/server.hpp>

#include <spdlog/spdlog.h>

#include "handler/CdHandler.hpp"
#include "handler/LdHandler.hpp"

#include "interface/IWebSocketFacade.hpp"

namespace server
{
class MessageDispatcher
{
public:
    MessageDispatcher(
        const websocketpp::server<websocketpp::config::asio>& wsServer,
        const interface::IWebSocketFacade::Connection& connection);
    ~MessageDispatcher();

    void handleMessage(
        const interface::IWebSocketFacade::ConnHdl& hdl, const std::string& message);

private:
    const websocketpp::server<websocketpp::config::asio>& wsServer_;
    const interface::IWebSocketFacade::Connection& connections_;
    std::shared_ptr<handler::LdHandler> ldHandler;
    std::shared_ptr<handler::CdHandler> cdHandler;
};

}  // namespace server

#endif
