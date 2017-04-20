#include "PQueue.h"
using std::make_pair;

const int INF = 1000000000;

vector<int> dijkstraTree(vector< vector< pair<int, int> > > g, int start, int end) {
  if (start < 0 || end > g.size() - 1) throw std::logic_error("wrong imput");

  PQueueTree<pair<int, int> > q;
  vector<bool> visited(g.size(), false);
  vector<int> dist(g.size(), INF);
  dist[start] = 0;
  q.push(make_pair(0, start));

  while (!q.empty()) {
    pair<int, int> v = q.min();
    q.deleteMin();

    if (visited[v.second] == true) continue;

    int n = g[v.second].size();
    for (int i = 0; i < n; i++) {
      pair<int, int> to = g[v.second][i];
      if (to.second < 0) break;

      if (v.first + to.first < dist[to.second]) {
        dist[to.second] = v.first + to.first;
        q.push(make_pair(dist[to.second], to.second));
      }
    }
    visited[v.second] = true;
  }
  return dist;
}

vector<int> dijkstraHeap(vector< vector< pair<int, int> > > g, int start, int end) {
  if (start < 0 || end > g.size() - 1) throw std::logic_error("wrong imput");

  PQueueHeap<pair<int, int> > q;
  vector<bool> visited(g.size(), false);
  vector<int> dist(g.size(), INF);
  dist[start] = 0;
  q.push(make_pair(0, start));

  while (!q.empty()) {
    pair<int, int> v = q.min();
    q.deleteMin();

    if (visited[v.second] == true) continue;

    int n = g[v.second].size();
    for (int i = 0; i < n; i++) {
      pair<int, int> to = g[v.second][i];
      if (to.second < 0) break;

      if (v.first + to.first < dist[to.second]) {
        dist[to.second] = v.first + to.first;
        q.push(make_pair(dist[to.second], to.second));
      }
    }
    visited[v.second] = true;
  }
  return dist;
}
