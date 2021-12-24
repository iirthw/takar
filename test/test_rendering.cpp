#include "gtest/gtest.h"

class TestRendering : public ::testing::Test {
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

TEST(TestCamera, TestCtor)
{    
}