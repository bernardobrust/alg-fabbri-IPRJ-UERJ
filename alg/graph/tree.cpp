/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include "tree.h"
#include <cstdlib>
#include <cstring>

tree *
plant_tree (char *data)
{
  tree *root = (tree *)malloc (sizeof (tree));
  root->data = data;
  root->left = nullptr;
  root->mid = nullptr;
  root->right = nullptr;

  return root;
}

vs_tree *
create_vs_tree (char *data)
{
  vs_tree *new_node = (vs_tree *)malloc (sizeof (vs_tree));
  new_node->data = data;
  new_node->nSibling = nullptr;
  new_node->fChild = nullptr;

  return new_node;
}

int
sumRec (tree *root, int acc)
{
  if (!root)
    return acc;

  if (root->data)
    acc += strlen (root->data);

  acc = sumRec (root->left, acc);
  acc = sumRec (root->mid, acc);
  acc = sumRec (root->right, acc);

  return acc;
}

int
sumRecVstree (vs_tree *root, int acc)
{
  if (!root)
    return acc;

  if (root->data)
    acc += strlen (root->data);

  acc = sumRecVstree (root->nSibling, acc);
  acc = sumRecVstree (root->fChild, acc);

  return acc;
}
