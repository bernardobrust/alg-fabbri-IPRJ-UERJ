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
