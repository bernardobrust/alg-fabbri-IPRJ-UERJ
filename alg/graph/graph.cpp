#include "graph.h"
#include <cstring>
#include <map>
#include <queue>
#include <vector>

unsigned int
bfs (u_graph4 *root, const char *target, std::vector<u_graph4 *> &path)
{
  path.clear ();
  if (!root)
    return 0;

  std::map<u_graph4 *, u_graph4 *> parent_map;
  std::queue<u_graph4 *> q;
  std::vector<u_graph4 *> visited_nodes;

  q.push (root);
  root->visited = true;
  visited_nodes.push_back (root);

  u_graph4 *target_node = nullptr;

  while (!q.empty ())
    {
      u_graph4 *cur = q.front ();
      q.pop ();

      if (strcmp (cur->data, target) == 0)
        {
          target_node = cur;
          break;
        }

      for (int i = 0; i < 4; ++i)
        {
          u_graph4 *dir = cur->directions[i];
          if (dir && !dir->visited)
            {
              dir->visited = true;
              visited_nodes.push_back (dir);
              parent_map[dir] = cur;
              q.push (dir);
            }
        }
    }

  if (target_node)
    {
      u_graph4 *cur = target_node;
      while (cur != nullptr)
        {
          path.insert (path.begin (), cur);
          cur = parent_map.count (cur) ? parent_map[cur] : nullptr;
        }
    }

  // Cleanup
  for (u_graph4 *node : visited_nodes)
    {
      node->visited = false;
    }

  return path.size ();
}

unsigned int
hyper_bfs (hyper_u_graph *root, const char *target,
           std::vector<hyper_u_graph *> &path)
{
  path.clear ();
  if (!root)
    return 0;

  hyper_u_graph *queue[HYPER_BFS_QUEUE_SIZE];
  std::vector<hyper_u_graph *> visited_nodes;
  int head = 0;
  int tail = 0;

  root->visited = true;
  root->parent = nullptr;
  visited_nodes.push_back (root);

  queue[tail++] = root;

  hyper_u_graph *target_node = nullptr;
  bool overflow = false;

  while (head != tail)
    {
      hyper_u_graph *cur = queue[head];
      head = (head + 1) % HYPER_BFS_QUEUE_SIZE;

      if (strcmp (cur->data, target) == 0)
        {
          target_node = cur;
          break;
        }

      for (int i = 0; i < 4; ++i)
        {
          hyper_u_graph *dir = cur->directions[i];
          if (dir && !dir->visited)
            {
              dir->visited = true;
              dir->parent = cur;
              visited_nodes.push_back (dir);

              if (((tail + 1) % HYPER_BFS_QUEUE_SIZE) == head)
                {
                  overflow = true;
                  break;
                }
              queue[tail] = dir;
              tail = (tail + 1) % HYPER_BFS_QUEUE_SIZE;
            }
        }
      if (overflow)
        break;
    }

  if (target_node)
    {
      hyper_u_graph *cur = target_node;
      while (cur != nullptr)
        {
          path.insert (path.begin (), cur);
          cur = cur->parent;
        }
    }

  // Cleanup
  for (hyper_u_graph *node : visited_nodes)
    {
      node->visited = false;
      node->parent = nullptr;
    }

  return path.size ();
}
