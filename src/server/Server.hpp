#ifndef CHAT_SERVER_SERVER_HPP
#define CHAT_SERVER_SERVER_HPP
#include <map>

#include <websocketpp/server.hpp>
#include <websocketpp/config/asio.hpp>

#include <spdlog/spdlog.h>

#include "interface/IServer.hpp"

namespace server
{
class Server : public interface::IServer, public std::enable_shared_from_this<Server>
{
public:
    typedef std::weak_ptr<void> ConnHdl;
    Server();

    void initialize() override;

    void run() override;

    bool isListening() override;

    void stop() override;

    void setDscp(unsigned int) override;

    boost::asio::io_service &getIoService()
    {
        return ioService_;
    }

    ~Server();

private:
    void accept() override;

    void setHandlers();

    void onOpen(ConnHdl hdl);
    bool onValidate(ConnHdl hdl);
    void onMessage(ConnHdl hdl, websocketpp::server<websocketpp::config::asio>::message_ptr ptr);
    void onClose(ConnHdl hdl);

private:
    boost::asio::io_context ioService_;
    websocketpp::server<websocketpp::config::asio> wsServer_;
    uint16_t port_;
    std::map<ConnHdl, std::string, std::owner_less<ConnHdl>> connections_;
};
} // namespace server
#endif