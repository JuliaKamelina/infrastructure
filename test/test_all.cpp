#include <gtest/gtest.h>
#include "Algs.h"
#include "Heap.h"
#include "DSet.h"

TEST(Prim, canFindCore) {
  vector<vector<int> > g = {{0, 1, 0, 0},
                            {1, 0, 1, 2},
                            {0, 1, 0, 3},
                            {0, 2, 3, 0}};

  vector<Node> o = Prim(g);

  EXPECT_EQ(o[0].dist, 1);
  EXPECT_EQ(o[0].first, 0);
  EXPECT_EQ(o[0].second, 1);
  EXPECT_EQ(o[1].dist, 1);
  EXPECT_EQ(o[1].first, 1);
  EXPECT_EQ(o[1].second, 2);
  EXPECT_EQ(o[2].dist, 2);
  EXPECT_EQ(o[2].first, 1);
  EXPECT_EQ(o[2].second, 3);
}

TEST(Prim, oneVErtex) {
  vector<vector<int> > g = { {0, 0}};
  vector<Node> o = Prim(g);

  EXPECT_EQ(o.size(), 0);
}

TEST(Prim, twoVertexes) {
  vector<vector<int> > g = { {0, 2},
                             {2, 0} };
  vector<Node> o = Prim(g);

  EXPECT_EQ(o[0].dist, 2);
  EXPECT_EQ(o[0].first, 0);
  EXPECT_EQ(o[0].second, 1);
}

TEST(Prim, canFindCore2) {
  vector<vector<int> > g = { {0, 2, 4, 0, 5},
                             {2, 0, 7, 5, 0},
                             {4, 7, 0, 1, 3},
                             {0, 5, 1, 0, 3},
                             {5, 0, 3, 3, 0} };

  vector<Node> o = Prim(g);

  EXPECT_EQ(o[0].dist, 2);
  EXPECT_EQ(o[0].first, 0);
  EXPECT_EQ(o[0].second, 1);
  EXPECT_EQ(o[1].dist, 4);
  EXPECT_EQ(o[1].first, 0);
  EXPECT_EQ(o[1].second, 2);
  EXPECT_EQ(o[2].dist, 1);
  EXPECT_EQ(o[2].first, 2);
  EXPECT_EQ(o[2].second, 3);
  EXPECT_EQ(o[3].dist, 3);
  EXPECT_EQ(o[3].first, 2);
  EXPECT_EQ(o[3].second, 4);
}


TEST(Kruskal, canFindCore) {
  vector<vector<int> > g = { { 1, 1},
                             {1, 0, 1, 2, 2, 3},
                             {1, 1, 3, 3},
                             {2, 1, 3, 2} };

  vector<Node> o = Kruskal(g);

  EXPECT_EQ(o[0].dist, 1);
  EXPECT_EQ(o[0].first, 0);
  EXPECT_EQ(o[0].second, 1);
  EXPECT_EQ(o[1].dist, 1);
  EXPECT_EQ(o[1].first, 1);
  EXPECT_EQ(o[1].second, 2);
  EXPECT_EQ(o[2].dist, 2);
  EXPECT_EQ(o[2].first, 1);
  EXPECT_EQ(o[2].second, 3);
}

TEST(Kruskal, oneVErtex) {
  vector<vector<int> > g = { {-1, -1 } };
  vector<Node> o = Kruskal(g);

  EXPECT_EQ(o.size(), 0);
}

TEST(Kruskal, twoVertexes) {
  vector<vector<int> > g = { { 2, 1},
                      {2, 0} };
  vector<Node> o = Kruskal(g);

  EXPECT_EQ(o[0].dist, 2);
  EXPECT_EQ(o[0].first, 0);
  EXPECT_EQ(o[0].second, 1);
}

TEST(Kruskal, canFindCore2) {
  vector<vector<int> > g = { {2, 1, 4, 2, 5, 4},
                             {2, 0, 7, 2, 5, 3},
                             {4, 0, 7, 1, 1, 3, 3, 4},
                             {5, 1, 1, 2, 3, 4},
                             {5, 0, 3, 2, 3, 3}};

  vector<Node> o = Kruskal(g);

  EXPECT_EQ(o[1].dist, 2);
  EXPECT_EQ(o[1].first, 0);
  EXPECT_EQ(o[1].second, 1);
  EXPECT_EQ(o[3].dist, 4);
  EXPECT_EQ(o[3].first, 0);
  EXPECT_EQ(o[3].second, 2);
  EXPECT_EQ(o[0].dist, 1);
  EXPECT_EQ(o[0].first, 2);
  EXPECT_EQ(o[0].second, 3);
  EXPECT_EQ(o[2].dist, 3);
  EXPECT_EQ(o[2].first, 2);
  EXPECT_EQ(o[2].second, 4);
}
