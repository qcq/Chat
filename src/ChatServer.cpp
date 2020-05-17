#include <iostream>
#include <string>

#include <boost/optional.hpp>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include "src/ChatConfig.h"

#include "server/Server.hpp"

void initLogger(const std::string& loggerName)
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::debug);
    console_sink->set_pattern("[%g:%#] [%^%l%$] %v");

    std::string logFileName = "logs/" + loggerName + ".txt";

    auto file_sink =
        std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFileName, true);
    file_sink->set_level(spdlog::level::debug);
    spdlog::set_default_logger(std::make_shared<spdlog::logger>(
        loggerName, spdlog::sinks_init_list({console_sink, file_sink})));
    spdlog::flush_every(std::chrono::seconds(5));
}

int main()
{
    std::cout << "major:" << Chat_VERSION_MAJOR
              << " minor:" << Chat_VERSION_MINOR << std::endl;
    initLogger("server");
    auto server = std::make_shared<server::Server>();
    server->initialize();

    server->run();
    // server->getIoService().run();
    return 0;
}