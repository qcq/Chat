#ifndef CHAT_SERVER_SERVER_HPP
#define CHAT_SERVER_SERVER_HPP
#include <map>

#include <websocketpp/server.hpp>
#include <websocketpp/config/asio.hpp>

namespace server
{
class Server
{
public:
    Server();

private:
    websocketpp::server<websocketpp::config::asio> wsServer_;
};
} // namespace server
#endif