#include <iostream>
#include <boost/optional.hpp>

#include "src/ChatConfig.h"

#include "server/Server.hpp"

int main() {
    server::Server server;
    std::cout << "hello , this is the first step to make a mircle." << std::endl;
    std::cout << "major:" << Chat_VERSION_MAJOR << " minor:" << Chat_VERSION_MINOR << std::endl;
    return 0;
}