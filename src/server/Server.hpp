#ifndef CHAT_SERVER_SERVER_HPP
#define CHAT_SERVER_SERVER_HPP
#include <map>

#include <websocketpp/config/asio.hpp>
#include <websocketpp/server.hpp>

#include <spdlog/spdlog.h>

#include "MessageDispatcher.hpp"
#include "interface/IServer.hpp"
#include "interface/IWebSocketFacade.hpp"

namespace server
{
class Server : public interface::IServer,
               public interface::IWebSocketFacade,
               public std::enable_shared_from_this<Server>
{
public:
    Server();

    void initialize() override;

    void run() override;

    bool isListening() override;

    void stop() override;

    void setDscp(unsigned int) override;

    boost::asio::io_service& getIoService() { return ioService_; }

    ~Server();

protected:
    void accept() override;

    void setHandlers();

    void onOpen(ConnHdl hdl);
    std::string retrieveUserNameFromResource(const std::string& resource);
    bool isNameExist(const std::string& userName, std::string& suggestName);
    void broadCast(const std::string& message);

    bool onValidate(ConnHdl hdl);
    void onMessage(
        ConnHdl hdl,
        websocketpp::server<websocketpp::config::asio>::message_ptr ptr);
    void onClose(ConnHdl hdl);

private:
    const std::string NAME_LABEL;
    const std::string SEPARATOR;
    boost::asio::io_context ioService_;
    websocketpp::server<websocketpp::config::asio> wsServer_;
    uint16_t port_;
    Connection connections_;
    std::shared_ptr<MessageDispatcher> messageDispatcher;
    std::shared_ptr<std::thread> m_thread;
};
}  // namespace server
#endif
