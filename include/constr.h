#ifndef INCLUDE_CONSTR_H_
#define INCLUDE_CONSTR_H_

#include <stack>

struct CNode {
  int val;
  CNode* left;
  CNode* right;

  explicit CNode(int v = 0) {
    val = v;
    left = 0;
    right = 0;
  }
};

struct Node {
  int begin;
  int end;
  CNode* treeNode;

  Node(int b, int e, CNode* n) {
    begin = b;
    end = e;
    treeNode = n;
  }
};

CNode* construct(int *arr, int n);

#endif  //  INCLUDE_CONSTR_H_
