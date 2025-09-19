/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include <benchmark/benchmark.h>
#include "graph.h"

static void BM_GraphAlgorithm(benchmark::State& state) {
  for (auto _ : state) {
    graph_function();
  }
}
BENCHMARK(BM_GraphAlgorithm);

BENCHMARK_MAIN();