#include "gtest/gtest.h"

#include <memory>

#include "rendering/camera.h"
#include "rendering/node.h"
#include "rendering/path_tracer.h"
#include "rendering/ray.h"
#include "rendering/scene.h"

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

            static std::shared_ptr<PathTracer> buildTestPathTracer();

        protected:

            void SetUp() override
            {}

            // void TearDown() override {}
        };

    } // namespace test
} // namespace tkr

using namespace mq;
using namespace tkr;
using namespace test;

std::shared_ptr<PathTracer> TestRendering::buildTestPathTracer()
{
    auto node = std::make_shared<Node>();
    auto scene = std::make_shared<Scene>(node);

    auto viewport = std::make_shared<Viewport>(16.f / 9.f, 128);
    auto camera = std::make_shared<PerspectiveCamera>(viewport, vec3(0.f, 0.f, 1.f), vec3::getZero());

    return std::make_shared<PathTracer>(scene, camera);
}

TEST(TestCamera, TestCtor)
{ 
    auto viewport = std::make_shared<Viewport>(16.f / 9.f, 128);
    ASSERT_TRUE(viewport != nullptr);

    auto camera = std::make_shared<PerspectiveCamera>(viewport, vec3{ 0.f, 0.f, 0.f }, vec3{ 0.f, 0.f, -1.f });

    ASSERT_TRUE(camera != nullptr);
}

TEST(TestRay, BasicTest)
{
    {
        Ray ray(vec3::getZero(), vec3(0.f, 0.f, -1.f));
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

TEST(TestPathTracer, TestCtor)
{
    auto pathTracer = TestRendering::buildTestPathTracer();
    ASSERT_TRUE(pathTracer != nullptr);
}

TEST(TestPathTracer, TestRendering)
{
    auto pathTracer = TestRendering::buildTestPathTracer();
    ASSERT_TRUE(pathTracer != nullptr);

    auto renderedImage = pathTracer->renderToImage();
    ASSERT_EQ(renderedImage.height(), 128);
    ASSERT_EQ(renderedImage.width(), 227);
}