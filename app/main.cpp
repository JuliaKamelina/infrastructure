#include "Algs.h"
#include <stdio.h>

using std::string;

int main() {
  int k;
  do {
    printf("Choose algorithm (1 - Prim, 2 - Kruskal, 3 - Exit)\n");
    scanf("%d", &k);

    if (k != 3) {
      printf("Enter path to file\n");
      char path[150];
      scanf("%s", path);
      FILE* f = fopen(path, "r");

      if (f == 0) {
        printf("FILE NOT FOUND\n");
        break;
      }

      vector<vector<int> > g;
      vector<int> v;
      char ch = fgetc(f);

      while (ch != EOF) {
        if (ch != ' ') {
          if (ch == '\n') {
            g.push_back(v);
            v.resize(0);
          } else {
            v.push_back(ch - '0');
          }
        }
        ch = fgetc(f);
      }
      g.push_back(v);
      fclose(f);

      vector<Node> res;
      switch (k) {
        case 1:
          res = Prim(g);
          break;
        case 2:
          res = Kruskal(g);
          break;
      }

      for (int i = 0; i < static_cast<int>(res.size()); i++) {
        printf("distance %d first %d second %d\n", res[i].dist, res[i].first, res[i].second);
      }
    }
  } while (k != 3);

  printf("All images have been saved to your current directory\n");
}
