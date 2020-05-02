#include <iostream>
#include <fstream>
#include "Server.hpp"

namespace server
{

Server::Server() : port_(7890)
{
    // https://github.com/gabime/spdlog/wiki/0.-FAQ
    /*
    Source information do not appear when using custom format.
    */
    SPDLOG_INFO("created server.");
}

Server::~Server()
{
    SPDLOG_INFO("the server ready to go down.");
    stop();
}

void Server::initialize()
{
    SPDLOG_INFO("initialize the server.");

    // setting the log direct to
    // std::string logName = "logs/server.txt";
    // std::ofstream fout(logName, std::ios::out);

    wsServer_.get_alog().set_ostream(&std::cout);
    wsServer_.set_access_channels(websocketpp::log::alevel::all);
    wsServer_.set_error_channels(websocketpp::log::elevel::all);

    std::error_code initEc;
    wsServer_.set_user_agent("Chat-Sever");
    wsServer_.init_asio(&ioService_, initEc);

    if (initEc)
    {
        SPDLOG_ERROR("WsServer initAsio failed");
    }

    wsServer_.set_reuse_addr(true);
    setHandlers();
}

void Server::run()
{
    SPDLOG_INFO("the server ready to accept the income connect.");
    accept();
}

bool Server::isListening()
{
    return wsServer_.is_listening();
}

void Server::stop()
{
    std::error_code stopEc;
    if (isListening())
    {
        wsServer_.stop_listening(stopEc);
    }
}

void Server::setDscp(unsigned int)
{
}

void Server::accept()
{
    SPDLOG_INFO("Websocket Server starting to listen on port: {}", port_);
    bool ok;
    do
    {
        ok = true;
        std::error_code listenEc;
        std::error_code acceptEc;
        wsServer_.listen(port_, listenEc);
        if (listenEc)
        {
            SPDLOG_ERROR("Websocket listen on port failed! Error code:{} , msg: {}",
                         listenEc.value(), listenEc.message());
        }
        else
        {
            wsServer_.start_accept(acceptEc);
            if (acceptEc)
            {
                SPDLOG_ERROR("Websocket start_accept on port failed! Error code:{}  msg: {}.",
                             acceptEc.value(), acceptEc.message());
            }
        }
        if (acceptEc || listenEc)
        {
            ok = false;
            sleep(5);
        }
    } while (!ok);
}

void Server::setHandlers()
{
    wsServer_.set_open_handshake_timeout(50);

    auto self = this->shared_from_this();

    wsServer_.set_open_handler(
        [self](ConnHdl hdl) -> void {
            self->onOpen(hdl);
        });

    wsServer_.set_message_handler(
        [self](ConnHdl hdl, websocketpp::server<websocketpp::config::asio>::message_ptr ptr) -> void {
            self->onMessage(hdl, ptr);
        });
}

void Server::onOpen(ConnHdl hdl)
{
    SPDLOG_INFO("some body is try to connect me.");
    connections_[wsServer_.get_con_from_hdl(hdl)->get_remote_endpoint()] = hdl;
}

void Server::onMessage(ConnHdl hdl, websocketpp::server<websocketpp::config::asio>::message_ptr ptr)
{
    auto message = std::string(ptr->get_raw_payload().begin(), ptr->get_raw_payload().end());
    SPDLOG_DEBUG("message received.{}", message);
    wsServer_.get_con_from_hdl(hdl)->send("yes you are here. congratulation");
}
} // namespace server