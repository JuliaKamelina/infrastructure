#include "PQueue.h"
#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ifstream;

int main() {
  vector<vector<pair<int, int> > >g;
  string str;
  ifstream file("D:\GitLabs\Laba2\graph.txt");
  int j = 0;

  if (!file.is_open()) std::cout << "reahjngkrs;o";

  while (getline(file, str)) {
    int i = 0, k = 0;

    while (str[k] != 0) {
      string s1, s2;
      while (str[k] != ' ') {
        s1 += str[k];
        k++;
      }

      while (str[k] != ' ') {
        s2 += str[k];
        k++;
      }

      g[i][j] = make_pair(stoi(s1), stoi(s2));
      i++;
    }
    j++;
  }
  file.close();

  int start, end;
  std::cout << "select starting point" << std::endl;
  std::cin >> start;
  std::cout << "select finishing point" << std::endl;
  std::cin >> end;

  std::cout << dijkstraTree(g, start, end) << std::endl;
  std::cout << dijkstraHeap(g, start, end) << std::endl;
}
