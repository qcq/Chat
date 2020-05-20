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

TEST_F(StringUtilsTest, shouldSplitStringIntoVector)
{
    std::string dataIn("I am Chinese");
    std::string delimiter(" ");
    auto dataOut = ::util::StringUtils::splitStringBy(dataIn, delimiter);

    ASSERT_EQ(dataOut.size(), 3u);
    EXPECT_STREQ(dataOut[0].c_str(), "I");
    EXPECT_STREQ(dataOut[1].c_str(), "am");
    EXPECT_STREQ(dataOut[2].c_str(), "Chinese");
}

TEST_F(StringUtilsTest, shouldSplitStringIntoVectorWithOutEmptyItem)
{
    std::string dataIn("     I am   Chinese    ");
    using namespace ::util;
    std::string delimiter(" ");
    auto dataOut = StringUtils::splitStringBy(
        StringUtils::trim(StringUtils::removeDupilcateSpace(dataIn)), delimiter);

    ASSERT_EQ(dataOut.size(), 3u);
    EXPECT_STREQ(dataOut[0].c_str(), "I");
    EXPECT_STREQ(dataOut[1].c_str(), "am");
    EXPECT_STREQ(dataOut[2].c_str(), "Chinese");
}
}  // namespace util
}  // namespace ut
