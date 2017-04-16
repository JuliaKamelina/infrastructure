#include "Heap.h"

DHeap::DHeap() {
  arr = new pair<int, int>[N];
  size = 0;
}

int DHeap::getSize() {
  return size;
}

pair<int, int> DHeap::getMin() {
  return arr[0];
}

pair<int, int>& DHeap::operator[](int i) {
  return arr[i];
}

int DHeap::minChild(int i) {
  if (i*d + 1 >= size) return 0;

  int s = i*d + 1;
  pair<int, int> min = arr[s];
  for (int j = s; j < i*d + d + 1; j++) {
    if (min.first > arr[j].first) {
      min = arr[j];
      s = j;
    }
  }
  return s;
}

void DHeap::dive(int i) {
  int child = minChild(i);

  while ((child != 0) && (child != size) && (arr[i].first > arr[child].first)) {
    swap(arr[i], arr[child]);
    i = child;
    child = minChild(i);
  }
}

int DHeap::emerge(int i) {
  int parent = (i - 1)/d;

  while ((i != 0) && (arr[parent].first > arr[i].first)) {
    swap(arr[i], arr[parent]);
    i = parent;
    parent = (i - 1)/d;
  }
  return i;
}

int DHeap::insert(int key, int value) {
  arr[size] = make_pair(key, value);
  int i = emerge(size);
  size++;
  return i;
}

int DHeap::find(int key, int value) {
  for (int i = 0; i < size; i++) {
    if (arr[i].first == key && arr[i].second == value) return i;
  }

  return 0;
}

int DHeap::findV(int value) {
  for (int i = 0; i < size; i++) {
    if (arr[i].second == value) return i;
  }

  return 0;
}

void DHeap::deleteNode(int i) {
  arr[i] = arr[size - 1];
  arr[size - 1] = make_pair(0, 0);
  size--;

  if (i != size) {
    if ((i != 0) && (arr[i].first < arr[(i - 1) / d].first)) {
      emerge(i);
    } else {
      dive(i);
    }
  }
}
