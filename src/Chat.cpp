#include <iostream>
#include <boost/optional.hpp>

#include "src/ChatConfig.h"

int main() {
    std::cout << "hello , this is the first step to make a mircle." << std::endl;
    std::cout << "major:" << Chat_VERSION_MAJOR << " minor:" << Chat_VERSION_MINOR << std::endl;
    auto opt = boost::optional<int>(6);
    if (opt) {
        std::cout << opt.get() << std::endl;
    }
    return 0;
}