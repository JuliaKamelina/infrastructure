#include "PQueue.h"

const int INF = 1000000000;

int dijkstraTree(vector< vector< pair<int, int> > > g, int start, int end) {
  PQueueTree q;

  for (int i = 0; i < g.size(); i++) {
    if (i == start) {
      q.push(make_pair(0, i));
    } else {
      q.push(make_pair(INF, i));
    }
  }

  while (!q.empty()) {
    pair<int, int> v = q.min();

    if (v.second == end) {
      return v.first;
    }

    int n = g[v.second].size();
    for (int i = 0; i < n; i++) {
      pair<int, int> to = g[v.second][i];
      if (to.second < 0) return 0;

      if (v.first + to.first < q.getCurVal(to.second)) {
        q.update(to.second, v.first + to.first);
      }
    }
    q.deleteMin(v);
  }
  return 0;
}

int dijkstraHeap(vector< vector< pair<int, int> > > g, int start, int end) {
  PQueueHeap q;

  for (int i = 0; i < g.size(); i++) {
    if (i == start) {
      q.push(make_pair(0, i));
    } else {
      q.push(make_pair(INF, i));
    }
  }

  while (!q.empty()) {
    pair<int, int> v = q.min();

    if (v.second == end) {
      return v.first;
    }

    int n = g[v.second].size();
    for (int i = 0; i < n; i++) {
      pair<int, int> to = g[v.second][i];
      if (to.second < 0) return 0;

      if (v.first + to.first < q.getCurVal(to.second)) {
        q.update(to.second, v.first + to.first);
      }
    }
    q.deleteMin(v);
  }
  return 0;
}
