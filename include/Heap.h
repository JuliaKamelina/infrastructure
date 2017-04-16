#ifndef INCLUDE_HEAP_H_
#define INCLUDE_HEAP_H_

#include <utility>

using std::pair;
using std::make_pair;

const int N = 100;
const int d = 2;

class DHeap {  //  key == текущее расстояние, value == вершина
  int size;
  pair<int, int> *arr;  //  ???????

  void dive(int i);
  int emerge(int i);
  int minChild(int i);

 public:
  DHeap();
  int getSize();
  pair<int, int>& operator[](int i);

  pair<int, int> getMin();
  int find(int key, int value);  //  поиск по расстоянию
  int findV(int value);  //  поиск по вершине
  int insert(int key, int value);
  void deleteNode(int i);  //  ???ИЛИ ПЕРЕДАВАТЬ ЗНАЧЕНИЕ???
};

#endif  // INCLUDE_HEAP_H_
