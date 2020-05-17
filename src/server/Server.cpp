#include "Server.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

namespace server
{

Server::Server() : port_(7890), NAME_LABEL("name"), SEPARATOR("=")
{
    // https://github.com/gabime/spdlog/wiki/0.-FAQ
    /*
    Source information do not appear when using custom format.
    */
    SPDLOG_INFO("created server.");
    messageDispatcher = std::make_shared<MessageDispatcher>();
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
    wsServer_.set_access_channels(
        websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);
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
    wsServer_.run();
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
{}

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
            SPDLOG_ERROR(
                "Websocket listen on port failed! Error code:{} , msg: {}",
                listenEc.value(),
                listenEc.message());
        }
        else
        {
            wsServer_.start_accept(acceptEc);
            if (acceptEc)
            {
                SPDLOG_ERROR(
                    "Websocket start_accept on port failed! Error code:{}  "
                    "msg: {}.",
                    acceptEc.value(),
                    acceptEc.message());
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

    wsServer_.set_open_handler([self](ConnHdl hdl) -> void { self->onOpen(hdl); });

    wsServer_.set_validate_handler([self](ConnHdl hdl) -> bool { return self->onValidate(hdl); });

    wsServer_.set_message_handler(
        [self](ConnHdl hdl, websocketpp::server<websocketpp::config::asio>::message_ptr ptr)
            -> void { self->onMessage(hdl, ptr); });

    wsServer_.set_close_handler([self](ConnHdl hdl) -> void { self->onClose(hdl); });
}

void Server::onOpen(ConnHdl hdl)
{
    SPDLOG_DEBUG("{} connect me.", wsServer_.get_con_from_hdl(hdl)->get_remote_endpoint());
    // connections_[hdl] = "";
    SPDLOG_INFO("{} users online", connections_.size());
    auto resource = wsServer_.get_con_from_hdl(hdl)->get_resource();
    SPDLOG_INFO("request resource {}.", resource);
    auto userName = retrieveUserNameFromResource(resource);
    std::stringstream messageOut;
    if (userName.empty())
    {
        SPDLOG_ERROR("not indicate the username value in resource {}", resource);
        messageOut << "not indicate the username value in url";
        wsServer_.send(hdl, messageOut.str(), websocketpp::frame::opcode::text);
        return;
    }
    // check whether same user name already exist, and give the suggest name.
    std::string suggestName;
    if (isNameExist(userName, suggestName))
    {
        messageOut << "The user name " << userName << "already used by others, may be you can use "
                   << suggestName << " instead.";
        SPDLOG_ERROR(messageOut.str());
        wsServer_.send(hdl, messageOut.str(), websocketpp::frame::opcode::text);
        return;
    }
    connections_[hdl] = userName;
    messageOut << "welcome " << userName;
    SPDLOG_DEBUG("{} connect me.", userName);
    wsServer_.send(hdl, messageOut.str(), websocketpp::frame::opcode::text);
}

std::string Server::retrieveUserNameFromResource(const std::string& resource)
{
    auto position = resource.find(NAME_LABEL);
    if (position == std::string::npos)
    {
        SPDLOG_ERROR("not indicate the username key in resource {}", resource);
        return "";
    }
    position = resource.find(SEPARATOR, position);
    if (position == std::string::npos)
    {
        SPDLOG_ERROR("not indicate the username separator = in resource {}", resource);
        return "";
    }
    auto name = resource.substr(position + 1);
    return name;
}

bool Server::isNameExist(const std::string& userName, std::string& suggestName)
{
    for (const auto& connection : connections_)
    {
        if (userName == connection.second)
        {
            suggestName = connection.second + "1";
            return true;
        }
    }
    return false;
}

bool Server::onValidate(ConnHdl hdl)
{
    auto connPtr = wsServer_.get_con_from_hdl(hdl);
    auto requestedSubprotocols = connPtr->get_requested_subprotocols();
    for (const auto& protocol : requestedSubprotocols)
    {
        SPDLOG_WARN("{}", protocol);
    }

    // below code to set subprotocol
    if (std::find(requestedSubprotocols.begin(), requestedSubprotocols.end(), "binary")
        != requestedSubprotocols.end())
    {
        // connPtr->select_subprotocol("binary");
        return true;
    }
    else
    {
        SPDLOG_DEBUG("can't set binary as subprotocol");
        return true;
    }
}

void Server::onMessage(ConnHdl hdl, websocketpp::server<websocketpp::config::asio>::message_ptr ptr)
{
    std::string message = ptr->get_payload();
    SPDLOG_INFO("message received.{}", message);
    auto messageOut = messageDispatcher->handleMessage(message);
    wsServer_.send(hdl, messageOut, websocketpp::frame::opcode::text);
    /*
    std::stringstream messageOut;
    if (message == "ls")
    {
        messageOut << "current online user list below: \n";
        for (const auto& connection : connections_)
        {
            messageOut << connection.second << "\n";
        }
        messageOut << "congratulation";
        wsServer_.send(hdl, messageOut.str(), websocketpp::frame::opcode::text);
    }
    else if (message.starts_with("cd"))
    {
        if (message.find("..") != std::string::npos)
        {
            // here should delete the connection which used before.
            // if the previous connection non-exist, just sent message which to
            // indicate error.
        }
        // reterive the user which want to talk
        auto userWantTalk = message.substr(message.find_first_of(" ") + 1);
    }
    else
    {
        wsServer_.send(hdl, "congratulation", websocketpp::frame::opcode::text);
    }
    */
}

void Server::onClose(ConnHdl hdl)
{
    // should remove the closed user
    SPDLOG_INFO("{} disconnect me.", wsServer_.get_con_from_hdl(hdl)->get_remote_endpoint());
    connections_.erase(hdl);

    SPDLOG_INFO("{} users online", connections_.size());
}
}  // namespace server
