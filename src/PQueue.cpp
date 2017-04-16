#include "PQueue.h"

//  PQ НА ДЕРЕВЕ

pair<int, int> PQueueTree::min() {
  countOp = 0;

  pair<int, int> res = d.getMin()->val;
  countOp += d.count;
  return res;
}

bool PQueueTree::empty() {
  if (d.getRoot() == nullptr) {
    return true;
  } else {
    return false;
  }
}

void PQueueTree::push(pair<int, int> n) {
  countOp = 0;

  d.findInsert(n.first, n.second);
  countOp += d.count;
  v.findInsert(n.second, n.first);
  countOp += v.count;
}

void PQueueTree::update(int key, int new_value) {
  countOp = 0;

  CNode* dist = v.findV(key);  //  нашли заданную вершину
  countOp += v.count;
  CNode* node = d.findInsert(dist->val.second, key);  //  нашли ее же в графе с расстояниями
  countOp += d.count;
  d.deleteNode(node);  //  удалили из графа расстояний
  countOp += d.count;
  dist->val.second = new_value;  //  ИЗМЕНИЛИ рассотяние в графе с вершинами
  d.findInsert(new_value, key);  //  изменили расстояние в графе с расстояниями
  countOp += d.count;
}

void PQueueTree::deleteMin(pair<int, int> dist) {
  countOp = 0;

  CNode* node = d.getMin();
  countOp += d.count;
  d.deleteNode(node);
  countOp += d.count;

  node = v.findInsert(dist.second, dist.first);
  countOp += v.count;
  v.deleteNode(node);
  countOp += v.count;
}

int PQueueTree::getCurVal(int vkey) {
  countOp = 0;

  CNode* res = v.findV(vkey);
  countOp += v.count;

  if (res != nullptr) {
    return res->val.second;
  } else {
    return -1;
  }
}

//  PQ НА КУЧЕ

pair<int, int> PQueueHeap::min() {
  return d.getMin();
}

bool PQueueHeap::empty() {
  if (d.getSize() == 0) {
    return true;
  } else {
    return false;
  }
}

void PQueueHeap::push(pair<int, int> n) {
  d.insert(n.first, n.second);
}

void PQueueHeap::update(int key, int new_value) {
  int i = d.findV(key);
  d.deleteNode(i);
  d.insert(new_value, key);
}

void PQueueHeap::deleteMin() {
  d.deleteNode(0);
}

int PQueueHeap::getCurVal(int vkey) {
  int i = d.findV(vkey);
  return d[i].first;
}
