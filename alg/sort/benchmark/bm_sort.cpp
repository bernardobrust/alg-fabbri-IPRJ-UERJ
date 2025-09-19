/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include <benchmark/benchmark.h>
#include <sort.h>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

// Fills a vector with random strings.
static void fill_random_list(std::vector<std::string>& list, int size) {
    list.resize(size);
    if (size == 0) return;
    static std::mt19937 gen(42);
    std::uniform_int_distribution<> distrib(1, 10);

    for (int i = 0; i < size; ++i) {
        int len = distrib(gen);
        std::string s(len, ' ');
        for (int j = 0; j < len; ++j) {
            s[j] = 'a' + (gen() % 26);
        }
        list[i] = s;
    }
}

class sort_fixture : public benchmark::Fixture {
public:
  void SetUp(const ::benchmark::State& state) {
    int size = state.range(0);
    fill_random_list(string_list, size);
    char_list.resize(size);
    for(size_t i=0; i<string_list.size(); ++i) {
        char_list[i] = &string_list[i][0];
    }
  }

  std::vector<std::string> string_list;
  std::vector<char*> char_list;
};

BENCHMARK_DEFINE_F(sort_fixture, BM_simple_sort)(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    fill_random_list(string_list, state.range(0));
    for(size_t i=0; i<string_list.size(); ++i) {
        char_list[i] = &string_list[i][0];
    }
    state.ResumeTiming();
    simple_sort(char_list.data(), char_list.size());
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
}

BENCHMARK_DEFINE_F(sort_fixture, BM_fast_sort)(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    fill_random_list(string_list, state.range(0));
    for(size_t i=0; i<string_list.size(); ++i) {
        char_list[i] = &string_list[i][0];
    }
    state.ResumeTiming();
    fast_sort(char_list.data(), char_list.size());
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
}

BENCHMARK_REGISTER_F(sort_fixture, BM_simple_sort)->Arg(10);
BENCHMARK_REGISTER_F(sort_fixture, BM_simple_sort)->Arg(100);
BENCHMARK_REGISTER_F(sort_fixture, BM_simple_sort)->Arg(1000);
BENCHMARK_REGISTER_F(sort_fixture, BM_simple_sort)->Arg(10000);

BENCHMARK_REGISTER_F(sort_fixture, BM_fast_sort)->Arg(10);
BENCHMARK_REGISTER_F(sort_fixture, BM_fast_sort)->Arg(100);
BENCHMARK_REGISTER_F(sort_fixture, BM_fast_sort)->Arg(1000);
BENCHMARK_REGISTER_F(sort_fixture, BM_fast_sort)->Arg(10000);

BENCHMARK_MAIN();
