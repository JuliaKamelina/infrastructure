#include <gtest/gtest.h>
#include "join.h"
#include <iostream>

using std::make_pair;

TEST(Join, canJoin) {
  vector<int> q = {0, 1, 2, 3, 4, 5, 6, 7};
  vector<pair<int, int> > p = {make_pair(1, 2), make_pair(2, 4), 
     make_pair(5, 6), make_pair(6, 2), make_pair(1, 4)};

  int *par = join(p, q);
  int res[8] = {0, 0, 2, 0, 4, 0, 4, 0};

  for (int i = 0; i < 8; i++) {
    EXPECT_EQ(par[i], res[i]);
  }
}

TEST(Join, canJoin2) {
  vector<int> q = { 0, 1, 2, 3, 4, 5};
  vector<pair<int, int> > p = {make_pair(0, 1), make_pair(1, 2), make_pair(0, 2), 
                                make_pair(0, 3), make_pair(2, 3)};

  int *par = join(p, q);
  int res[6] = {0, 3, 2, 3, 0, 0};

  for (int i = 0; i < 6; i++) {
    EXPECT_EQ(par[i], res[i]);
  }
}

TEST(Join, disjoin) {
  vector<int> q =  {0, 1, 2, 3};
  vector<pair<int, int> > p = {make_pair(0, 1), make_pair(1, 2), make_pair(2, 0),
                               make_pair(3, 2), make_pair(3, 1), make_pair(3, 0)};

  int *par = join(p, q);
  int res[4] = {0, 1, 2, 3};

  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(par[i], res[i]);
  }
}
