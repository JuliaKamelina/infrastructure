#include "PQueue.h"
#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ifstream;
using std::make_pair;

int main() {
  vector<vector<pair<int, int> > >g;
  string str;
  ifstream file("graph.txt", ifstream::in);

  if (!file.is_open()) std::cout << "FILE NOT FOUND" << std::endl;

  while (getline(file, str)) {
    int j = 0, k = 0;
    vector<pair<int, int> > p;

    j = atoi(&str[k]);
    if (j == 0) {
      p.push_back(make_pair(-1, -1));
    }

    k++;
    while (str[k] != 0) {
      k++;
      string s1, s2;
      while (str[k] != ' ') {
        s1 += str[k];
        k++;
      }
      k++;

      while ((str[k] != ' ') && (str[k] != 0)) {
        s2 += str[k];
        k++;
      }

      int d = stoi(s1);
      int v = stoi(s2);
      p.push_back(make_pair(d, v));
    }
    g.push_back(p);
  }
  file.close();

  int start, end;
  std::cout << "select starting point" << std::endl;
  std::cin >> start;
  std::cout << "select finishing point" << std::endl;
  std::cin >> end;

  std::cout << "Dijkstra on Tree -- " << dijkstraTree(g, start, end)[end] << std::endl;
  std::cout << "Dijkstra on Heap -- " << dijkstraHeap(g, start, end)[end] << std::endl;
}
