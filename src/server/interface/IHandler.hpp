#ifndef SERVER_INTERFACE_IHANDLER_HPP_
#define SERVER_INTERFACE_IHANDLER_HPP_

#include <string>

namespace server
{
namespace interface
{
class IHandler
{
public:
    virtual std::string handle(const std::string& message) = 0;
};
}  // namespace interface
}  // namespace server

#endif
