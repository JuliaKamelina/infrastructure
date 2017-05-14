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
  vector<Node> res = {Node(1, 0, 1), Node(1, 1, 2), Node(2, 1, 3) };

  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(o[i].dist, res[i].dist);
    EXPECT_EQ(o[i].first, res[i].first);
    EXPECT_EQ(o[i].second, res[i].second);
  }
}

TEST(Prim, oneVErtex) {
  vector<vector<int> > g = { {0, 0}};
  vector<Node> o = Prim(g);

  EXPECT_EQ(static_cast<int>(o.size()), 0);
}

TEST(Prim, twoVertexes) {
  vector<vector<int> > g = { {0, 2},
                             {2, 0} };
  vector<Node> o = Prim(g);
  Node res = Node(2, 0, 1);

  EXPECT_EQ(o[0].dist, res.dist);
  EXPECT_EQ(o[0].first, res.first);
  EXPECT_EQ(o[0].second, res.second);
}

TEST(Prim, canFindCore2) {
  vector<vector<int> > g = { {0, 2, 4, 0, 5},
                             {2, 0, 7, 5, 0},
                             {4, 7, 0, 1, 3},
                             {0, 5, 1, 0, 3},
                             {5, 0, 3, 3, 0} };

  vector<Node> o = Prim(g);
  vector<Node> res = {Node(2, 0, 1), Node(4, 0, 2), Node(1, 2, 3), Node(3, 2, 4)};

  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(o[i].dist, res[i].dist);
    EXPECT_EQ(o[i].first, res[i].first);
    EXPECT_EQ(o[i].second, res[i].second);
  }
}


TEST(Kruskal, canFindCore) {
  vector<vector<int> > g = { { 1, 1},
                             {1, 0, 1, 2, 2, 3},
                             {1, 1, 3, 3},
                             {2, 1, 3, 2} };

  vector<Node> o = Kruskal(g);

  vector<Node> res = { Node(1, 0, 1), Node(1, 1, 2), Node(2, 1, 3) };

  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(o[i].dist, res[i].dist);
    EXPECT_EQ(o[i].first, res[i].first);
    EXPECT_EQ(o[i].second, res[i].second);
  }
}

TEST(Kruskal, oneVErtex) {
  vector<vector<int> > g = { {-1, -1 } };
  vector<Node> o = Kruskal(g);

  EXPECT_EQ(static_cast<int>(o.size()), 0);
}

TEST(Kruskal, twoVertexes) {
  vector<vector<int> > g = { { 2, 1},
                      {2, 0} };
  vector<Node> o = Kruskal(g);
  Node res = Node(2, 0, 1);

  EXPECT_EQ(o[0].dist, res.dist);
  EXPECT_EQ(o[0].first, res.first);
  EXPECT_EQ(o[0].second, res.second);
}

TEST(Kruskal, canFindCore2) {
  vector<vector<int> > g = { {2, 1, 4, 2, 5, 4},
                             {2, 0, 7, 2, 5, 3},
                             {4, 0, 7, 1, 1, 3, 3, 4},
                             {5, 1, 1, 2, 3, 4},
                             {5, 0, 3, 2, 3, 3}};

  vector<Node> o = Kruskal(g);
  vector<Node> res = {Node(1, 2, 3), Node(2, 0, 1), Node(3, 2, 4), Node(4, 0, 2)};

  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(o[i].dist, res[i].dist);
    EXPECT_EQ(o[i].first, res[i].first);
    EXPECT_EQ(o[i].second, res[i].second);
  }
}
