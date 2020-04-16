#include <iostream>
#include "Server.hpp"

namespace server
{

Server::Server()
{
    // https://github.com/gabime/spdlog/wiki/0.-FAQ
    /*
    Source information do not appear when using custom format.
    */
    SPDLOG_WARN("qcq is in server now");
}

void Server::initialize()
{
}

void Server::run()
{
}

bool Server::isListening()
{
    return false;
}

void Server::stop()
{
}

void Server::setDscp(unsigned int)
{
}

void Server::accept()
{
}
} // namespace server