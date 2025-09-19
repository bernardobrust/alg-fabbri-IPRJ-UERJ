/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#ifndef TREE_H
#define TREE_H

struct tree
{
  char *data;

  // Nodes
  tree *left;
  tree *mid;
  tree *right;
};

tree *plant_tree (char *data);
int sumRec (tree *root, int acc);

#endif // TREE_H
