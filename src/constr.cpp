#include "constr.h"

CNode* construct(int *arr, int n) {
  if (arr == 0) return 0;

  std::stack<Node*> s;
  CNode* root = new CNode(arr[(n - 1)/2]);
  Node* cRoot = new Node(0, n - 1, root);
  s.push(cRoot);

  while (!s.empty()) {
    Node* node = s.top();
    s.pop();

    int mid = (node->begin + node->end)/2;
    if (node->end - mid >= 1) {
      CNode* rNode = new CNode(arr[(mid + 1 + node->end)/2]);
      node->treeNode->right = rNode;
      Node* rTreeNode = new Node(mid + 1, node->end, rNode);
      s.push(rTreeNode);
    }

    if (mid - node->begin >= 1) {
      CNode* lNode = new CNode(arr[(mid  - 1 + node->begin)/2]);
      node->treeNode->left = lNode;
      Node* lTreeNode = new Node(node->begin, mid - 1, lNode);
      s.push(lTreeNode);
    }
  }
  return root;
}
