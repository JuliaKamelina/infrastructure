#ifndef INCLUDE_HEAP_H_
#define INCLUDE_HEAP_H_

#include <vector>

using std::vector;
const int d = 3;

template <class T>
class DHeap {
  int size;
  vector<T> arr;

  void dive(int i);
  int emerge(int i);
  int minChild(int i);

 public:
  DHeap();
  int getSize();
  T& operator[](int i);

  T getMin();
  int insert(T val);
  void deleteNode(int i);
};


template <class T>
DHeap<T>::DHeap() {
  size = 0;
}

template <class T>
int DHeap<T>::getSize() {
  return size;
}

template <class T>
T DHeap<T>::getMin() {
  return arr[0];
}

template <class T>
T& DHeap<T>::operator[](int i) {
  return arr[i];
}

template <class T>
int DHeap<T>::minChild(int i) {
  if (i*d + 1 >= size) return 0;

  int s = i*d + 1;
  T min = arr[s];
  for (int j = s; (j < i*d + d + 1) && (j < size); j++) {
    if (min > arr[j]) {
      min = arr[j];
      s = j;
    }
  }
  return s;
}

template <class T>
void DHeap<T>::dive(int i) {
  int child = minChild(i);

  while ((child != 0) && (child != size) && (arr[i] > arr[child])) {
    std::swap(arr[i], arr[child]);
    i = child;
    child = minChild(i);
  }
}

template <class T>
int DHeap<T>::emerge(int i) {
  int parent = (i - 1) / d;

  while ((i != 0) && (arr[parent] > arr[i])) {
    std::swap(arr[i], arr[parent]);
    i = parent;
    parent = (i - 1) / d;
  }
  return i;
}

template <class T>
int DHeap<T>::insert(T val) {
  arr.push_back(val);
  int i = emerge(size);
  size++;
  return i;
}

template <class T>
void DHeap<T>::deleteNode(int i) {
  arr[i] = arr[size - 1];
  arr.pop_back();
  size--;

  if (i != size) {
    if ((i != 0) && (arr[i] < arr[(i - 1) / d])) {
      emerge(i);
    } else {
      dive(i);
    }
  }
}

#endif  // INCLUDE_HEAP_H_
