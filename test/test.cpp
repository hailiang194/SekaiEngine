#include <gtest/gtest.h>
#include <api/Color.hpp>

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