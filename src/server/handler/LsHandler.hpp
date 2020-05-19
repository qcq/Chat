#ifndef CHAT_SERVER_HANDLER_LSHANDLER_HPP
#define CHAT_SERVER_HANDLER_LSHANDLER_HPP

#include <websocketpp/config/asio.hpp>
#include <websocketpp/server.hpp>

#include "../interface/IHandler.hpp"
#include "../interface/IWebSocketFacade.hpp"

namespace server
{
namespace handler
{
class LsHandler : public interface::IHandler
{
public:
    LsHandler(
        websocketpp::server<websocketpp::config::asio>& wsServer,
        const interface::IWebSocketFacade::Connection& connections);
    ~LsHandler();

    void handle(const interface::IWebSocketFacade::ConnHdl& hdl, std::string& message) override;

private:
    websocketpp::server<websocketpp::config::asio>& wsServer_;
    const interface::IWebSocketFacade::Connection& connections_;
};
}
}

#endif
