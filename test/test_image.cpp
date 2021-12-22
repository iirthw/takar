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

TEST(TesImage, TestCtorDtor)
{
    // Sanity check  for ctor and dtor.
    // Since the Image use custom deleter, dtor might crash if deleter is 
    // implemented incorrectly.
    tkr::Image img(2, 2);
}

TEST(TesImage, TestCtor)
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

TEST(TesImage, TestSetPixel)
{
    {
        tkr::Image img(1, 1);

        ASSERT_EQ(img.getPixel(0, 0), 0);

        img.setPixel(0, 0, 255);
        ASSERT_EQ(img.getPixel(0, 0), 255);
    }

    {
        constexpr int size = 16;
        tkr::Image img(size, size);

        unsigned char value = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                img.setPixel(i, j, value++);
            }
        }

        for (int i = size - 1; i >= 0; --i) {
            for (int j = size - 1; j >= 0; --j) {
                ASSERT_EQ(img.getPixel(i, j), --value);
            }
        }
    }
}