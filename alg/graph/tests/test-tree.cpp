/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include "tree.h"
#include <gtest/gtest.h>

TEST (TreeTest, PlantTree)
{
  tree *root = plant_tree ((char *)"I am root!");
  root->mid = plant_tree ((char *)"Nice reference!");
  EXPECT_EQ (root->data, "I am root!");
  EXPECT_EQ (root->mid->data, "Nice reference!");
}

TEST (SumTests, Sum1)
{
  tree *root = plant_tree ((char *)"abc");
  EXPECT_EQ (sumRec (root, 0), 3);
}

TEST (SumTests, Sum2)
{
  tree *root = plant_tree ((char *)"abc");
  root->left = plant_tree ((char *)"def");
  root->mid = plant_tree ((char *)"def");
  root->right = plant_tree ((char *)"def");
  EXPECT_EQ (sumRec (root, 0), 12);
}

TEST (VSTreeSumTests, Sum3)
{
  vs_tree *root = create_vs_tree ((char *)"Root");
  root->fChild = create_vs_tree ((char *)"Level1-1");
  root->fChild->nSibling = create_vs_tree ((char *)"Level1-2");
  root->fChild->fChild = create_vs_tree ((char *)"level2-1");

  EXPECT_EQ (sumRecVstree (root, 0), 28);
}
