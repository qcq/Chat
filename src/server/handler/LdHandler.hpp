#ifndef CHAT_SERVER_HANDLER_LDHANDLER_HPP
#define CHAT_SERVER_HANDLER_LDHANDLER_HPP

#include "../interface/IHandler.hpp"

namespace server
{
namespace handler
{
class LdHandler : public interface::IHandler
{
public:
    LdHandler();
    ~LdHandler();

    std::string handle(const std::string& message) override;

private:
};
}
}

#endif
