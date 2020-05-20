#include <string>
#include <vector>

namespace util
{
class StringUtils
{
public:
    static std::string removeAllSpaces(std::string str);
    static std::string trim(std::string str);
    static std::string removeDupilcateSpace(std::string str);
    static std::vector<std::string> splitStringBy(const std::string& str, const std::string& sepeartor);
};
}  // namespace util
