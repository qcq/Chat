#ifndef CHAT_SERVER_HANDLER_CDHANDLER_HPP
#define CHAT_SERVER_HANDLER_CDHANDLER_HPP

#include "../interface/IHandler.hpp"

namespace server
{
namespace handler
{
class CdHandler : public interface::IHandler
{
public:
    CdHandler();
    ~CdHandler();

    void handle(
        const interface::IWebSocketFacade::ConnHdl& hdl, const std::string& message) override;

private:
};
}  // namespace handler
}  // namespace server
#endif
