#include <gtest/gtest.h>
#include <iostream>
#include "island.h"

TEST(sinkSet, CanDrownOneIsland) {
  int n = 5, m = 5;

  int **g = new int*[m];
  for (int i = 0; i < m; i++)
    g[i] = new int[n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = 0;
    }
  }

  g[0][3] = 1;
  g[2][1] = 1;
  g[2][2] = 1;
  g[2][3] = 1;
  g[4][1] = 1;
  /*{ { 0, 0, 0, 1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 1, 1, 1, 0 },
      { 0, 1, 0, 0, 0 },
      { 0, 1, 0, 1, 0 } };
*/
  sinkSet(g, 5, 5);
  EXPECT_EQ(g[2][1], 0);
  EXPECT_EQ(g[2][2], 0);
  EXPECT_EQ(g[2][3], 0);
}

TEST(sinkSet, NothingToDronw) {
  int n = 5, m = 5;

  int **g = new int*[m];
  for (int i = 0; i < m; i++)
    g[i] = new int[n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = 0;
    }
  }

  g[0][1] = 1;
  g[1][0] = 1;
  g[1][1] = 1;
  g[4][2] = 1;
  g[4][3] = 1;
  g[3][4] = 1;
  g[3][3] = 1;

  sinkSet(g, n, m);
  EXPECT_EQ(g[0][1], 1);
  EXPECT_EQ(g[1][0], 1);
  EXPECT_EQ(g[1][1], 1);
  EXPECT_EQ(g[4][2], 1);
  EXPECT_EQ(g[4][3], 1);
  EXPECT_EQ(g[3][4], 1);
  EXPECT_EQ(g[3][3], 1);
}

TEST(sinkSet, CanDrownAll) {
  int n = 5, m = 6;

  int **g = new int*[m];
  for (int i = 0; i < m; i++)
    g[i] = new int[n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = 0;
    }
  }

  g[1][1] = 1;
  g[2][2] = 1;
  g[2][3] = 1;
  g[3][3] = 1;
  g[4][1] = 1;

  sinkSet(g, n, m);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      EXPECT_EQ(g[i][j], 0);
    }
  }
}


TEST(sink, CanDownOneIsland) {
  int n = 5, m = 5;

  int **g = new int*[m];
  for (int i = 0; i < m; i++)
    g[i] = new int[n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = 0;
    }
  }

  g[0][3] = 1;
  g[2][1] = 1;
  g[2][2] = 1;
  g[2][3] = 1;
  g[4][1] = 1;
  /*{ { 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0 },
  { 0, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 0 },
  { 0, 1, 0, 1, 0 } };
  */
  sink(g, 5, 5);
  EXPECT_EQ(g[2][1], 0);
  EXPECT_EQ(g[2][2], 0);
  EXPECT_EQ(g[2][3], 0);
}

TEST(sink, NothingToDronw) {
  int n = 5, m = 5;

  int **g = new int*[m];
  for (int i = 0; i < m; i++)
    g[i] = new int[n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = 0;
    }
  }

  g[0][1] = 1;
  g[1][0] = 1;
  g[1][1] = 1;
  g[4][2] = 1;
  g[4][3] = 1;
  g[3][4] = 1;
  g[3][3] = 1;

  sink(g, n, m);
  EXPECT_EQ(g[0][1], 1);
  EXPECT_EQ(g[1][0], 1);
  EXPECT_EQ(g[1][1], 1);
  EXPECT_EQ(g[4][2], 1);
  EXPECT_EQ(g[4][3], 1);
  EXPECT_EQ(g[3][4], 1);
  EXPECT_EQ(g[3][3], 1);
}

TEST(sink, CanDrownAll) {
  int n = 5, m = 6;

  int **g = new int*[m];
  for (int i = 0; i < m; i++)
    g[i] = new int[n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = 0;
    }
  }

  g[1][1] = 1;
  g[2][2] = 1;
  g[2][3] = 1;
  g[3][3] = 1;
  g[4][1] = 1;

  sink(g, n, m);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      EXPECT_EQ(g[i][j], 0);
    }
  }
}

TEST(sink_sinkSet, ReturnSame) {
  int n = 10, m = 10;

  int **g = new int*[m];
  int **g1 = new int*[m];
  for (int i = 0; i < m; i++){
    g[i] = new int[n];
    g1[i] = new int[n];
  }

  srand(time(0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = rand() % 2;
      g1[i][j] = g[i][j];
    }
  }

  sink(g, n, m);
  sinkSet(g1, n, m);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      EXPECT_EQ(g[i][j], g1[i][j]);
    }
  }
}
