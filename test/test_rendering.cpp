#include "gtest/gtest.h"

#include <memory>

#include "rendering/camera.h"
#include "rendering/ray.h"

namespace tkr {
    namespace test {

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

    } // namespace test
} // namespace tkr

using namespace mq;
using namespace tkr;

TEST(TestCamera, TestCtor)
{ 
    auto viewport = std::make_shared<Viewport>(16.f / 9.f, 128);
    ASSERT_TRUE(viewport != nullptr);

    auto camera = std::make_shared<Camera>(viewport, vec3{ 0.f, 0.f, 0.f }, vec3{ 0.f, 0.f, -1.f });

    ASSERT_TRUE(camera != nullptr);
}

TEST(TestRay, BasicTest)
{
    {
        Ray ray(vec3(0.f, 0.f, 0.f), vec3(0.f, 0.f, -1.f));
        ASSERT_EQ(ray.direction(), vec3(0.f, 0.f, -1.f));
    }
    {
        Ray ray(vec3(1.f, 0.f, 0.f), vec3(0.f, 0.f, 1.f));
        ASSERT_EQ(ray.direction(), vec3(-1.f, 0.f, 1.f));
    }
    {
        Ray ray(vec3(10.f, 0.f, 0.f), vec3(1.f, 1.f, 1.f));
        ASSERT_EQ(ray.direction(), vec3(-9.f, 1.f, 1.f));
    }
}