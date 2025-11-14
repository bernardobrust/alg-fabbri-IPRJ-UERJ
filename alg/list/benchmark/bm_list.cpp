#include "big_string.h"
#include "big_string_array.h"
#include <benchmark/benchmark.h>
#include <cstring>
#include <string>
#include <vector>
#include <random>

// =============================================================================
// BigString Benchmarks
// =============================================================================

static void BM_BigString_Insert(benchmark::State& state) {
    std::mt19937 gen(0);
    auto generate_random_string = [&](int max_len) {
        std::string s = "";
        int len = std::uniform_int_distribution<>(1, max_len)(gen);
        for (int i = 0; i < len; ++i) {
            s += (char)std::uniform_int_distribution<>('a', 'z')(gen);
        }
        return s;
    };

    for (auto _ : state) {
        state.PauseTiming();
        BigString bs;
        state.ResumeTiming();

        for (int i = 0; i < state.range(0); ++i) {
            std::string to_insert = generate_random_string(5);
            bs.insert(0, (char*)to_insert.c_str());
        }
    }
}
BENCHMARK(BM_BigString_Insert)->Range(8, 8<<5);

static void BM_BigString_InsertBigStringAt(benchmark::State& state) {
    std::mt19937 gen(0);
    auto generate_random_string = [&](int max_len) {
        std::string s = "";
        int len = std::uniform_int_distribution<>(1, max_len)(gen);
        for (int i = 0; i < len; ++i) {
            s += (char)std::uniform_int_distribution<>('a', 'z')(gen);
        }
        return s;
    };

    for (auto _ : state) {
        state.PauseTiming();
        BigString bs;
        bs.insert(0, (char*)generate_random_string(1000).c_str());
        state.ResumeTiming();

        for (int i = 0; i < state.range(0); ++i) {
            std::string to_insert_str = generate_random_string(5);
            BigString to_insert_bs;
            to_insert_bs.insert(0, (char*)to_insert_str.c_str());
            unsigned int pos = std::uniform_int_distribution<>(0, bs.get_char_size())(gen);
            bs.insert_big_string_at(to_insert_bs, pos);
        }
    }
}
BENCHMARK(BM_BigString_InsertBigStringAt)->Range(8, 8<<5);

// =============================================================================
// BigStringArray Benchmarks
// =============================================================================

static void BM_BigStringArray_Insert(benchmark::State& state) {
    std::mt19937 gen(0);
    auto generate_random_string = [&](int max_len) {
        std::string s = "";
        int len = std::uniform_int_distribution<>(1, max_len)(gen);
        for (int i = 0; i < len; ++i) {
            s += (char)std::uniform_int_distribution<>('a', 'z')(gen);
        }
        return s;
    };

    for (auto _ : state) {
        state.PauseTiming();
        BigStringArray bsa;
        state.ResumeTiming();

        for (int i = 0; i < state.range(0); ++i) {
            std::string to_insert = generate_random_string(5);
            bsa.insert(0, (char*)to_insert.c_str());
        }
    }
}
BENCHMARK(BM_BigStringArray_Insert)->Range(8, 8<<5);

static void BM_BigStringArray_InsertBigStringAt_Optimized(benchmark::State& state) {
    std::mt19937 gen(0);
    auto generate_random_string = [&](int max_len) {
        std::string s = "";
        int len = std::uniform_int_distribution<>(1, max_len)(gen);
        for (int i = 0; i < len; ++i) {
            s += (char)std::uniform_int_distribution<>('a', 'z')(gen);
        }
        return s;
    };

    for (auto _ : state) {
        state.PauseTiming();
        BigStringArray bsa;
        bsa.insert(0, (char*)generate_random_string(20).c_str());
        state.ResumeTiming();

        for (int i = 0; i < state.range(0); ++i) {
            std::string to_insert_str = generate_random_string(5);
            BigStringArray to_insert_bsa;
            to_insert_bsa.insert(0, (char*)to_insert_str.c_str());
            unsigned int pos = std::uniform_int_distribution<>(0, bsa.get_char_size())(gen);
            bsa.insert_big_string_at(to_insert_bsa, pos);
        }
    }
}
BENCHMARK(BM_BigStringArray_InsertBigStringAt_Optimized)->Range(8, 8<<5);

BENCHMARK_MAIN();
