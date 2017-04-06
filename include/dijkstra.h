#ifndef INCLUDE_DIJKSTRA_H_
#define INCLUDE_DIJKSTRA_H_

#include <vector>
#include <set>
#include <utility>

using std::set;
using std::pair;
using std::vector;
using std::make_pair;

struct CNode {
  int value;
  int lenght;
  CNode* left;
  CNode* right;

  CNode(int v, int l) {
    value = v;
    lenght = l;
    left = 0;
    right = 0;
  }
};

int deikstra(vector< vector< pair<int, int> > > g, int start, int end);

#endif  // INCLUDE_DIJKSTRA_H_
