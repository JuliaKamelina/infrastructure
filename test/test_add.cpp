#include <gtest/gtest.h>
#include "constr.h"

TEST(Construct, canConstructTreeChot) {
  int arr[] = {0, 1, 2, 3, 4, 5};

  CNode* tree = construct(arr, 6);

  EXPECT_EQ(tree->val, 2);
  EXPECT_EQ(tree->left->val, 0);
  EXPECT_EQ(tree->left->right->val, 1);

  EXPECT_EQ(tree->right->val, 4);
  EXPECT_EQ(tree->right->left->val, 3);
  EXPECT_EQ(tree->right->right->val, 5);
}


TEST(Construct, canConstructTreeNeChot) {
  int arr[] = {0, 1, 2, 3, 4};

  CNode* tree = construct(arr, 5);

  EXPECT_EQ(tree->val, 2);
  EXPECT_EQ(tree->left->val, 0);
  EXPECT_EQ(tree->left->right->val, 1);

  EXPECT_EQ(tree->right->val, 3);
  EXPECT_EQ(tree->right->right->val, 4);
}

TEST(Construct, emptyArray) {
  int* arr = 0;
  CNode* tree = construct(arr, 0);

  EXPECT_EQ(tree, nullptr);
}
