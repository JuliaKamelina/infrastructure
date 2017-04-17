#include "prcl.h"
#include <iostream>

int main() {
  int** g = new int*[N];

  for (int i = 0; i < N; i++) {
    g[i] = new int[N];
    for (int j = 0; j < N; j++) {
      g[i][j] = 0;
    }
  }

  std::cout << minThrows(g);
}
