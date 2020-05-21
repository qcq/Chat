#ifndef CHAT_SERVER_USERINFO_HPP
#define CHAT_SERVER_USERINFO_HPP
#include <string>
#include <iostream>

namespace server
{
struct UserInfo
{
    std::string userName;
    std::string talkingTo;
    operator std::string() const
    {
        return userName;
    }
    friend std::ostream& operator<<(std::ostream& out, UserInfo& A);
};
}
#endif
