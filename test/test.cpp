#include <gtest/gtest.h>
#include <core/Container.hpp>
#include <core/Scence.hpp>
#include <api/Color.hpp>
#include <api/Vector.hpp>
#include <api/Shape.hpp>

//Scence

TEST(EngineTest, TestInsertToFrontScence)
{
  SekaiEngine::Core::Scence scence;
  SekaiEngine::Core::Container container;
  scence.addObject(&container, SekaiEngine::Core::SCENCE_LAYER::FRONT_CAMERA);
  EXPECT_TRUE(scence.getLayer(SekaiEngine::Core::SCENCE_LAYER::FRONT_CAMERA).objects().size() == 1);
}

// COLOR API
TEST(EngineTest, TestRaylibColorEqualToCode)
{
  SekaiEngine::API::Color a(GREEN);
  EXPECT_TRUE(a == (SekaiEngine::API::Color)0x00e430ff);
}

TEST(EngineTest, TestRaylibColorEqualToRaylibColor)
{
  SekaiEngine::API::Color a(GREEN);
  bool result = (a == (SekaiEngine::API::Color)GREEN);
  EXPECT_TRUE(result);
}

TEST(EngineTest, TestCodeEqualToCode)
{
  SekaiEngine::API::Color a(0x00e430ff);
  EXPECT_TRUE(a == (SekaiEngine::API::Color)0x00e430ff);
}

TEST(EngineTest, TestCodeEqualToRaylibColor)
{
  SekaiEngine::API::Color a(0x00e430ff);
  bool result = (a == (SekaiEngine::API::Color)GREEN); 
  EXPECT_TRUE(result);
}

TEST(EngineTest, TestCodeWithRed)
{
  SekaiEngine::API::Color a(0x00e430ff);
  COLOR_API b = GREEN;
  EXPECT_TRUE(a.r() == b.r);
}

TEST(EngineTest, TestCodeWithGreen)
{
  SekaiEngine::API::Color a(0x00e430ff);
  COLOR_API b = GREEN;
  EXPECT_TRUE(a.g() == b.g);
}

TEST(EngineTest, TestCodeWithBlue)
{
  SekaiEngine::API::Color a(0x00e430ff);
  COLOR_API b = GREEN;
  EXPECT_TRUE(a.b() == b.b);
}

TEST(EngineTest, TestCodeWithAlpha)
{
  SekaiEngine::API::Color a(0x00e430ff);
  COLOR_API b = GREEN;
  EXPECT_TRUE(a.a() == b.a);
}

// VECTOR 2D API

TEST(EngineTest, TestVectorAndRaylibVector)
{
  SekaiEngine::API::Vector2D vector(0.3f, 0.7f);
  VECTOR2_API raylibVector = {0.3f, 0.7f};
  EXPECT_TRUE(vector == (SekaiEngine::API::Vector2D)raylibVector);
}

TEST(EngineTest, TestVectorAddAndRaylibVector)
{
  SekaiEngine::API::Vector2D vector(0.1f, 0.3f);
  SekaiEngine::API::Vector2D vector2(0.2f, 0.4f);
  SekaiEngine::API::Vector2D sumVector = vector + vector2;
  VECTOR2_API raylibVector = {0.3f, 0.7f};
  EXPECT_TRUE(sumVector == (SekaiEngine::API::Vector2D)raylibVector);
}

TEST(EngineTest, TestVectorMinusAndRaylibVector)
{
  SekaiEngine::API::Vector2D vector(0.1f, 0.3f);
  SekaiEngine::API::Vector2D vector2(0.2f, 0.4f);
  SekaiEngine::API::Vector2D sumVector = vector2 - vector;
  VECTOR2_API raylibVector = {0.1f, 0.1f};
  EXPECT_TRUE(sumVector == (SekaiEngine::API::Vector2D)raylibVector);
}

TEST(EngineTest, TestVectorProductAndRaylibVector)
{
  SekaiEngine::API::Vector2D vector(0.1f, 0.3f);
  SekaiEngine::API::Vector2D sumVector = vector * 3;
  VECTOR2_API raylibVector = {0.3f, 0.9f};
  EXPECT_TRUE(sumVector == (SekaiEngine::API::Vector2D)raylibVector);
}

// Shape intersect

TEST(EngineTest, TestPointInterect)
{
  SekaiEngine::API::Point p({10.0f, 10.0f});
  SekaiEngine::API::Point q({10.0f, 10.0f});
  EXPECT_TRUE(p.intersect(q));
}

TEST(EngineTest, TestPointNotInterect)
{
  SekaiEngine::API::Point p({10.0f, 10.0f});
  SekaiEngine::API::Point q({11.0f, 10.0f});
  EXPECT_FALSE(p.intersect(q));
}

TEST(EngineTest, TestLineAndPointInterect)
{
  SekaiEngine::API::Line l({1.0f, 1.0f}, {3.0f, 3.0f});
  SekaiEngine::API::Point p({2.0f, 2.0f});
  EXPECT_TRUE(l.intersect(p));
}

TEST(EngineTest, TestPointAndLineInterect)
{
  SekaiEngine::API::Line l({1.0f, 1.0f}, {3.0f, 3.0f});
  SekaiEngine::API::Point p({2.0f, 2.0f});
  EXPECT_TRUE(p.intersect(l));
}

TEST(EngineTest, TestPointAndLineCodirectionalButNotInterect)
{
  SekaiEngine::API::Line l({1.0f, 1.0f}, {3.0f, 3.0f});
  SekaiEngine::API::Point p({0.0f, 0.0f});
  EXPECT_FALSE(p.intersect(l));
}

TEST(EngineTest, TestLineAndPointCodirectionalButNotInterect)
{
  SekaiEngine::API::Line l({1.0f, 1.0f}, {3.0f, 3.0f});
  SekaiEngine::API::Point p({0.0f, 0.0f});
  EXPECT_FALSE(l.intersect(p));
}

TEST(EngineTest, TestCircleBorderAndPointInterect)
{
  SekaiEngine::API::Circle c({2.0f, -1.0f}, 3.0f);
  SekaiEngine::API::Point p({2.0f, 2.0f});
  EXPECT_TRUE(c.intersect(p));
}

TEST(EngineTest, TestPointAndCircleBorderInterect)
{
  SekaiEngine::API::Circle c({2.0f, -1.0f}, 3.0f);
  SekaiEngine::API::Point p({2.0f, 2.0f});
  EXPECT_TRUE(p.intersect(c));
}

TEST(EngineTest, TestPointAndCircleInsideInterect)
{
  SekaiEngine::API::Circle c({2.0f, -1.0f}, 3.0f);
  SekaiEngine::API::Point p({1.5f, 0.5f});
  EXPECT_TRUE(p.intersect(c));
}

TEST(EngineTest, TestPointAndCircleNotInterect)
{
  SekaiEngine::API::Circle c({2.0f, -1.0f}, 3.0f);
  SekaiEngine::API::Point p({5.0f, 3.0f});
  EXPECT_FALSE(p.intersect(c));
}

TEST(EngineTest, TestRectAndPointInterect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Point p({4.0f, 4.0f});
  EXPECT_TRUE(r.intersect(p));
}

TEST(EngineTest, TestPointAndRectInterect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Point p({4.0f, 4.0f});
  EXPECT_TRUE(p.intersect(r));
}

TEST(EngineTest, TestRectAndPointNotIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Point p({9.0f, 6.0f});
  EXPECT_FALSE(p.intersect(r));
}

TEST(EngineTest, TestRectAndRectIntersect)
{
  SekaiEngine::API::Rectangle r1({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Rectangle r2({4.0f, 4.0f}, 7.0f, 2.0f);
  EXPECT_TRUE(r1.intersect(r2));
}

TEST(EngineTest, TestRectAndRectNotIntersect)
{
  SekaiEngine::API::Rectangle r1({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Rectangle r2({9.0f, 6.0f}, 7.0f, 2.0f);
  EXPECT_FALSE(r1.intersect(r2));
}

TEST(EngineTest, TestRectAndCircleTopLeftIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({1.0f, 1.0f}, 3.0f);
  EXPECT_TRUE(r.intersect(c));
}

TEST(EngineTest, TestCircleAndRectTopLeftIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({1.0f, 1.0f}, 3.0f);
  EXPECT_TRUE(c.intersect(r));
}

TEST(EngineTest, TestRectAndCircleTopLeftNotIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({-5.0f, -5.0f}, 3.0f);
  EXPECT_FALSE(r.intersect(c));
}

TEST(EngineTest, TestCircleAndRectTopRightIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({8.0f, 1.0f}, 3.0f);
  EXPECT_TRUE(c.intersect(r));
}

TEST(EngineTest, TestRectAndCircleTopRightNotIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({10.0f, -5.0f}, 3.0f);
  EXPECT_FALSE(r.intersect(c));
}

TEST(EngineTest, TestCircleAndRectMiddleLeftIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({1.0f, 4.0f}, 3.0f);
  EXPECT_TRUE(c.intersect(r));
}

TEST(EngineTest, TestRectAndCircleMiddleLeftNotIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({-5.0f, 4.0f}, 3.0f);
  EXPECT_FALSE(r.intersect(c));
}

TEST(EngineTest, TestCircleAndRectMiddleRightIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({8.0f, 4.0f}, 3.0f);
  EXPECT_TRUE(c.intersect(r));
}

TEST(EngineTest, TestRectAndCircleMiddleRightNotIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({11.0f, 4.0f}, 3.0f);
  EXPECT_FALSE(r.intersect(c));
}

TEST(EngineTest, TestCircleAndRectBottomLeftIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({1.0f, 6.0f}, 3.0f);
  EXPECT_TRUE(c.intersect(r));
}

TEST(EngineTest, TestRectAndCircleBottomLeftNotIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({-5.0f, 6.0f}, 3.0f);
  EXPECT_FALSE(r.intersect(c));
}

TEST(EngineTest, TestCircleAndRectBottomRightIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({8.0f, 6.0f}, 3.0f);
  EXPECT_TRUE(c.intersect(r));
}

TEST(EngineTest, TestRectAndCircleBottomRightNotIntersect)
{
  SekaiEngine::API::Rectangle r({2.0f, 2.0f}, 5.0f, 3.0f);
  SekaiEngine::API::Circle c({10.0f, 6.0f}, 3.0f);
  EXPECT_FALSE(r.intersect(c));
}
