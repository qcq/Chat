#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
#include <string>

#include <Server.hpp>

using namespace testing;

class ServerTest : public Test
{
public:
    std::shared_ptr<server::Server> sut_ = std::make_shared<server::Server>();
};

TEST_F(ServerTest, shouldEqual)
{
    EXPECT_EQ(2, 2);
}