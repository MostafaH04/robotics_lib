#include <gtest/gtest.h>

// Simple dummy function for now
int Add(int a, int b) {
    return a + b;
}

TEST(MathTest, Addition) {
    EXPECT_EQ(Add(2, 3), 5);
    EXPECT_NE(Add(2, 2), 5);  // check inequality
}
