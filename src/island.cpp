#include "island.h"
#include <queue>
#include <utility>

using std::make_pair;

void unite(int a, int b, int *count, int *parent) {
  int i = find(a, parent);
  int j = find(b, parent);

  if (count[i] > count[j]) {
    count[i]++;
    parent[j] = i;
  }
  else {
    count[j]++;
    parent[i] = j;
  }
}

int find(int a, int *parent) {
  int i = a;
  while (parent[i] != i) {
    i = parent[i];
  }
  return i;
}

void sinkSet(int **g, const int n, const int m) {
  int *count = new int[n*m];
  int *parent = new int[n*m];

  for (int i = 0; i < n*m; i++) {
    count[i] = 1;
    parent[i] = i;
  }

  for (int i = 1; i < n; i++) {
    unite(0, i, count, parent);
    unite(n*m - 1, n*m - 1 - i, count, parent);
  }

  for (int i = 1; i < m; i++) {
    unite(0, i*n, count, parent);
    unite(n - 1, n - 1 + i*n, count, parent);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if ((j + 1 < n) && (g[i][j + 1] == 1) && (g[i][j] == 1)) {
        unite(j + n*i, j + 1 + n*i, count, parent);
      }

      if ((i + 1 < m) && (g[i + 1][j] == 1) && (g[i][j] == 1)) {
        unite(j + n*i, j + n*(i + 1), count, parent);
      }
    }
  }

  for (int i = 0; i < n*m; i++) {
    int s = find(i, parent);
    if ((s != 1) /*&& (s != n*m - 2)*/) {
      g[i/n][i % n] = 0;
    }
  }
}

void sink(int **g, int n, int m) {
  std::queue<std::pair<int, int> > q;
  int **a = new int*[m];
  for (int i = 0; i < m; i++) {
    a[i] = new int[n];
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if ((i == 0) || (i == m - 1) || (j == 0) || (j == n - 1)) {
        a[i][j] = 1;
      } else {
        a[i][j] = 0;
      }
    }
  }

  q.push(make_pair(0,0));

  while (!q.empty()) {
    auto t = q.front();
    q.pop();

    if (t.second + 1 < n) {
      q.push(make_pair(t.first, t.second + 1));

      if ((g[t.first][t.second] == 1) && (g[t.first][t.second + 1] == 1)) {
        a[t.first][t.second + 1] = a[t.first][t.second + 1] | a[t.first][t.second];
        a[t.first][t.second] = a[t.first][t.second + 1] | a[t.first][t.second];
      }
    }

    if (t.first + 1 < m) {
      q.push(make_pair(t.first + 1, t.second));

      if ((g[t.first][t.second] == 1) && (g[t.first + 1][t.second] == 1)) {
        a[t.first + 1][t.second] |= a[t.first][t.second];
        a[t.first][t.second] |= a[t.first + 1][t.second];
      }
    }
  }

  q.push(make_pair(m - 1, n - 1));

  while (!q.empty()) {
    auto t = q.front();
    q.pop();

    if (t.first - 1 >= 0) {
      q.push(make_pair(t.first - 1, t.second));

      if ((g[t.first][t.second] == 1) && (g[t.first - 1][t.second] == 1)) {
        a[t.first - 1][t.second] |= a[t.first][t.second];
        a[t.first][t.second] |= a[t.first - 1][t.second];
      }
    }

    if (t.second - 1 >= 0) {
      q.push(make_pair(t.first, t.second - 1));

      if ((g[t.first][t.second] == 1) && (g[t.first][t.second - 1] == 1)) {
        a[t.first][t.second - 1] |= a[t.first][t.second];
        a[t.first][t.second] |= a[t.first][t.second - 1];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      g[i][j] &= a[i][j];
    }
  }
}
