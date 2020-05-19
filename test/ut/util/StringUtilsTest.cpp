#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <memory>
#include <string>

#include <StringUtils.hpp>

using namespace testing;

namespace ut
{
namespace util
{
class StringUtilsTest : public Test
{
public:
};

TEST_F(StringUtilsTest, shouldRemoveHeadAndTailSpace)
{
    std::string dataIn("     I am   Chinese    ");
    std::string expected("I am   Chinese");
    EXPECT_EQ(expected, ::util::StringUtils::trim(dataIn));
}

TEST_F(StringUtilsTest, shouldRemoveAllSpace)
{
    std::string dataIn("     I am   Chinese    ");
    std::string expected("IamChinese");
    EXPECT_EQ(expected, ::util::StringUtils::removeAllSpaces(dataIn));
}

TEST_F(StringUtilsTest, shouldRemoveDuplicateSpace)
{
    std::string dataIn("     I am   Chinese    ");
    std::string expected(" I am Chinese ");
    EXPECT_EQ(expected, ::util::StringUtils::removeDupilcateSpace(dataIn));
}
}  // namespace util
}  // namespace ut
