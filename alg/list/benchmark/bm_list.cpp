/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include <benchmark/benchmark.h>
#include <linked_list_string.h>

static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state) {
    std::string empty_string;
  }
}
BENCHMARK(BM_StringCreation);

BENCHMARK_MAIN();