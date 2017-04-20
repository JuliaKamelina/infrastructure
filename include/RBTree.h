#ifndef INCLUDE_RBTREE_H_
#define INCLUDE_RBTREE_H_

#include <queue>
#include <stdexcept>

template <class T>
struct CNode {
  T val;
  CNode<T>* left;
  CNode<T>* right;
  CNode<T>* parent;
  char color;

  CNode<T>(T v, CNode<T>* l, CNode<T>* r, CNode<T>* p, char c) {
    val = v;
    left = l;
    right = r;
    parent = p;
    color = c;
  }
};

template <class T>
class RBTree {
  CNode<T>* root;

  void rotateLeft(CNode<T>* n);
  void rotateRight(CNode<T>* n);
  void fixCase1(CNode<T>* n);
  void fixCase2(CNode<T>* n);
  void fixCase3(CNode<T>* n);
  void fix(CNode<T>* n);
  void deleteFix(CNode<T>* n);

 public:
  CNode<T>* insert(T value);
  void deleteNode(CNode<T>* n);
  CNode<T>* getMin();
  CNode<T>* find(T value);

  RBTree();
  ~RBTree();
  CNode<T>* getRoot();
};


template <class T>
RBTree<T>::RBTree() {
  root = nullptr;
}

template <class T>
RBTree<T>::~RBTree() {
  std::queue<CNode<T>* > q;

  if (root != nullptr) {
    q.push(root);
  } else {
    delete root;
  }

  while (!q.empty()) {
    CNode<T>* tmp = q.front();
    q.pop();

    if (tmp->left != nullptr) q.push(tmp->left);
    if (tmp->right != nullptr) q.push(tmp->right);

    delete tmp;
  }
}

template <class T>
CNode<T>* RBTree<T>::getRoot() {
  return root;
}

template <class T>
CNode<T>* RBTree<T>::find(T value) {
  CNode<T>* cur = root;

  while (cur != nullptr) {
    if (cur->val == value) {
      return cur;

    } else {
      if (cur->val < value) {
        cur = cur->right;

      } else {
        cur = cur->left;
      }
    }
  }
  throw std::logic_error("Element does't exist");
}

template <class T>
void RBTree<T>::rotateLeft(CNode<T>* n) {
  CNode<T>* p = n->right;
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

template <class T>
void RBTree<T>::rotateRight(CNode<T>* n) {
  CNode<T>* p = n->left;
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

template <class T>
CNode<T>* RBTree<T>::getMin() {
  CNode<T>* n = root;
  while (n->left != nullptr) {
    n = n->left;
  }
  return n;
}

// INSERT

template <class T>
void RBTree<T>::fixCase1(CNode<T>* n) {
  CNode<T>* g = n->parent->parent;

  n->parent->color = 'B';
  g->color = 'R';
  if ((n == n->parent->left) && (n->parent == g->left)) {
    rotateRight(g);
  } else {
    rotateLeft(g);
  }
}

template <class T>
void RBTree<T>::fixCase2(CNode<T>* n) {
  CNode<T>* g = n->parent->parent;

  if ((n == n->parent->right) && (n->parent == g->left)) {
    rotateLeft(n->parent);
    n = n->left;
  } else if ((n == n->parent->left) && (n->parent == g->right)) {
    rotateRight(n->parent);
    n = n->right;
  }
  fixCase1(n);
}

template <class T>
void RBTree<T>::fixCase3(CNode<T>* n) {
  CNode<T>* u;
  if (n->parent == n->parent->parent->left) {
    u = n->parent->parent->right;
  } else {
    u = n->parent->parent->left;
  }

  if (u != nullptr && u->color == 'R' && n->parent->color == 'R') {
    n->parent->color = 'B';
    u->color = 'B';
    CNode<T>* g = n->parent->parent;
    g->color = 'R';

    if (g->parent == nullptr) {
      g->color = 'B';
    } else {
      if (g->parent->color == 'B') {
        return;
      } else {
        fixCase3(g);
      }
    }
  } else {
    fixCase2(n);
  }
}

template <class T>
void RBTree<T>::fix(CNode<T>* n) {
  if (n->parent->color == 'B') return;

  CNode<T>* u;
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

template <class T>
CNode<T>* RBTree<T>::insert(T value) {
  CNode<T>* cur = root;
  CNode<T>* curp = 0;

  while (cur != nullptr) {
    curp = cur;
    if (cur->val <= value) {
      cur = cur->right;
    } else {
      cur = cur->left;
    }
  }

  CNode<T>* node = new CNode<T>(value, 0, 0, curp, 'R');
  if (curp == nullptr) {
    node->color = 'B';
    root = node;
  } else {
    if (node->val < curp->val) {
      curp->left = node;
    } else {
      curp->right = node;
    }
  }

  if (node->parent != nullptr) {
    fix(node);
  }

  while (root->parent != nullptr) {
    root = root->parent;
  }
  return node;
}

//  DELETE

template <class T>
void RBTree<T>::deleteFix(CNode<T>* n) {
  CNode<T>* s = 0;
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

      if (s->left != nullptr) {
        slc = s->left->color;
      }
      if (s->right != nullptr) {
        src = s->right->color;
      }

      if ((n->parent->color == 'B') && (s->color == 'B')
        && (slc == 'B') && (src == 'B')) {
        s->color = 'R';
      } else {
        break;
      }
    }
    n = n->parent;
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

template <class T>
void RBTree<T>::deleteNode(CNode<T>* n) {
  if (n == nullptr) return;
  CNode<T>* p;
  CNode<T>* q;
  if (n->left == nullptr || n->right == nullptr) {
    p = n;
  } else {
    p = n->right;
    while (p->left != nullptr) {
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
    delete p;
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

  delete p;
  while (root->parent != nullptr) {
    root = root->parent;
  }
}

#endif  // INCLUDE_RBTREE_H_
