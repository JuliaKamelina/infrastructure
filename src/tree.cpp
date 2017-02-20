#include "tree.h"

CNode::CNode(int v = 0) {
  val = v;
  left = 0;
  right = 0;
}

CNode** find(CNode** root, int v) {
  CNode** start = root;
  while (*start) {
    if ((*start)->val == v) {
      return start;
    } else {
     if ((*start)->val < v) {
       start = &(*start)->right;
     } else {
       start = &(*start)->left;
     }
    }
  }
  return start;
}

void print(CNode* root) {
  std::stack<CNode*> s;
  bool goleft = true;  //  налево ходить можно

  s.push(root);
  while (root) {
    while ((root->left) && (goleft)) {
      s.push(root->left);
      root = root->left;
    }

    std::cout << root << ' ' << root->val << ' ';
    std::cout << root->left << ' ' << root->right << std::endl;
    s.pop();

    if (root->right) {
      s.push(root->right);
      root = root->right;
      goleft = true;
    } else {
      if (!s.empty()) {
        root = s.top();
        goleft = false;  //  перехлд на уровень выше, налево нельзя
      } else {
        root = 0;
      }
    }
  }
}
