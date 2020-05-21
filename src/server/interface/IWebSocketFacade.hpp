#ifndef SERVER_INTERFACE_IWEBSOCKETFACADE_HPP_
#define SERVER_INTERFACE_IWEBSOCKETFACADE_HPP_

#include <map>
#include <memory>

#include "../UserManager.hpp"

namespace server
{
namespace interface
{
class IWebSocketFacade
{
public:
    typedef std::weak_ptr<void> ConnHdl;
    typedef std::map<ConnHdl, UserInfo, std::owner_less<ConnHdl>> Connection;
};
}  // namespace interface
}  // namespace server

#endif
