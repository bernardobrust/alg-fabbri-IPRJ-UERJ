/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include "graph.h"
#include <gtest/gtest.h>
#include <queue>
#include <set>
#include <vector>

//--- Helpers & Tests for standard BFS ---

u_graph4 *
create_node (const char *data)
{
  u_graph4 *node = new u_graph4 (data);
  for (int i = 0; i < 4; ++i)
    {
      node->directions[i] = nullptr;
    }
  node->visited = false;
  return node;
}

void
delete_graph (u_graph4 *root)
{
  if (!root)
    return;
  std::set<u_graph4 *> nodes;
  std::queue<u_graph4 *> q;
  if (root)
    {
      q.push (root);
      nodes.insert (root);
    }
  while (!q.empty ())
    {
      u_graph4 *curr = q.front ();
      q.pop ();
      for (int i = 0; i < 4; ++i)
        {
          if (curr->directions[i]
              && nodes.find (curr->directions[i]) == nodes.end ())
            {
              q.push (curr->directions[i]);
              nodes.insert (curr->directions[i]);
            }
        }
    }
  for (auto node : nodes)
    {
      delete node;
    }
}

void
assert_path_eq (const std::vector<u_graph4 *> &path,
                const std::vector<const char *> &expected)
{
  ASSERT_EQ (path.size (), expected.size ());
  for (size_t i = 0; i < path.size (); ++i)
    {
      EXPECT_STREQ (path[i]->data, expected[i]);
    }
}

TEST (GraphBfsPathTest, TargetIsRoot)
{
  u_graph4 *a = create_node ("A");
  std::vector<u_graph4 *> path;
  unsigned int length = bfs (a, "A", path);
  EXPECT_EQ (length, 1);
  assert_path_eq (path, { "A" });
  delete_graph (a);
}

TEST (GraphBfsPathTest, SimpleLinearPath)
{
  u_graph4 *a = create_node ("A");
  u_graph4 *b = create_node ("B");
  u_graph4 *c = create_node ("C");
  a->directions[0] = b;
  b->directions[0] = c;
  std::vector<u_graph4 *> path;
  unsigned int length = bfs (a, "C", path);
  EXPECT_EQ (length, 3);
  assert_path_eq (path, { "A", "B", "C" });
  delete_graph (a);
}

TEST (GraphBfsPathTest, ChoosesShortestPath)
{
  u_graph4 *a = create_node ("A");
  u_graph4 *b = create_node ("B");
  u_graph4 *c = create_node ("C"); // Target
  a->directions[0] = b;
  b->directions[0] = c; // Long path: A->B->C
  a->directions[1] = c; // Short path: A->C
  std::vector<u_graph4 *> path;
  unsigned int length = bfs (a, "C", path);
  EXPECT_EQ (length, 2);
  assert_path_eq (path, { "A", "C" });
  delete_graph (a);
}

TEST (GraphBfsPathTest, UnreachableTarget)
{
  u_graph4 *a = create_node ("A");
  std::vector<u_graph4 *> path;
  unsigned int length = bfs (a, "C", path);
  EXPECT_EQ (length, 0);
  EXPECT_TRUE (path.empty ());
  delete_graph (a);
}

TEST (GraphBfsPathTest, HandlesCycles)
{
  u_graph4 *a = create_node ("A");
  u_graph4 *b = create_node ("B");
  u_graph4 *c = create_node ("C");
  u_graph4 *d = create_node ("D");
  a->directions[0] = b;
  b->directions[1] = d; // Path to exit
  b->directions[0] = c;
  c->directions[0] = a; // Cycle
  std::vector<u_graph4 *> path;
  unsigned int length = bfs (a, "D", path);
  EXPECT_EQ (length, 3);
  assert_path_eq (path, { "A", "B", "D" });
  delete_graph (a);
}

//--- Helpers & Tests for Hyper BFS ---

hyper_u_graph *
hyper_create_node (const char *data)
{
  hyper_u_graph *node = new hyper_u_graph (data);
  for (int i = 0; i < 4; ++i)
    {
      node->directions[i] = nullptr;
    }
  node->visited = false;
  node->parent = nullptr;
  return node;
}

void
hyper_delete_graph (hyper_u_graph *root)
{
  if (!root)
    return;
  std::set<hyper_u_graph *> nodes;
  std::queue<hyper_u_graph *> q;
  if (root)
    {
      q.push (root);
      nodes.insert (root);
    }
  while (!q.empty ())
    {
      hyper_u_graph *curr = q.front ();
      q.pop ();
      for (int i = 0; i < 4; ++i)
        {
          if (curr->directions[i]
              && nodes.find (curr->directions[i]) == nodes.end ())
            {
              q.push (curr->directions[i]);
              nodes.insert (curr->directions[i]);
            }
        }
    }
  for (auto node : nodes)
    {
      delete node;
    }
}

void
hyper_assert_path_eq (const std::vector<hyper_u_graph *> &path,
                      const std::vector<const char *> &expected)
{
  ASSERT_EQ (path.size (), expected.size ());
  for (size_t i = 0; i < path.size (); ++i)
    {
      EXPECT_STREQ (path[i]->data, expected[i]);
    }
}

TEST (HyperGraphBfsPathTest, TargetIsRoot)
{
  hyper_u_graph *a = hyper_create_node ("A");
  std::vector<hyper_u_graph *> path;
  unsigned int length = hyper_bfs (a, "A", path);
  EXPECT_EQ (length, 1);
  hyper_assert_path_eq (path, { "A" });
  hyper_delete_graph (a);
}

TEST (HyperGraphBfsPathTest, SimpleLinearPath)
{
  hyper_u_graph *a = hyper_create_node ("A");
  hyper_u_graph *b = hyper_create_node ("B");
  hyper_u_graph *c = hyper_create_node ("C");
  a->directions[0] = b;
  b->directions[0] = c;
  std::vector<hyper_u_graph *> path;
  unsigned int length = hyper_bfs (a, "C", path);
  EXPECT_EQ (length, 3);
  hyper_assert_path_eq (path, { "A", "B", "C" });
  hyper_delete_graph (a);
}

TEST (HyperGraphBfsPathTest, ChoosesShortestPath)
{
  hyper_u_graph *a = hyper_create_node ("A");
  hyper_u_graph *b = hyper_create_node ("B");
  hyper_u_graph *c = hyper_create_node ("C");
  a->directions[0] = b;
  b->directions[0] = c; // Long path: A->B->C
  a->directions[1] = c; // Short path: A->C
  std::vector<hyper_u_graph *> path;
  unsigned int length = hyper_bfs (a, "C", path);
  EXPECT_EQ (length, 2);
  hyper_assert_path_eq (path, { "A", "C" });
  hyper_delete_graph (a);
}

TEST (HyperGraphBfsPathTest, UnreachableTarget)
{
  hyper_u_graph *a = hyper_create_node ("A");
  std::vector<hyper_u_graph *> path;
  unsigned int length = hyper_bfs (a, "C", path);
  EXPECT_EQ (length, 0);
  EXPECT_TRUE (path.empty ());
  hyper_delete_graph (a);
}

TEST (HyperGraphBfsPathTest, HandlesCycles)
{
  hyper_u_graph *a = hyper_create_node ("A");
  hyper_u_graph *b = hyper_create_node ("B");
  hyper_u_graph *c = hyper_create_node ("C");
  hyper_u_graph *d = hyper_create_node ("D");
  a->directions[0] = b;
  b->directions[1] = d; // Path to exit
  b->directions[0] = c;
  c->directions[0] = a; // Cycle
  std::vector<hyper_u_graph *> path;
  unsigned int length = hyper_bfs (a, "D", path);
  EXPECT_EQ (length, 3);
  hyper_assert_path_eq (path, { "A", "B", "D" });
  hyper_delete_graph (a);
}
