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
