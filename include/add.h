#ifndef INCLUDE_CONSTRUCT_H_
#define INCLUDE_CONSTRUCT_H_

#include <stack>

struct CNode {
  int val;
  CNode* left;
  CNode* right;

  CNode (int v = 0) {
    val = v;
    left = 0;
    right = 0;
  }
};

struct Node {
  int begin;
  int end;
  CNode* treeNode;

  Node (int b = 0, int e = 0, CNode* n) {
    begin = b;
    end = e;
    treeNode = n;
  }
};

#endif  // INCLUDE_CONSTRUCT_H_
