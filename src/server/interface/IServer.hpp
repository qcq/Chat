#ifndef SERVER_INTERFACE_ISERVER_HPP_
#define SERVER_INTERFACE_ISERVER_HPP_

namespace server
{
namespace interface
{
class IServer
{
public:
    virtual void initialize() = 0;

    virtual void run() = 0;

    virtual bool isListening() = 0;

    virtual void stop() = 0;

    virtual void setDscp(unsigned int) = 0;

    virtual ~IServer() = default;

private:
    virtual void accept() = 0;
};
} // namespace interface
} // namespace server

#endif
