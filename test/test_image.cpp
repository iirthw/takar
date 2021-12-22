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

TEST(TesImage, TestCtor)
{
    {
        tkr::Image img(2, 3);

        ASSERT_EQ(img.width(), 2);
        ASSERT_EQ(img.height(), 3);        

        for (int i = 0; i < img.height(); ++i) {
            for (int j = 0; j < img.width(); ++j) {
                ASSERT_EQ(img.getPixel(i, j), 0);
            }
        }
    }
}