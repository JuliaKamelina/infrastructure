#include <gtest/gtest.h>
#include "dijkstra.h"

TEST(Dijkstra, canFindWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
                                           { make_pair(1, 3) },
                                           { make_pair(3, 3) },
                                           { make_pair(-1, -1) } };
  int way = deikstra(g, 0, 3);

  EXPECT_EQ(way, 5);
}

TEST(Dijkstra, canFindMinWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
                                           { make_pair(1, 3) },
                                           { make_pair(3, 3), make_pair(2, 4) },
                                           { make_pair(1, 5) },
                                           { make_pair(1, 5), make_pair(4, 6) },
                                           { make_pair(2, 6) },
                                           { make_pair(-1, -1) } };
  int way = deikstra(g, 2, 6);

  EXPECT_EQ(way, 5);
}

TEST(Dijkstra, canDetectNonExistinWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
                                         { make_pair(1, 3) },
                                         { make_pair(3, 3) },
                                         { make_pair(-1, -1) } };
  int way = deikstra(g, 2, 1);

  EXPECT_EQ(way, 0);
}
