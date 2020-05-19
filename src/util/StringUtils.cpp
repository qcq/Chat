#include <algorithm>
#include "StringUtils.hpp"

namespace util
{
std::string StringUtils::removeAllSpaces(std::string str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    return str;
}

std::string StringUtils::trim(std::string str)
{
    while (not str.empty() and str[0] == ' ')
    {
        str.erase(str.begin());
    }
    while (not str.empty() and str[str.size() - 1] == ' ')
    {
        str.erase(str.end() - 1);
    }
    return str;
}

std::string StringUtils::removeDupilcateSpace(std::string str)
{
    auto new_end = std::unique(str.begin(), str.end(), [](char lhs, char rhs) -> bool {
        return (lhs == rhs) && (std::isspace(lhs));
    });
    str.erase(new_end, str.end());
    return str;
}
}
