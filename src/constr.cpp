#include "add.h"

CNode* construct(int *arr, int n) {
  std::stack<Node*> s;
  CNode* root = new CNode(arr[n/2]);
  Node* cRoot = new Node(0, n, root);
//  int begin = 0;
//  int end = n;
  s.push(cRoot);
//  int mid = (cRoot->begin - cRoot->end)/2;

  while (!s.empty()) {
    Node* node = s.top();
    s.pop();

    int mid = (node->begin - node->end)/2;
    if ((node->end - mid) != 1) {
      CNode* rNode = new CNode(arr[mid + (node->end - mid)/2]);
      node->treeNode->right = rNode;
      Node* rTreeNode = new Node(mid, node->end, rNode);
      s.push(rTreeNode);
    }

    if ((mid - node->begin) != 1) {
      CNode* lNode = new CNode(arr[mid - (mid - node->begin)/2]);
      node->treeNode->left = lNode;
      Node* lTreeNode = new Node(node->begin, mid, lNode);
      s.push(lTreeNode);
    }
  }
  return root;
}

int main() {

  
