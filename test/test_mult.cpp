#include <gtest/gtest.h>
#include "mult.h"

TEST(Mult, canMult) {
  int a[5] = {1, 2, 3, 4, 2};
  int res[5] = {48, 24, 16, 12, 24};

  int* out = mult(a, 5);

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(res[i], out[i]);
  }
}

TEST(Mult, canMultTwoNumbers) {
  int a[2] = {2, 4};
  int res[2] = {4, 2};

  int* out = mult(a, 2);

  for (int i = 0; i < 2; i++) {
    EXPECT_EQ(res[i], out[i]);
  }
}

TEST(Mult, 0pointer) {
  int* a = 0;

  EXPECT_EQ(mult(a, 0), nullptr);
}

TEST(Mult, oneElement) {
  int a[1] = {6};

  EXPECT_EQ(mult(a, 1), nullptr);
}
