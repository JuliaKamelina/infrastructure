#ifndef INCLUDE_PQUEUE_H_
#define INCLUDE_PQUEUE_H_

#include "RBTree.h"
#include "Heap.h"
#include <vector>
#include <utility>

using std::vector;
using std::pair;

template <class T>
class PQueueTree: public RBTree<T> {
  RBTree<T> d;
 public:
  void push(T n);
  T min();
  void deleteMin();
  bool empty();
};

template <class T>
class PQueueHeap: public DHeap<T> {
  DHeap<T> d;
 public:
  void push(T n);
  T min();
  bool empty();
  void deleteMin();
};

vector<int> dijkstraTree(vector< vector< pair<int, int> > > g, int start, int end);
vector<int> dijkstraHeap(vector< vector< pair<int, int> > > g, int start, int end);



//  PQ мю депебе

template <class T>
T PQueueTree<T>::min() {
  return d.getMin()->val;
}

template <class T>
bool PQueueTree<T>::empty() {
  if (d.getRoot() == nullptr) {
    return true;
  } else {
    return false;
  }
}

template <class T>
void PQueueTree<T>::push(T n) {
  d.insert(n);
}

template <class T>
void PQueueTree<T>::deleteMin() {
  CNode<T>* node = d.getMin();
  d.deleteNode(node);
}

//  PQ мю йсве

template <class T>
T PQueueHeap<T>::min() {
  return d.getMin();
}

template <class T>
bool PQueueHeap<T>::empty() {
  if (d.getSize() == 0) {
    return true;
  } else {
    return false;
  }
}

template <class T>
void PQueueHeap<T>::push(T n) {
  d.insert(n);
}

template <class T>
void PQueueHeap<T>::deleteMin() {
  d.deleteNode(0);
}
#endif  // INCLUDE_PQUEUE_H_
