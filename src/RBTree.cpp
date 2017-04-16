#include "RBTree.h"

RBTree::RBTree() {
  root = 0;
  count = 0;
}

CNode* RBTree::getRoot() {
  return root;
}

void RBTree::rotateLeft(CNode* n) {
  CNode* p = n->right;
  p->parent = n->parent;

  if (n->parent != nullptr) {
    if (n->parent->left == n) {
      n->parent->left = p;
    } else {
      n->parent->right = p;
    }
  }

  n->right = p->left;
  if (p->left != nullptr) {
    p->left->parent = n;
  }

  n->parent = p;
  p->left = n;
}

void RBTree::rotateRight(CNode* n) {
  CNode* p = n->left;
  p->parent = n->parent;

  if (n->parent != nullptr) {
    if (n->parent->left == n) {
      n->parent->left = p;
    } else {
      n->parent->right = p;
    }
  }

  n->left = p->right;
  if (p->right != nullptr)
    p->right->parent = n;

  n->parent = p;
  p->right = n;
}

CNode* RBTree::getMin() {
  count = 0;

  CNode* n = root;
  while (n->left != nullptr) {
    n = n->left;

    count++;
  }

  return n;
}

// INSERT

void RBTree::fixCase1(CNode* n) {
  CNode* g = n->parent->parent;

  n->parent->color = 'B';
  g->color = 'R';
  if ((n == n->parent->left) && (n->parent == g->left)) {
    rotateRight(g);
  } else {
    rotateLeft(g);
  }
}

void RBTree::fixCase2(CNode* n) {
  CNode* g = n->parent->parent;

  if ((n == n->parent->right) && (n->parent == g->left)) {
    rotateLeft(n->parent);
    n = n->left;
    count++;
  } else if ((n == n->parent->left) && (n->parent == g->right)) {
    rotateRight(n->parent);
    n = n->right;
    count++;
  }
  fixCase1(n);
}

void RBTree::fixCase3(CNode* n) {
  CNode* u;
  if (n->parent == n->parent->parent->left) {
    u = n->parent->parent->right;
  } else {
    u = n->parent->parent->left;
  }

  if (u != nullptr && u->color == 'R' && n->parent->color == 'R') {
    n->parent->color = 'B';
    u->color = 'B';
    CNode* g = n->parent->parent;
    g->color = 'R';

    if (g->parent == nullptr) {
      g->color = 'B';
    } else {
      if (g->parent->color == 'B') {
        return;
      } else {
        count++;  //  ????RECURSION INCREASES COUNT????
        fixCase3(g);
      }
    }
  } else {
    fixCase2(n);
  }
}

void RBTree::fix(CNode* n) {
  if (n->parent->color == 'B') return;

  CNode* u;
  if (n->parent == n->parent->parent->left) {
    u = n->parent->parent->right;
  } else {
    u = n->parent->parent->left;
  }
  if (u == nullptr) {
    fixCase2(n);
  } else {
    switch (u->color) {
    case 'B':
      if (n == n->parent->left) {
        fixCase1(n);
      } else {
        fixCase2(n);
      }
      break;
    case 'R':
      fixCase3(n);
      break;
    }
  }
}

CNode* RBTree::findInsert(int key, int value) {
  count = 0;

  CNode* cur = root;
  CNode* curp = 0;

  while (cur != nullptr) {
    if ((cur->val.first == key) && (cur->val.second == value)) return cur;

    curp = cur;
    if (cur->val.first <= key) {
      cur = cur->right;
      count++;
    } else {
      cur = cur->left;
      count++;
    }
  }

  CNode* node = new CNode(make_pair(key, value), 0, 0, curp, 'R');
  if (curp == nullptr) {
    node->color = 'B';
    root = node;
  } else {
    if (node->val.first < curp->val.first) {
      curp->left = node;
    } else {
      curp->right = node;
    }
  }

  if (node->parent != nullptr) fix(node);

  while (root->parent != nullptr) {
    root = root->parent;
    count++;
  }
  return node;
  }

CNode* RBTree::findV(int key) {
  count = 0;

  CNode* cur = root;

  while (cur != nullptr) {
    if (cur->val.first == key) return cur;

    if (cur->val.first < key) {
      cur = cur->right;
      count++;
    } else {
      cur = cur->left;
      count++;
    }
  }
  return nullptr;
}

//  DELETE

void RBTree::deleteFix(CNode* n) {
  CNode* s = 0;
  char slc = 'B';
  char src = 'B';

  while (n->parent != nullptr) {
    if (n == n->parent->left) {
      s = n->parent->right;
    } else {
      s = n->parent->left;
    }

    if (s != nullptr) {
      if (s->color == 'R') {
        n->parent->color = 'R';
        s->color = 'B';
        if (n == n->parent->left) {
          rotateLeft(n->parent);
        } else {
          rotateRight(n->parent);
        }
      }

      if (s->left != nullptr) slc = s->left->color;
      if (s->right != nullptr) src = s->right->color;

      if ((n->parent->color == 'B') && (s->color == 'B')
        && (slc == 'B') && (src == 'B')) {
        s->color = 'R';
      } else {
        break;
      }
    }
    n = n->parent;
    count++;
  }

  if (n->parent == nullptr) return;

  if (s != nullptr) {
    if ((n->parent->color == 'R') && (s->color == 'B') &&
      (slc == 'B') && (src == 'B')) {
      s->color = 'R';
      n->parent->color = 'B';

    } else {
      if (s->color == 'B') {
        if ((n == n->parent->left) && (src == 'B') && (slc == 'R')) {
          s->color = 'R';
          slc = 'B';
          rotateRight(s);

        } else if ((n == n->parent->right) && (slc == 'B') && (src == 'R')) {
          s->color = 'R';
          src = 'B';
          rotateLeft(s);
        }
      }

      s->color = n->parent->color;
      n->parent->color = 'B';

      if (n == n->parent->left) {
        src = 'B';
        rotateLeft(n->parent);
      } else {
        slc = 'B';
        rotateRight(n->parent);
      }
    }

    if (s->left != nullptr) s->left->color = slc;
    if (s->right != nullptr) s->right->color = src;
  }
}

void RBTree::deleteNode(CNode* n) {
  count = 0;

  if (n == nullptr) return;
  CNode* p;
  CNode* q;
  if (n->left == nullptr || n->right == nullptr) {
    p = n;
  } else {
    p = n->right;
    while (p->left != nullptr) {
      count++;
      p = p->left;
    }
  }

  if (p->left != nullptr)
    q = p->left;
  else
    q = p->right;

  if (q != nullptr) q->parent = p->parent;

  if (p->parent == nullptr) {
    root = q;
    if (q != nullptr) root->color = 'B';
    delete(p);
    return;
  } else {
    if (p == p->parent->left) {
      p->parent->left = q;
    } else {
      p->parent->right = q;
    }
  }

  if (p != n && n != nullptr) n->val = p->val;

  if (p->color == 'B') {
    if (q == nullptr) {
      deleteFix(p);
    } else {
      deleteFix(q);
    }
  }

  delete(p);
  while (root->parent != nullptr) {
    count++;
    root = root->parent;
  }
}
