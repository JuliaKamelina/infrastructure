#include "join.h"

void unite(int a, int b, int *count, int *parent) {
  int j = find(a, parent);
  int i = find(b, parent);

  if (count[i] > count[j]) {
    count[i]++;
    parent[j] = i;
  } else {
    count[j]++;
    parent[i] = j;
  }
}

int disjoin(int a, int b, int* count, int* parent) {
  int j = find(a, parent);
  count[j]--;

  if (a == j) {
    parent[b] = b;
    return b;
  } else {
    parent[a] = a;
    return a;
  }
}

int find(int a, int *parent) {
  int i = a;
  while (parent[i] != i) {
    i = parent[i];
  }
  return i;
}

int* join(vector<pair<int, int> > p, vector<int> q) {
  int n = static_cast<int>(q.size());
  int *count = new int[n];
  int *parent = new int[n];

  for (int i = 0; i < n; i++) {
    parent[i] = i;
    count[i] = 1;
  }

  for (int i = 1; i < n; i++) {
    unite(q[0], q[i], count, parent);
  }

  vector<int> sep;
  int size = static_cast<int>(p.size());

  for (int i = 0; i < size; i++) {
    int par1 = find(p[i].first, parent);
    int par2 = find(p[i].second, parent);

    if (par1 == par2) {
      int a = disjoin(p[i].second, p[i].first, count, parent);

      int j = 0;
      bool f = false;
      int s = static_cast<int>(sep.size());

      while (j < s && f == false) {
        f = true;
        for (int k = 0; k < size; k++) {
          int par3 = find(sep[j], parent);

          if (a == p[k].first && par3 == find(p[k].second, parent) ||
               a == p[k].second && par3 == find(p[k].first, parent)) {
            f = false;
            break;
          }
        }

        if (f == true) {
          unite(p[i].second, sep[j], count, parent);
        }
        j++;
      }

      f = true;
      for (int k = 0; k < s; k++) {
        if (sep[k] == p[i].second) {
          break;
          f = false;
        }
      }

      if (f) sep.push_back(p[i].second);
    }
  }

  return parent;
}
