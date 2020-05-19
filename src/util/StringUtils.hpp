#include <string>

namespace util
{
class StringUtils
{
public:
    static std::string removeAllSpaces(std::string str);
    static std::string trim(std::string str);
    static std::string removeDupilcateSpace(std::string str);
};
}  // namespace util
