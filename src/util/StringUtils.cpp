#include "StringUtils.hpp"
#include <algorithm>

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

std::vector<std::string> StringUtils::splitStringBy(
    const std::string& str, const std::string& sepeartor)
{
    std::vector<std::string> output;
    std::string::size_type pos(0), findPos;
    findPos = str.find_first_of(sepeartor);
    while (std::string::npos != findPos)
    {
        auto splitString = str.substr(pos, findPos - pos);
        output.push_back(splitString);

        pos = findPos + 1;
        findPos = str.find_first_of(sepeartor, pos);
    }
    auto splitString = str.substr(pos, findPos - pos);
    output.push_back(splitString);

    return output;
}
}  // namespace util
