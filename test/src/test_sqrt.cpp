#include <gtest/gtest.h>
#include <sqrt/sqrt.h>
#include<math.h>

TEST(SqrtTest1, caluclateSqrt)
{
    auto result = CalculateSqrt(125348, 1);
    EXPECT_TRUE(fabs(result-404.457) < 0.001) << result;
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}