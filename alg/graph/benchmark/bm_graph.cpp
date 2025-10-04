/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include "../graph.h"
#include <benchmark/benchmark.h>
#include <cstring>
#include <string>
#include <vector>

// --- Graph Creation Helpers for Benchmark ---

// Creates a grid of standard u_graph4 nodes
u_graph4 *
create_grid_graph (int width, int height, std::vector<u_graph4 *> &all_nodes)
{
  all_nodes.resize (width * height);
  for (int y = 0; y < height; ++y)
    {
      for (int x = 0; x < width; ++x)
        {
          std::string name = std::to_string (x) + "," + std::to_string (y);
          char *name_str = new char[name.length () + 1];
          strcpy (name_str, name.c_str ());

          u_graph4 *node = new u_graph4 (name_str);
          for (int i = 0; i < 4; ++i)
            node->directions[i] = nullptr;
          all_nodes[y * width + x] = node;
        }
    }

  for (int y = 0; y < height; ++y)
    {
      for (int x = 0; x < width; ++x)
        {
          u_graph4 *node = all_nodes[y * width + x];
          if (y > 0)
            node->directions[0] = all_nodes[(y - 1) * width + x]; // Up
          if (y < height - 1)
            node->directions[1] = all_nodes[(y + 1) * width + x]; // Down
          if (x > 0)
            node->directions[2] = all_nodes[y * width + (x - 1)]; // Left
          if (x < width - 1)
            node->directions[3] = all_nodes[y * width + (x + 1)]; // Right
        }
    }
  return all_nodes[0];
}

// Creates a grid of hyper_u_graph nodes
hyper_u_graph *
create_hyper_grid_graph (int width, int height,
                         std::vector<hyper_u_graph *> &all_nodes)
{
  all_nodes.resize (width * height);
  for (int y = 0; y < height; ++y)
    {
      for (int x = 0; x < width; ++x)
        {
          std::string name = std::to_string (x) + "," + std::to_string (y);
          char *name_str = new char[name.length () + 1];
          strcpy (name_str, name.c_str ());

          hyper_u_graph *node = new hyper_u_graph (name_str);
          for (int i = 0; i < 4; ++i)
            node->directions[i] = nullptr;
          all_nodes[y * width + x] = node;
        }
    }

  for (int y = 0; y < height; ++y)
    {
      for (int x = 0; x < width; ++x)
        {
          hyper_u_graph *node = all_nodes[y * width + x];
          if (y > 0)
            node->directions[0] = all_nodes[(y - 1) * width + x]; // Up
          if (y < height - 1)
            node->directions[1] = all_nodes[(y + 1) * width + x]; // Down
          if (x > 0)
            node->directions[2] = all_nodes[y * width + (x - 1)]; // Left
          if (x < width - 1)
            node->directions[3] = all_nodes[y * width + (x + 1)]; // Right
        }
    }
  return all_nodes[0];
}

// --- Benchmark Fixture ---

class BfsBenchmark : public benchmark::Fixture
{
public:
  u_graph4 *graph_root;
  hyper_u_graph *hyper_graph_root;
  std::vector<u_graph4 *> all_graph_nodes;
  std::vector<hyper_u_graph *> all_hyper_nodes;
  const char *target_label;

  void
  SetUp (const ::benchmark::State &state) override
  {
    int width = 50;
    int height = 50;
    graph_root = create_grid_graph (width, height, all_graph_nodes);
    hyper_graph_root
        = create_hyper_grid_graph (width, height, all_hyper_nodes);
    target_label = all_graph_nodes.back ()->data; // Target is bottom-right
  }

  void
  TearDown (const ::benchmark::State &state) override
  {
    for (auto node : all_graph_nodes)
      {
        delete[] node->data;
        delete node;
      }
    for (auto node : all_hyper_nodes)
      {
        delete[] node->data;
        delete node;
      }
  }
};

// --- Benchmark Cases ---

BENCHMARK_F (BfsBenchmark, BFS) (benchmark::State &st)
{
  for (auto _ : st)
    {
      std::vector<u_graph4 *> path;
      benchmark::DoNotOptimize (bfs (graph_root, target_label, path));
    }
}

BENCHMARK_F (BfsBenchmark, HyperBFS) (benchmark::State &st)
{
  for (auto _ : st)
    {
      std::vector<hyper_u_graph *> path;
      benchmark::DoNotOptimize (
          hyper_bfs (hyper_graph_root, target_label, path));
    }
}

BENCHMARK_MAIN ();
