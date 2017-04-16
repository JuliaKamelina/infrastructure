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

  void push(pair<int, int> n);  //  first - ����������, second - �������
  pair<int, int> min();  //  first - ����������, second - �������
  void update(int key, int new_value);  //  key - �������, value - ����������
  void deleteMin(pair<int, int> dist);  //  ������� ������� � ����������� �����������. dist.first == distance
  int getCurVal(int vkey);  //  ������� �������� ���������� �� ������ �������
  bool empty();
};

class PQueueHeap: public DHeap {
  DHeap d;
 public:
  void push(pair<int, int> n);
  pair<int, int> min();  //  first - ����������, second - �������
  void update(int key, int new_value);  //  key - �������, new_value - ����������
  void deleteMin(pair<int, int> dist);  //  ������� ������� � ����������� �����������, dist.first == distance
  int getCurVal(int key);
  bool empty();
};

int dijkstraTree(vector< vector< pair<int, int> > > g, int start, int end);
int dijkstraHeap(vector< vector< pair<int, int> > > g, int start, int end);

#endif  // INCLUDE_PQUEUE_H_
