#ifndef INCLUDE_PQUEUE_H_
#define INCLUDE_PQUEUE_H_

#include "RBTree.h"
#include "Heap.h"
#include <vector>

using std::vector;

class PQueueTree: public RBTree {
  RBTree d, v;
 public:
  int countOp;

  void push(pair<int, int> n);  //  first - расстояние, second - вершина
  pair<int, int> min();  //  first - расстояние, second - вершина
  void update(int key, int new_value);  //  key - вершина, value - расстояние
  void deleteMin(pair<int, int> dist);  //  удаляет вершину с минимальным расстоянием. dist.first == distance
  int getCurVal(int vkey);  //  текущее значение расстояния до данной вершины
  bool empty();
};

class PQueueHeap: public DHeap {
  DHeap d;
 public:
  void push(pair<int, int> n);
  pair<int, int> min();  //  first - расстояние, second - вершина
  void update(int key, int new_value);  //  key - вершина, new_value - расстояние
  void deleteMin(pair<int, int> dist);  //  удаляет вершину с минимальным расстоянием, dist.first == distance
  int getCurVal(int key);
  bool empty();
};

int dijkstraTree(vector< vector< pair<int, int> > > g, int start, int end);
int dijkstraHeap(vector< vector< pair<int, int> > > g, int start, int end);

#endif  // INCLUDE_PQUEUE_H_
