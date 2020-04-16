#include <iostream>
#include <string>

#include <boost/optional.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "src/ChatConfig.h"

#include "server/Server.hpp"

void initLogger(const std::string& loggerName)
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::warn);
    console_sink->set_pattern("[%g:%#] [%^%l%$] %v");

    std::string logFileName = "logs/" + loggerName + ".txt";

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFileName, true);
    file_sink->set_level(spdlog::level::trace);
    spdlog::set_default_logger(std::make_shared<spdlog::logger>(loggerName,
        spdlog::sinks_init_list({console_sink, file_sink})));
}

int main()
{
    initLogger("server");
    server::Server server;
    std::cout << "hello , this is the first step to make a mircle." << std::endl;
    std::cout << "major:" << Chat_VERSION_MAJOR << " minor:" << Chat_VERSION_MINOR << std::endl;

    spdlog::warn("qcq yes I am fine");
    return 0;
}