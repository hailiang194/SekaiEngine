#include <gtest/gtest.h>
#include <api/Color.hpp>
#include <api/Vector2D.hpp>

//COLOR API
TEST(EngineTest, TestRaylibColorEqualToCode) {
  SekaiEngine::API::Color a(GREEN);
  EXPECT_TRUE(a == (SekaiEngine::API::Color)0x00e430ff);
}

TEST(EngineTest, TestRaylibColorEqualToRaylibColor) {
  SekaiEngine::API::Color a(GREEN);
  EXPECT_TRUE(a == (SekaiEngine::API::Color)GREEN);
}

TEST(EngineTest, TestCodeEqualToCode) {
  SekaiEngine::API::Color a(0x00e430ff);
  EXPECT_TRUE(a == (SekaiEngine::API::Color)0x00e430ff);
}

TEST(EngineTest, TestCodeEqualToRaylibColor) {
  SekaiEngine::API::Color a(0x00e430ff);
  EXPECT_TRUE(a == (SekaiEngine::API::Color)GREEN);
}

TEST(EngineTest, TestCodeWithRed) {
    SekaiEngine::API::Color a(0x00e430ff);
    ::Color b = GREEN;
    EXPECT_TRUE(a.r() == b.r);
}

TEST(EngineTest, TestCodeWithGreen) {
    SekaiEngine::API::Color a(0x00e430ff);
    ::Color b = GREEN;
    EXPECT_TRUE(a.g() == b.g);
}

TEST(EngineTest, TestCodeWithBlue) {
    SekaiEngine::API::Color a(0x00e430ff);
    ::Color b = GREEN;
    EXPECT_TRUE(a.b() == b.b);
}

TEST(EngineTest, TestCodeWithAlpha) {
    SekaiEngine::API::Color a(0x00e430ff);
    ::Color b = GREEN;
    EXPECT_TRUE(a.a() == b.a);
}

//VECTOR 2D API

TEST(EngineTest, TestVectorAndRaylibVector) {
  SekaiEngine::API::Vector2D vector(0.3f, 0.7f);
  ::Vector2 raylibVector = {0.3f, 0.7f};
  EXPECT_TRUE(vector == (SekaiEngine::API::Vector2D)raylibVector);
}

TEST(EngineTest, TestVectorAddAndRaylibVector) {
  SekaiEngine::API::Vector2D vector(0.1f, 0.3f);
  SekaiEngine::API::Vector2D vector2(0.2f, 0.4f);
  SekaiEngine::API::Vector2D sumVector = vector + vector2;
  ::Vector2 raylibVector = {0.3f, 0.7f};
  EXPECT_TRUE(sumVector == (SekaiEngine::API::Vector2D)raylibVector);
}

TEST(EngineTest, TestVectorProductAndRaylibVector) {
  SekaiEngine::API::Vector2D vector(0.1f, 0.3f);
  SekaiEngine::API::Vector2D sumVector = vector * 3;
  ::Vector2 raylibVector = {0.3f, 0.9f};
  EXPECT_TRUE(sumVector == (SekaiEngine::API::Vector2D)raylibVector);
}