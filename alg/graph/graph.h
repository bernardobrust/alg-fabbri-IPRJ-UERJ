#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

// Podemos armezenar um grafo como matriz ou como struct
// Grafo sem pesos
struct u_graph4
{
  const char *data{};
  bool visited{ false };

  u_graph4 *directions[4];

  u_graph4 (const char *data) : data (data) {}
};

#define HYPER_BFS_QUEUE_SIZE 8192

struct hyper_u_graph
{
  const char *data{};
  bool visited{ false };
  hyper_u_graph *parent{ nullptr };

  hyper_u_graph *directions[4];

  hyper_u_graph (const char *data) : data (data) {}
};

// Retornar o caminho como vector só pra facilidade de testar
unsigned int bfs (u_graph4 *root, const char *target,
                  std::vector<u_graph4 *> &path);

// Versão otimizada do bfs
unsigned int hyper_bfs (hyper_u_graph *root, const char *target,
                        std::vector<hyper_u_graph *> &path);

#endif // GRAPH_H
