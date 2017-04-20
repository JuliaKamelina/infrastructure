#include <gtest/gtest.h>
#include "RBTree.h"
#include "Heap.h"
#include "PQueue.h"

#include <math.h>

using std::make_pair;

TEST(RBTREE, canFindExistingElement) {
  RBTree<int> rTree;

  CNode<int>* tree = rTree.insert(7);
  rTree.insert(5);
  rTree.insert(1);
  rTree.insert(9);
  rTree.insert(6);

  tree = rTree.find(5);

  EXPECT_EQ(tree->val, 5);
}

TEST(RBTREE, elementDoesntExist) {
  RBTree<int> rTree;

  rTree.insert(7);
  rTree.insert(5);
  rTree.insert(1);
  rTree.insert(9);
  rTree.insert(6);

  ASSERT_ANY_THROW(rTree.find(10));
}

TEST(RBTREE, canFindMin) {
  RBTree<int> rTree;
  rTree.insert(7);
  rTree.insert(5);
  rTree.insert(3);
  rTree.insert(4);
  rTree.insert(2);
  rTree.insert(1);
  rTree.insert(0);
  rTree.insert(-1);

  EXPECT_EQ(-1, rTree.getMin()->val);
}

TEST(RBTREE, canInsert) {
  RBTree<int> rTree;
  CNode<int>* tree = rTree.insert(7);
  rTree.insert(5);
  rTree.insert(3);
  rTree.insert(4);
  rTree.insert(2);
  rTree.insert(1);
  rTree.insert(0);
  rTree.insert(-1);
  tree = rTree.getRoot();

  EXPECT_EQ(tree->val, 3);
  EXPECT_EQ(tree->color, 'B');
  EXPECT_EQ(tree->right->val, 5);
  EXPECT_EQ(tree->right->color, 'R');
  EXPECT_EQ(tree->right->left->val, 4);
  EXPECT_EQ(tree->right->left->color, 'B');
  EXPECT_EQ(tree->right->right->val, 7);
  EXPECT_EQ(tree->right->right->color, 'B');
  EXPECT_EQ(tree->left->val, 1);
  EXPECT_EQ(tree->left->color, 'R');
  EXPECT_EQ(tree->left->left->val, 0);
  EXPECT_EQ(tree->left->left->color, 'B');
  EXPECT_EQ(tree->left->right->val, 2);
  EXPECT_EQ(tree->left->right->color, 'B');
  EXPECT_EQ(tree->left->left->left->val, -1);
  EXPECT_EQ(tree->left->left->left->color, 'R');
}

TEST(RBTREE, hight) {
  RBTree<int> rTree;

  CNode<int>* tree = rTree.insert(7);
  rTree.insert(5);
  rTree.insert(3);
  rTree.insert(4);
  rTree.insert(2);
  rTree.insert(1);
  rTree.insert(0);
  rTree.insert(-1);

  tree = rTree.getRoot();

  std::queue<CNode<int>* > q;  //  cчитает высоту
  int h = 0;
  q.push(tree);

  while (!q.empty()) {
    int s = q.size();
    for (int i = 0; i < s; i++) {
      CNode<int>* node = q.front();
      q.pop();

      if (node->left != nullptr) q.push(node->left);
      if (node->right != nullptr) q.push(node->right);
    }
    h++;
  }

  EXPECT_EQ(h - 1, log(8) / log(2));
}

TEST(RBTREE, hightAfterDelete) {
  RBTree<int> rTree;

  CNode<int>* tree = rTree.insert(7);
  tree = rTree.insert(5);
  rTree.insert(1);
  rTree.insert(9);
  rTree.insert(6);

  rTree.deleteNode(tree);

  tree = rTree.getRoot();

  std::queue<CNode<int>* > q;  //  cчитает высоту
  int h = 0;
  q.push(tree);

  while (!q.empty()) {
    int s = q.size();
    for (int i = 0; i < s; i++) {
      CNode<int>* node = q.front();
      q.pop();

      if (node->left != nullptr) q.push(node->left);
      if (node->right != nullptr) q.push(node->right);
    }
    h++;
  }

  EXPECT_EQ(h - 1, log(4) / log(2));
}

TEST(RBTREE, canDeleteRoot) {
  RBTree<int> rTree;

  CNode<int>* tree = rTree.insert(7);
  tree = rTree.insert(5);
  rTree.insert(1);
  rTree.insert(9);
  rTree.insert(6);

  rTree.deleteNode(tree);

  tree = rTree.getRoot();

  EXPECT_EQ(tree->val, 6);
  EXPECT_EQ(tree->color, 'B');
  EXPECT_EQ(tree->left->val, 1);
  EXPECT_EQ(tree->left->color, 'B');
  EXPECT_EQ(tree->right->val, 7);
  EXPECT_EQ(tree->right->color, 'B');
  EXPECT_EQ(tree->right->right->val, 9);
  EXPECT_EQ(tree->right->right->color, 'R');
}

TEST(RBTREE, canDeleteLeaf) {
  RBTree<int> rTree;

  CNode<int>* tree = rTree.insert(7);
  rTree.insert(5);
  rTree.insert(1);
  tree = rTree.insert(9);
  rTree.insert(6);

  rTree.deleteNode(tree);

  tree = rTree.getRoot();

  EXPECT_EQ(tree->val, 5);
  EXPECT_EQ(tree->color, 'B');
  EXPECT_EQ(tree->left->val, 1);
  EXPECT_EQ(tree->left->color, 'B');
  EXPECT_EQ(tree->right->val, 7);
  EXPECT_EQ(tree->right->color, 'B');
  EXPECT_EQ(tree->right->left->val, 6);
  EXPECT_EQ(tree->right->left->color, 'R');
}

TEST(RBTREE, canDeleteTwoNodesTree) {
  RBTree<int> rTree;

  CNode<int>* tree = rTree.insert(7);
  rTree.insert(5);

  rTree.deleteNode(tree);

  EXPECT_EQ(rTree.getRoot()->val, 5);
  EXPECT_EQ(rTree.getRoot()->color, 'B');
}

TEST(RBTREE, canDeleteOnlyRoot) {
  RBTree<int> rTree;

  CNode<int>* tree = rTree.insert(7);

  rTree.deleteNode(tree);

  EXPECT_EQ(rTree.getRoot(), nullptr);
}

TEST(HEAP, canInsert) {
  DHeap<int> h;

  int a[4] = {1, 0, 7, 4};

  for (int i = 0; i < 4; i++) {
    int j = h.insert(a[i]);
    EXPECT_EQ(h[j], a[i]);
  }
}

TEST(HEAP, minOnTop) {
  DHeap<int> h;

  int a[4] = { 1, 0, 7, 4 };

  for (int i = 0; i < 4; i++) {
    h.insert(a[i]);
  }

  EXPECT_EQ(h[0], a[1]);
}

TEST(HEAP, canDelete) {
  DHeap<int> h;

  int a[4] = { 1, 0, 7, 4 };

  for (int i = 0; i < 4; i++) {
    h.insert(a[i]);
  }

    int b = h[0];
    h.deleteNode(0);
    EXPECT_FALSE(b == h[0]);
}

TEST(PQUEUETREE, canGetMin) {
  PQueueTree<int> q;

  q.push(19);
  q.push(2);
  q.push(3);
  q.push(1);

  EXPECT_EQ(q.min(), 1);
}

TEST(PQUEUETREE, canDelMin) {
  PQueueTree<int> q;

  q.push(19);
  q.push(2);
  q.push(3);
  q.push(1);

  q.deleteMin();

  EXPECT_EQ(q.min(), 2);
}

TEST(PQUEUEHEAP, canGetMin) {
  PQueueHeap<int> q;

  q.push(19);
  q.push(2);
  q.push(3);
  q.push(1);

  EXPECT_EQ(q.min(), 1);
}

TEST(PQUEUEHEAP, canDelMin) {
  PQueueHeap<int> q;

  q.push(19);
  q.push(2);
  q.push(3);
  q.push(1);

  q.deleteMin();

  EXPECT_EQ(q.min(), 2);
}

TEST(DijkstraTree, canFindWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
  { make_pair(1, 3), make_pair(4, 0) },
  { make_pair(3, 3), make_pair(6, 0) },
  { make_pair(1, 1), make_pair(3, 2) } };
  vector<int> way = dijkstraTree(g, 0, 3);

  EXPECT_EQ(way[3], 5);
}

TEST(DijkstraTree, canFindMinWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
                                           { make_pair(1, 3) },
                                           { make_pair(3, 3), make_pair(2, 4) },
                                           { make_pair(1, 5) },
                                           { make_pair(1, 5), make_pair(4, 6) },
                                           { make_pair(2, 6) },
                                           { make_pair(-1, -1) } };
  vector<int> way = dijkstraTree(g, 0, 6);

  EXPECT_EQ(way[6], 8);
}

TEST(DijkstraTree, canFindMinWay2) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
                                           { make_pair(1, 3) },
                                           { make_pair(3, 3), make_pair(2, 4) },
                                           { make_pair(1, 5) },
                                           { make_pair(-1, -1) },
                                           { make_pair(2, 6) },
                                           { make_pair(-1, -1) } };
  vector<int> way = dijkstraTree(g, 0, 6);

  EXPECT_EQ(way[6], 8);
}

TEST(DijkstraTree, canDetectNonExistinWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
                                           { make_pair(1, 3) },
                                           { make_pair(3, 3) },
                                           { make_pair(-1, -1) } };
  vector<int> way = dijkstraTree(g, 2, 1);

  EXPECT_EQ(way[1], 1000000000);
}

TEST(DijkstraTree, oneNode) {
  vector<vector<pair<int, int> > >g{{ make_pair(6, 0) }};

  ASSERT_ANY_THROW(dijkstraTree(g, 0, 1));
}

TEST(DijkstraTree, leafs) {
  vector<vector<pair<int, int> > > g = { { make_pair(1, 1), make_pair(1, 3) },
  { make_pair(2, 4), make_pair(1, 2) },
  { make_pair(5, 5) },
  { make_pair(-1, -1) },
  { make_pair(-1, -1) },
  { make_pair(-1, -1) } };

  vector<int> way = dijkstraTree(g, 0, 5);

  EXPECT_EQ(way[5], 7);
}

TEST(DijkstraHeap, canFindWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
  { make_pair(1, 3), make_pair(4, 0) },
  { make_pair(3, 3), make_pair(6, 0) },
  { make_pair(1, 1), make_pair(3, 2) } };
  vector<int> way = dijkstraHeap(g, 0, 3);

  EXPECT_EQ(way[3], 5);
}

TEST(DijkstraHeap, canFindMinWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
  { make_pair(1, 3) },
  { make_pair(3, 3), make_pair(2, 4) },
  { make_pair(1, 5) },
  { make_pair(1, 5), make_pair(4, 6) },
  { make_pair(2, 6) },
  { make_pair(-1, -1) } };
  vector<int> way = dijkstraHeap(g, 2, 6);

  EXPECT_EQ(way[6], 5);
}

TEST(DijkstraHeap, canFindMinWay2) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
  { make_pair(1, 3) },
  { make_pair(3, 3), make_pair(2, 4) },
  { make_pair(1, 5) },
  { make_pair(-1, -1) },
  { make_pair(2, 6) },
  { make_pair(-1, -1) } };
  vector<int> way = dijkstraHeap(g, 0, 6);

  EXPECT_EQ(way[6], 8);
}

TEST(DijkstraHeap, canDetectNonExistinWay) {
  vector< vector< pair<int, int> > > g = { { make_pair(6, 2), make_pair(4, 1) },
  { make_pair(1, 3) },
  { make_pair(3, 3) },
  { make_pair(-1, -1) } };
  vector<int> way = dijkstraHeap(g, 2, 1);

  EXPECT_EQ(way[1], 1000000000);
}

TEST(DijkstraHeap, oneNode) {
  vector<vector<pair<int, int> > > g = { { make_pair(6, 0) } };

  ASSERT_ANY_THROW(dijkstraHeap(g, 0, 1));
}

TEST(DijkstraHeap, leafs) {
  vector<vector<pair<int, int> > > g = {{make_pair(1, 1), make_pair(1, 3)},
                                        {make_pair(2, 4), make_pair(1, 2)},
                                        {make_pair(5, 5)},
                                        {make_pair(-1, -1)},
                                        {make_pair(-1, -1)},
                                        {make_pair(-1, -1)}};

  vector<int> way = dijkstraHeap(g, 0, 5);

  EXPECT_EQ(way[5], 7);
}
