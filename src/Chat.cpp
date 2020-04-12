#include <iostream>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

#include "src/ChatConfig.h"

    int main() {
    std::cout << "hello , this is the first step to make a mircle." << std::endl;
    std::cout << "major:" << Chat_VERSION_MAJOR << " minor:" << Chat_VERSION_MINOR << std::endl;
    std::cout << boost::optional<int>(6) << std::endl;
    return 0;
}