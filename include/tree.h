#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <stack>

struct CNode {
  int val;
  CNode* left, *right;
  explicit CNode(int v);
};


CNode** find(CNode** root, int v);
void print(CNode *root);

#endif  // INCLUDE_TREE_H_
