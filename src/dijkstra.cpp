#include "dijkstra.h"

const int INF = 1000000000;

int deikstra(vector< vector< pair<int, int> > > g, int start, int end) {
  vector<int> dist(g.size(), INF);
  dist[start] = 0;
  set< pair<int, int> > s;
  s.insert(make_pair(dist[start], start));

  while (!s.empty()) {
    int v = s.begin()->second;
    if (v == end) {
      return s.begin()->first;
    }
    s.erase(s.begin());

    for (int i = 0; i < g[v].size(); ++i) {
      int to = g[v][i].second;
      if (to < 0) break;
      int len = g[v][i].first;

      if (dist[v] + len < dist[to]) {
        s.erase(make_pair(dist[to], to));
        dist[to] = dist[v] + len;
        s.insert(make_pair(dist[to], to));
      }
    }
  }
  return 0;
}
