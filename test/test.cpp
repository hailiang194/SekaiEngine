#include <gtest/gtest.h>
#include <api/Color.hpp>
#include <api/Vector2D.hpp>
#include <api/Shape.hpp>

// COLOR API
TEST(EngineTest, TestRaylibColorEqualToCode)
{
  SekaiEngine::API::Color a(GREEN);
  EXPECT_TRUE(a == (SekaiEngine::API::Color)0x00e430ff);
}

TEST(EngineTest, TestRaylibColorEqualToRaylibColor)
{
  SekaiEngine::API::Color a(GREEN);
  EXPECT_TRUE(a == (SekaiEngine::API::Color)GREEN);
}

TEST(EngineTest, TestCodeEqualToCode)
{
  SekaiEngine::API::Color a(0x00e430ff);
  EXPECT_TRUE(a == (SekaiEngine::API::Color)0x00e430ff);
}

TEST(EngineTest, TestCodeEqualToRaylibColor)
{
  SekaiEngine::API::Color a(0x00e430ff);
  EXPECT_TRUE(a == (SekaiEngine::API::Color)GREEN);
}

TEST(EngineTest, TestCodeWithRed)
{
  SekaiEngine::API::Color a(0x00e430ff);
  ::Color b = GREEN;
  EXPECT_TRUE(a.r() == b.r);
}

TEST(EngineTest, TestCodeWithGreen)
{
  SekaiEngine::API::Color a(0x00e430ff);
  ::Color b = GREEN;
  EXPECT_TRUE(a.g() == b.g);
}

TEST(EngineTest, TestCodeWithBlue)
{
  SekaiEngine::API::Color a(0x00e430ff);
  ::Color b = GREEN;
  EXPECT_TRUE(a.b() == b.b);
}

TEST(EngineTest, TestCodeWithAlpha)
{
  SekaiEngine::API::Color a(0x00e430ff);
  ::Color b = GREEN;
  EXPECT_TRUE(a.a() == b.a);
}

// VECTOR 2D API

TEST(EngineTest, TestVectorAndRaylibVector)
{
  SekaiEngine::API::Vector2D vector(0.3f, 0.7f);
  ::Vector2 raylibVector = {0.3f, 0.7f};
  EXPECT_TRUE(vector == (SekaiEngine::API::Vector2D)raylibVector);
}

TEST(EngineTest, TestVectorAddAndRaylibVector)
{
  SekaiEngine::API::Vector2D vector(0.1f, 0.3f);
  SekaiEngine::API::Vector2D vector2(0.2f, 0.4f);
  SekaiEngine::API::Vector2D sumVector = vector + vector2;
  ::Vector2 raylibVector = {0.3f, 0.7f};
  EXPECT_TRUE(sumVector == (SekaiEngine::API::Vector2D)raylibVector);
}

TEST(EngineTest, TestVectorMinusAndRaylibVector)
{
  SekaiEngine::API::Vector2D vector(0.1f, 0.3f);
  SekaiEngine::API::Vector2D vector2(0.2f, 0.4f);
  SekaiEngine::API::Vector2D sumVector = vector2 - vector;
  ::Vector2 raylibVector = {0.1f, 0.1f};
  EXPECT_TRUE(sumVector == (SekaiEngine::API::Vector2D)raylibVector);
}

TEST(EngineTest, TestVectorProductAndRaylibVector)
{
  SekaiEngine::API::Vector2D vector(0.1f, 0.3f);
  SekaiEngine::API::Vector2D sumVector = vector * 3;
  ::Vector2 raylibVector = {0.3f, 0.9f};
  EXPECT_TRUE(sumVector == (SekaiEngine::API::Vector2D)raylibVector);
}

//Shape intersect

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
  SekaiEngine::API::Point p({2.0f, 1.0f});
  EXPECT_TRUE(c.intersect(p));
}

TEST(EngineTest, TestPointAndCircleBorderInterect)
{
  SekaiEngine::API::Circle c({2.0f, -1.0f}, 3.0f);
  SekaiEngine::API::Point p({2.0f, 1.0f});
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