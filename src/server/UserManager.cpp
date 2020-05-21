#include "UserManager.hpp"

namespace server
{

std::ostream& operator<<(std::ostream& out, UserInfo& A)
{
    out << "user name:" << A.userName << " Talking to " << A.talkingTo;
    return out;
}
}
