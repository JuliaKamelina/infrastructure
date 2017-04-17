#include "prcl.h"
#include <cstdlib>

int count[N*N + 2];
int parent[N*N + 2];

void unite(int a, int b) {
  int i = find(a);
  int j = find(b);

  if (count[i] > count[j]) {
    count[i]++;
    parent[j] = i;
  } else {
    count[j]++;
    parent[i] = j;
  }
}

int find(int a) {
  int i = a;
  while (parent[i] != i) {
    i = parent[i];
  }
  return i;
}

bool percolation(int** g) {
  int start = 0;
  int end = N*N + 1;

  for (int i = 0; i < N*N+ 2; i++) {
    count[i] = 1;
    parent[i] = i;
  }

  for (int i = 0; i < N; i++) {
    unite(start, i + 1);
    unite(end, N*N - i);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {

      if ((j + 1 < N) && (g[i][j + 1] == 1) && (g[i][j] == 1)) {
        unite(j + 1 + N*i, j + 2 + N*i);
      }

      if ((i + 1 < N) && (g[i + 1][j] == 1) && (g[i][j] == 1)) {
        unite(j + 1 + N*i, j + 1 + N*(i + 1));
      }
    }
  }

  if (find(start) == find(end)) return true;
  return false;
}

double minThrows(int** g) {
  double res = 0;
  int k = 1000;
  int tmp;

  for (int i = 0; i < k; i++) {
    bool f = percolation(g);
    int x = 0;

    for (int j = 0; j < k; j++) {

      while (f == false) {
        int p = rand() % N;
        int q = rand() % N;

        if (g[p][q] != 1) {
          g[p][q] = 1;
          x++;
        }
        f = percolation(g);
      }

      for (int p = 0; p < N; p++) {
        for (int q = 0; q < N; q++) {
          g[p][q] = 0;
        }
      }

    }

    res += x/(N*N) + (x % (N*N))*1e-6;
  }

  tmp = (int)res*1e+6;
  res = res/k + ((tmp % 1000000)%k)*1e-5;

  return res;
}
