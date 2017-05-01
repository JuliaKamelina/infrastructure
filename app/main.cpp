#include "island.h"
#include <iostream>
#include <time.h>

int main() {
  int n = 7, m = 7;

  int **g = new int*[m];
  for (int i = 0; i < m; i++)
    g[i] = new int[n];

  srand(time(0));

  std::cout << "disjoint set" << std::endl;

  for (int i = 0; i < m; i++) {  //  на множествах
    for (int j = 0; j < n; j++) {
      g[i][j] = rand() % 2;
      std::cout << g[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  sinkSet(g, n, m);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << g[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  std::cout << "visiting round" << std::endl;

  for (int i = 0; i < m; i++) {  //  обход
    for (int j = 0; j < n; j++) {
      g[i][j] = rand() % 2;
      std::cout << g[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  sink(g, n, m);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << g[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}
