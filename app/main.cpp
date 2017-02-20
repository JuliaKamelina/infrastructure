#include "tree.h"

int main() {
  CNode* tree = new CNode(4);
  tree->left = new CNode(2);
  tree->right = new CNode(6);
  tree->right->left = new CNode(5);
  tree->right->right = new CNode(7);
  tree->left->left = new CNode(1);
  tree->left->right = new CNode(3);

  print(tree);
}
