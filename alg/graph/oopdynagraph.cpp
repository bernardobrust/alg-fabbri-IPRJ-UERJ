#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdlib.h>
#include <string_view>
#include <vector>

struct cons_t;
struct node_t;

struct cons_t
{
  cons_t (node_t *node, const size_t w, cons_t *next)
      : node (node), weight (w), next (next)
  {
  }
  cons_t () = default;
  ~cons_t () noexcept = default;

  node_t *node{ nullptr };
  size_t weight{ 0 };
  cons_t *next{ nullptr };
};

struct node_t
{
  node_t (std::string_view data) : data (data) {}
  node_t () = default;
  ~node_t ()
  {
    cons_t *c = this->conections;
    while (c)
      {
        cons_t *next = c->next;
        delete c;
        c = next;
      }
  }

  std::string_view data{ "" };
  cons_t *conections{ nullptr };
};

class Graph
{
private:
  node_t *nodes;

  auto
  insert (cons_t **con, node_t *no, const size_t w) noexcept -> void
  {
    cons_t *t = new cons_t (no, w, *con);
    *con = t;
  }

  auto
  remove_con (cons_t **con, const node_t *node) -> void
  {
    cons_t *l = *con;
    cons_t *prev = l;

    for (; l != nullptr && l->node != node; prev = l, l = l->next)
      ;
    if (!l)
      return;
    if (prev != l)
      prev->next = l->next;
    else
      *con = l->next;

    delete l;
  }

public:
  Graph (node_t *node) : nodes (node) {}
  ~Graph () {}

  auto
  connect (node_t *a, node_t *b, int w) noexcept -> void
  {
    insert (&a->conections, b, w);
    insert (&b->conections, a, w);
  }

  auto
  delete_node (node_t *node) -> void
  {
    cons_t *v = node->conections;
    while (v != nullptr)
      {
        remove_con (&(v->node->conections), node);
        cons_t *t = v;
        v = v->next;
        delete t;
      }
    node->conections = nullptr;
  }

  // External methods (set, get, print)
  auto
  set_nodes (node_t *node) noexcept -> void
  {
    nodes = node;
  }

  auto
  get_nodes () noexcept -> node_t *
  {
    return nodes;
  }

  auto
  print_graph () noexcept -> void
  {
    if (!nodes)
      return;

    std::vector<node_t *> to_visit;
    std::vector<node_t *> visited;

    to_visit.push_back (nodes);

    while (!to_visit.empty ())
      {
        node_t *current = to_visit.back ();
        to_visit.pop_back ();

        if (std::find (visited.begin (), visited.end (), current)
            != visited.end ())
          {
            continue;
          }

        visited.push_back (current);

        std::cout << "Node: " << current->data << " is connected to: ";
        cons_t *conn = current->conections;
        while (conn)
          {
            std::cout << "  - " << conn->node->data << " (weight "
                      << conn->weight << ")";
            to_visit.push_back (conn->node);
            conn = conn->next;
          }
        std::cout << std::endl;
      }
  }
};

auto
main (void) -> int
{
  node_t nodes[5];
  std::string_view names[5]
      = { "Petropolis", "Teresopolis", "Niteroi", "Rio", "Friburgo" };

  for (int i{ 0 }; i < 5; ++i)
    {
      nodes[i].data = names[i];
      nodes[i].conections = nullptr;
    }

  Graph g (nodes);

  g.connect (nodes + 0, nodes + 1, 50);
  g.connect (nodes + 0, nodes + 3, 65);
  g.connect (nodes + 1, nodes + 3, 100);
  g.connect (nodes + 1, nodes + 4, 65);
  g.connect (nodes + 2, nodes + 3, 15);
  g.connect (nodes + 2, nodes + 4, 120);
  g.connect (nodes + 3, nodes + 4, 140);

  size_t adj_mat[5][5] = {};
  for (int i = 0; i < 5; ++i)
    {
      for (cons_t *c = nodes[i].conections; c; c = c->next)
        {
          int j = c->node - nodes;
          adj_mat[i][j] = c->weight;
        }
    }

  g.print_graph ();
  std::cout << "\n";

  std::cout << "Adjacency Matrix:\n";
  for (int i = 0; i < 5; ++i)
    {
      for (int j = 0; j < 5; ++j)
        {
          std::cout << adj_mat[i][j] << "\t";
        }
      std::cout << "\n";
    }
}
