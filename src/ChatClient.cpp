#include <iostream>
#include <boost/optional.hpp>

#include "src/ChatConfig.h"

#include "client/Client.hpp"

int main()
{
    client::Client client;
    std::cout << "hello , this is the first step to make a mircle."
              << std::endl;
    std::cout << "major:" << Chat_VERSION_MAJOR
              << " minor:" << Chat_VERSION_MINOR << std::endl;
    return 0;
}