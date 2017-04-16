#ifndef INCLUDE_HEAP_H_
#define INCLUDE_HEAP_H_

#include <utility>

using std::pair;
using std::make_pair;

const int N = 100;
const int d = 2;

class DHeap {  //  key == ������� ����������, value == �������
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
  int find(int key, int value);  //  ����� �� ����������
  int findV(int value);  //  ����� �� �������
  int insert(int key, int value);
  void deleteNode(int i);  //  ???��� ���������� ��������???
};

#endif  // INCLUDE_HEAP_H_
