#ifndef INCLUDE_RBTREE_H_
#define INCLUDE_RBTREE_H_

#include <utility>

using std::pair;
using std::make_pair;

struct CNode {
  pair<int, int> val;
  CNode* left;
  CNode* right;
  CNode* parent;
  char color;

  CNode(pair<int, int> v, CNode* l, CNode* r, CNode* p, char c) {
    val = make_pair(v.first, v.second);
    left = l;
    right = r;
    parent = p;
    color = c;
  }
};

class RBTree {
  CNode* root;

  void rotateLeft(CNode* n);
  void rotateRight(CNode* n);
  void fixCase1(CNode* n);
  void fixCase2(CNode* n);
  void fixCase3(CNode* n);
  void fix(CNode* n);
  void deleteFix(CNode* n);

 public:
  CNode* findV(int key);
  CNode* findInsert(int key, int value);
  void deleteNode(CNode* n);
  CNode* getMin();

  RBTree();
  CNode* getRoot();

  int count;
};

#endif  // INCLUDE_RBTREE_H_
