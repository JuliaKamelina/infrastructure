#include <gtest/gtest.h>
#include "tree.h"

TEST(Find, CanFindExistingValueR) {
  CNode* tree = new CNode(4);
  tree->left = new CNode(2);
  tree->right = new CNode(6);
  tree->right->left = new CNode(5);
  tree->right->right = new CNode(7);
  tree->left->left = new CNode(1);
  tree->left->right = new CNode(3);

  CNode** n = find(&tree, 5);

  ASSERT_EQ((*n)->val, 5);
}

TEST(Find, CanFindExistingValueL) {
  CNode* tree = new CNode(4);
  tree->left = new CNode(2);
  tree->right = new CNode(6);
  tree->right->left = new CNode(5);
  tree->right->right = new CNode(7);
  tree->left->left = new CNode(1);
  tree->left->right = new CNode(3);

  CNode** n = find(&tree, 3);

  ASSERT_EQ((*n)->val, 3);
}

TEST(Find, CantFindNonexistentValue) {
  CNode* tree = new CNode(4);
  tree->left = new CNode(2);
  tree->right = new CNode(6);
  tree->right->left = new CNode(5);
  tree->right->right = new CNode(7);
  tree->left->left = new CNode(1);
  tree->left->right = new CNode(3);

  CNode** n = find(&tree, 9);
  CNode* n1 = 0;
  ASSERT_EQ(*n, n1);
}

TEST(Find, FindDontDestroyTree) {
  CNode* tree = new CNode(4);
  tree->left = new CNode(2);
  tree->right = new CNode(6);
  tree->right->left = new CNode(5);
  tree->right->right = new CNode(7);
  tree->left->left = new CNode(1);
  tree->left->right = new CNode(3);

  find(&tree, 1);

  ASSERT_EQ(tree->val, 4);
  ASSERT_EQ(tree->left->val, 2);
  ASSERT_EQ(tree->right->val, 6);
  ASSERT_EQ(tree->right->left->val, 5);
  ASSERT_EQ(tree->right->right->val, 7);
  ASSERT_EQ(tree->left->left->val, 1);
  ASSERT_EQ(tree->left->right->val, 3);
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
