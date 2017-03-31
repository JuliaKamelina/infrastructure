#include <gtest/gtest.h>
#include "way.h"

TEST(findWay, canFindWays) {
  int x, y;
  int cx, cy;

  for (int i = 0; i < 50; i++) {
    x = y = i;
    cx = cy = 0;
    char* res = Way(x, y);
    int j = 1;

    while (res[j - 1] != 0) {
      if (res[j - 1] == 'N') cy += j;
      if (res[j - 1] == 'S') cy -= j;
      if (res[j - 1] == 'E') cx += j;
      if (res[j - 1] == 'W') cx -= j;
      j++;
    }

    EXPECT_EQ(cx, x);
    EXPECT_EQ(cy, y);
  }
}

TEST(findWay, canFindWays2) {
  int x, y;
  int cx, cy;

  for (int i = 0; i < 50; i++) {
    x = i;
    y = 50 / 2 - x;
    cx = cy = 0;
    char* res = Way(x, y);
    int j = 1;

    while (res[j - 1] != 0) {
      if (res[j - 1] == 'N') cy += j;
      if (res[j - 1] == 'S') cy -= j;
      if (res[j - 1] == 'E') cx += j;
      if (res[j - 1] == 'W') cx -= j;
      j++;
    }

    EXPECT_EQ(cx, x);
    EXPECT_EQ(cy, y);
  }
}

TEST(findWay, canFindWays3) {
  int x, y;
  int cx, cy;

  for (int i = 0; i < 50; i++) {
    x = -i;
    y = -50/2 - x;
    cx = cy = 0;
    char* res = Way(x, y);
    int j = 1;

    while (res[j - 1] != 0) {
      if (res[j - 1] == 'N') cy += j;
      if (res[j - 1] == 'S') cy -= j;
      if (res[j - 1] == 'E') cx += j;
      if (res[j - 1] == 'W') cx -= j;
      j++;
    }

    EXPECT_EQ(cx, x);
    EXPECT_EQ(cy, y);
  }
}
