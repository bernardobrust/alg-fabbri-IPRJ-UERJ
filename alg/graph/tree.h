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

// Variable size tree
struct vs_tree
{
  char *data;

  // First node on a lower level
  vs_tree *fChild;

  // Next node on the same level
  vs_tree *nSibling;
};

tree *plant_tree (char *data);
vs_tree *create_vs_tree (char *data);
int sumRec (tree *root, int acc);
int sumRecVstree (vs_tree *root, int acc);

#endif // TREE_H
