#ifndef SERVER_INTERFACE_IOPERATIONFACTORY_HPP_
#define SERVER_INTERFACE_IOPERATIONFACTORY_HPP_

// standard library
#include <map>

namespace server
{
namespace interface
{

}
}  // namespace server

class IOperationFactory : public std::noncopyable
{
public:
    virtual ~IOperationFactory() {}
    static IOperationFactory& GetInstance();

    virtual bool getLsHandler() = 0;
    virtual bool getCdHandler() = 0;
};

#endif
