#include <gtest/gtest.h>
#include "RBTree.h"
#include "Heap.h"
#include "PQueue.h"

#include <queue>

TEST(RBTREE, canFindExistingElement) {
  RBTree rTree;

  CNode* tree = rTree.findInsert(7, 1);
  rTree.findInsert(5, 1);
  rTree.findInsert(1, 2);
  rTree.findInsert(9, 0);
  rTree.findInsert(6, 1);

  tree = rTree.findInsert(1, 2);

  EXPECT_EQ(tree->val.first, 1);
  EXPECT_EQ(tree->val.second, 2);
}

TEST(RBTREE, canUpdateExistingValue) {
  RBTree rTree;

  CNode* tree = rTree.findInsert(7, 1);
  rTree.findInsert(5, 1);
  rTree.findInsert(1, 2);
  rTree.findInsert(9, 0);
  rTree.findInsert(6, 1);

  tree = rTree.findInsert(1, 2);

  tree->val.second = 4;

  CNode* tree1 = rTree.findInsert(1, 4);

  EXPECT_EQ(tree->val.second, tree1->val.second);
}

TEST(RBTREE, canFindMin) {
  RBTree rTree;
  CNode* tree = rTree.findInsert(7, 1);
  rTree.findInsert(5, 1);
  rTree.findInsert(3, 0);
  rTree.findInsert(4, 9);
  rTree.findInsert(2, 1);
  rTree.findInsert(1, 2);
  rTree.findInsert(0, 2);
  rTree.findInsert(-1, 2);

  EXPECT_EQ(-1, rTree.getMin()->val.first);
}

TEST(RBTREE, canInsert) {
  RBTree rTree;
  CNode* tree = rTree.findInsert(7, 1);
  rTree.findInsert(5, 1);
  rTree.findInsert(3, 0);
  rTree.findInsert(4, 9);
  rTree.findInsert(2, 1);
  rTree.findInsert(1, 2);
  rTree.findInsert(0, 2);
  rTree.findInsert(-1, 2);
  tree = rTree.getRoot();

  EXPECT_EQ(tree->val.first, 3);
  EXPECT_EQ(tree->color, 'B');
  EXPECT_EQ(tree->right->val.first, 5);
  EXPECT_EQ(tree->right->color, 'R');
  EXPECT_EQ(tree->right->left->val.first, 4);
  EXPECT_EQ(tree->right->left->color, 'B');
  EXPECT_EQ(tree->right->right->val.first, 7);
  EXPECT_EQ(tree->right->right->color, 'B');
  EXPECT_EQ(tree->left->val.first, 1);
  EXPECT_EQ(tree->left->color, 'R');
  EXPECT_EQ(tree->left->left->val.first, 0);
  EXPECT_EQ(tree->left->left->color, 'B');
  EXPECT_EQ(tree->left->right->val.first, 2);
  EXPECT_EQ(tree->left->right->color, 'B');
  EXPECT_EQ(tree->left->left->left->val.first, -1);
  EXPECT_EQ(tree->left->left->left->color, 'R');
}

TEST(RBTREE, hight) {
  RBTree rTree;

  CNode* tree = rTree.findInsert(7, 1);
  rTree.findInsert(5, 1);
  rTree.findInsert(3, 0);
  rTree.findInsert(4, 9);
  rTree.findInsert(2, 1);
  rTree.findInsert(1, 2);
  rTree.findInsert(0, 2);
  rTree.findInsert(-1, 2);

  tree = rTree.getRoot();

  std::queue<CNode* > q;  //  cчитает высоту
  int h = 0;
  q.push(tree);

  while (!q.empty()) {
    int s = q.size();
    for (int i = 0; i < s; i++) {
      CNode* node = q.front();
      q.pop();

      if (node->left != nullptr) q.push(node->left);
      if (node->right != nullptr) q.push(node->right);
    }
    h++;
  }

  EXPECT_EQ(h - 1, log(8) / log(2));
}

TEST(RBTREE, hightAfterDelete) {
  RBTree rTree;

  CNode* tree = rTree.findInsert(7, 1);
  tree = rTree.findInsert(5, 1);
  rTree.findInsert(1, 2);
  rTree.findInsert(9, 0);
  rTree.findInsert(6, 1);

  rTree.deleteNode(tree);

  tree = rTree.getRoot();

  std::queue<CNode* > q;  //  cчитает высоту
  int h = 0;
  q.push(tree);

  while (!q.empty()) {
    int s = q.size();
    for (int i = 0; i < s; i++) {
      CNode* node = q.front();
      q.pop();

      if (node->left != nullptr) q.push(node->left);
      if (node->right != nullptr) q.push(node->right);
    }
    h++;
  }

  EXPECT_EQ(h - 1, log(4) / log(2));
}

TEST(RBTREE, canDeleteRoot) {
  RBTree rTree;

  CNode* tree = rTree.findInsert(7, 1);
  tree = rTree.findInsert(5, 1);
  rTree.findInsert(1, 2);
  rTree.findInsert(9, 0);
  rTree.findInsert(6, 1);

  rTree.deleteNode(tree);

  tree = rTree.getRoot();

  EXPECT_EQ(tree->val.first, 6);
  EXPECT_EQ(tree->color, 'B');
  EXPECT_EQ(tree->left->val.first, 1);
  EXPECT_EQ(tree->left->color, 'B');
  EXPECT_EQ(tree->right->val.first, 7);
  EXPECT_EQ(tree->right->color, 'B');
  EXPECT_EQ(tree->right->right->val.first, 9);
  EXPECT_EQ(tree->right->right->color, 'R');
}

TEST(RBTREE, canDeleteLeaf) {
  RBTree rTree;

  CNode* tree = rTree.findInsert(7, 1);
  rTree.findInsert(5, 1);
  rTree.findInsert(1, 2);
  tree = rTree.findInsert(9, 0);
  rTree.findInsert(6, 1);

  rTree.deleteNode(tree);

  tree = rTree.getRoot();

  EXPECT_EQ(tree->val.first, 5);
  EXPECT_EQ(tree->color, 'B');
  EXPECT_EQ(tree->left->val.first, 1);
  EXPECT_EQ(tree->left->color, 'B');
  EXPECT_EQ(tree->right->val.first, 7);
  EXPECT_EQ(tree->right->color, 'B');
  EXPECT_EQ(tree->right->left->val.first, 6);
  EXPECT_EQ(tree->right->left->color, 'R');
}

TEST(RBTREE, canDeleteTwoNodesTree) {
  RBTree rTree;

  CNode* tree = rTree.findInsert(7, 1);
  rTree.findInsert(5, 1);

  rTree.deleteNode(tree);

  EXPECT_EQ(rTree.getRoot()->val.first, 5);
  EXPECT_EQ(rTree.getRoot()->color, 'B');
}

TEST(RBTREE, canDeleteOnlyRoot) {
  RBTree rTree;

  CNode* tree = rTree.findInsert(7, 1);

  rTree.deleteNode(tree);

  EXPECT_EQ(rTree.getRoot(), nullptr);
}

TEST(HEAP, canInsert) {
  DHeap h;

  pair<int, int> a[4] = {make_pair(1, 2), make_pair(0, 2), make_pair(7, 1), make_pair(4, 1)};

  for (int i = 0; i < 4; i++) {
    int j = h.insert(a[i].first, a[i].second);
    EXPECT_EQ(h[j], a[i]);
  }
}

TEST(HEAP, minOnTop) {
  DHeap h;

  pair<int, int> a[4] = { make_pair(1, 2), make_pair(0, 2), make_pair(7, 1), make_pair(4, 1) };

  for (int i = 0; i < 4; i++) {
    h.insert(a[i].first, a[i].second);
  }

  EXPECT_EQ(h[0], a[1]);
}

TEST(HEAP, canFindExistingValues) {
  DHeap h;

  pair<int, int> a[4] = { make_pair(1, 2), make_pair(0, 2), make_pair(7, 1), make_pair(4, 1) };

  for (int i = 0; i < 4; i++) {
    h.insert(a[i].first, a[i].second);
  }

  for (int i = 0; i < 4; i++) {
    int j = h.find(a[i].first, a[i].second);
    EXPECT_EQ(h[j], a[i]);
  }
}

TEST(HEAP, canDelete) {
  DHeap h;

  pair<int, int> a[4] = { make_pair(1, 2), make_pair(0, 2), make_pair(7, 1), make_pair(4, 1) };

  for (int i = 0; i < 4; i++) {
    h.insert(a[i].first, a[i].second);
  }

  for (int i = 0; i < 4; i++) {
    int j = h.find(a[i].first, a[i].second);
    h.deleteNode(j);
    EXPECT_EQ(h.find(a[i].first, a[i].second), 0);
  }
}

TEST(PQUEUETREE, canPush) {
  PQueueTree q;

  q.push(make_pair(1, 0));
  q.push(make_pair(2, 1));
  q.push(make_pair(3, 2));
  q.push(make_pair(5, 3));
  q.push(make_pair(4, 4));

  int d1 = q.countOp;

  q.push(make_pair(11, 11));
  q.push(make_pair(12, 10));
  q.push(make_pair(13, 12));
  q.push(make_pair(15, 13));
  q.push(make_pair(14, 14));

  int d2 = q.countOp;

  //  EXPECT_EQ((log(10)/*/log(2)*/ - log(5)/*/log(2)*/)/(d2 - d1), 1);  //  ????difficulty of PQ?????
}

TEST(PQUEUETREE, canGetMin) {
  PQueueTree q;

  q.push(make_pair(19, 3));
  q.push(make_pair(2, 1));
  q.push(make_pair(3, 2));
  q.push(make_pair(1, 0));

  EXPECT_EQ(q.min().first, 1);
  EXPECT_EQ(q.min().second, 0);
}

TEST(PQUEUETREE, canDelMin) {
  PQueueTree q;

  q.push(make_pair(19, 3));
  q.push(make_pair(2, 1));
  q.push(make_pair(3, 2));
  q.push(make_pair(1, 0));

  q.deleteMin(make_pair(1, 0));

  EXPECT_EQ(q.min().first, 2);
  EXPECT_EQ(q.min().second, 1);
}

TEST(PQUEUETREE, canUpdate) {
  PQueueTree q;

  q.push(make_pair(19, 3));
  q.push(make_pair(2, 1));
  q.push(make_pair(3, 2));
  q.push(make_pair(1, 0));

  q.update(2, -1);

  EXPECT_EQ(q.min().first, -1);
  EXPECT_EQ(q.min().second, 2);
}

TEST(PQUEUEHEAP, canPush) {
  PQueueHeap q;

  q.push(make_pair(1, 0));
  q.push(make_pair(2, 1));
  q.push(make_pair(3, 2));
}

TEST(PQUEUEHEAP, canGetMin) {
  PQueueHeap q;

  q.push(make_pair(19, 3));
  q.push(make_pair(2, 1));
  q.push(make_pair(3, 2));
  q.push(make_pair(1, 0));

  EXPECT_EQ(q.min().first, 1);
  EXPECT_EQ(q.min().second, 0);
}

TEST(PQUEUEHEAP, canDelMin) {
  PQueueHeap q;

  q.push(make_pair(19, 3));
  q.push(make_pair(2, 1));
  q.push(make_pair(3, 2));
  q.push(make_pair(1, 0));

  q.deleteMin(make_pair(1, 0));

  EXPECT_EQ(q.min().first, 2);
  EXPECT_EQ(q.min().second, 1);
}

TEST(PQUEUEHEAP, canUpdate) {
  PQueueHeap q;

  q.push(make_pair(19, 3));
  q.push(make_pair(2, 1));
  q.push(make_pair(3, 2));
  q.push(make_pair(1, 0));

  q.update(2, -1);

  EXPECT_EQ(q.min().first, -1);
  EXPECT_EQ(q.min().second, 2);
}

TEST(DijkstraTree, canFindWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
                                           { make_pair(1, 3) },
                                           { make_pair(3, 3) },
                                           { make_pair(-1, -1) } };
  int way = dijkstraTree(g, 0, 3);

  EXPECT_EQ(way, 5);
}

TEST(DijkstraTree, canFindMinWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
                                           { make_pair(1, 3) },
                                           { make_pair(3, 3), make_pair(2, 4) },
                                           { make_pair(1, 5) },
                                           { make_pair(1, 5), make_pair(4, 6) },
                                           { make_pair(2, 6) },
                                           { make_pair(-1, -1) } };
  int way = dijkstraTree(g, 2, 6);

  EXPECT_EQ(way, 5);
}

TEST(DijkstraTree, canDetectNonExistinWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
                                           { make_pair(1, 3) },
                                           { make_pair(3, 3) },
                                           { make_pair(-1, -1) } };
  int way = dijkstraTree(g, 2, 1);

  EXPECT_EQ(way, 0);
}

TEST(DijkstraTree, oneNode) {
  vector<vector<pair<int, int> > >g{{ make_pair(6, 2) }};

  int way = dijkstraTree(g, 2, 1);

  EXPECT_EQ(way, 0);
}

TEST(DijkstraHeap, canFindWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
  { make_pair(1, 3) },
  { make_pair(3, 3) },
  { make_pair(-1, -1) } };
  int way = dijkstraHeap(g, 0, 3);

  EXPECT_EQ(way, 5);
}

TEST(DijkstraHeap, canFindMinWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
  { make_pair(1, 3) },
  { make_pair(3, 3), make_pair(2, 4) },
  { make_pair(1, 5) },
  { make_pair(1, 5), make_pair(4, 6) },
  { make_pair(2, 6) },
  { make_pair(-1, -1) } };
  int way = dijkstraHeap(g, 2, 6);

  EXPECT_EQ(way, 5);
}

TEST(DijkstraHeap, canDetectNonExistinWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
  { make_pair(1, 3) },
  { make_pair(3, 3) },
  { make_pair(-1, -1) } };
  int way = dijkstraHeap(g, 2, 1);

  EXPECT_EQ(way, 0);
}

TEST(DijkstraHeap, oneNode) {
  vector<vector<pair<int, int> > >g{ { make_pair(6, 2) } };

  int way = dijkstraHeap(g, 2, 1);

  EXPECT_EQ(way, 0);
}
