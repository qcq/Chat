#ifndef CHAT_SERVER_SERVER_HPP
#define CHAT_SERVER_SERVER_HPP
#include <map>

#include <websocketpp/server.hpp>
#include <websocketpp/config/asio.hpp>

#include <spdlog/spdlog.h>

#include "interface/IServer.hpp"

namespace server
{
class Server : public interface::IServer
{
public:
    Server();

    void initialize();

    void run();

    bool isListening();

    void stop();

    void setDscp(unsigned int);

    ~Server() = default;

private:
    void accept();

private:
    websocketpp::server<websocketpp::config::asio> wsServer_;
};
} // namespace server
#endif