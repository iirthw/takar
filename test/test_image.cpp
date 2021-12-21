#include "gtest/gtest.h"

#include "image.h"

class TestSuite1 : public ::testing::Test {
public:

    static std::string workingDir()
    {
        static std::string workDir =
            testing::UnitTest::GetInstance()->original_working_dir();

        return workDir;
    }

protected:

    void SetUp() override
    {}

    // void TearDown() override {}
};

TEST(TestSuite1, TestCtor)
{
    ASSERT_TRUE(false);
}