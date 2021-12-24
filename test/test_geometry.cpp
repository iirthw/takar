#include "gtest/gtest.h"

#include "geometry/rect.h"
#include "mq.h"

using namespace mq;
using namespace tkr;

namespace tkr {
    namespace test {

        class TestGeometry : public ::testing::Test {
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
        }; // TestGeometry

    } // namespace test
} // namespace tkr

TEST(TestRect, TestCtor)
{
    {
        Rect rect;

        ASSERT_TRUE(rect.degenerate());
        ASSERT_TRUE(isZero(rect.area()));
        ASSERT_TRUE(isZero(rect.x()));
        ASSERT_TRUE(isZero(rect.y()));
        ASSERT_TRUE(isZero(rect.width()));
        ASSERT_TRUE(isZero(rect.height()));
    }

    {
        Rect rect(0.f, 0.f, 10.f, 2.f);

        ASSERT_FALSE(rect.degenerate());
        ASSERT_EQ(rect.area(), 20.f);
    }
}