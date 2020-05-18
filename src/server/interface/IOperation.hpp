#ifndef SERVER_INTERFACE_IOPERATION_HPP_
#define SERVER_INTERFACE_IOPERATION_HPP_

#include <memory>

namespace server
{
namespace interface
{
class IOperation : public std::noncopyable
{
public:
    typedef std::shared_ptr<IOperation> Handler;

public:
    virtual ~IOperation() {}
    virtual void operator()() = 0;
};
}
}  // namespace server


#endif
