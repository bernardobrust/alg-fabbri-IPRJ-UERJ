/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include "../big_string.h"
#include <benchmark/benchmark.h>
#include <cstring>
#include <string>
#include <vector>
#include <random>

// --- BigString Creation Helpers for Benchmark ---

// Creates a BigString with a single node
BigString* create_big_string(const std::string& str) {
    return new BigString((char*)str.c_str());
}

// --- Benchmark Fixture ---

class BigStringBenchmark : public benchmark::Fixture {
public:
    BigString bs;
    std::string reference_str;
    std::mt19937 gen;

    BigStringBenchmark() : gen(0) {}

    auto generate_random_string(int max_len) {
        std::string s = "";
        int len = std::uniform_int_distribution<>(1, max_len)(gen);
        for (int i = 0; i < len; ++i) {
            s += (char)std::uniform_int_distribution<>('a', 'z')(gen);
        }
        return s;
    }

    void SetUp(const ::benchmark::State& state) override {
        std::string initial_str = generate_random_string(10);
        bs.insert(0, (char*)initial_str.c_str());
        reference_str += initial_str;
    }

    void TearDown(const ::benchmark::State& state) override {
    }
};

// --- Benchmark Cases ---

BENCHMARK_F(BigStringBenchmark, Insert)(benchmark::State& st) {
    for (auto _ : st) {
        std::string to_insert_str = generate_random_string(5);
        unsigned int insert_pos = 0;
        if (bs.get_size() > 0) {
            insert_pos = std::uniform_int_distribution<>(0, bs.get_size())(gen);
        }
        bs.insert(insert_pos, (char*)to_insert_str.c_str());
        reference_str.insert(insert_pos, to_insert_str);
    }
}

BENCHMARK_F(BigStringBenchmark, Concat)(benchmark::State& st) {
    for (auto _ : st) {
        std::string to_concat_str = generate_random_string(7);
        BigString to_concat_bs;
        to_concat_bs.insert(0, (char*)to_concat_str.c_str());

        bs.concat(to_concat_bs);
        reference_str += to_concat_str;
    }
}

BENCHMARK_F(BigStringBenchmark, InsertBigStringAt)(benchmark::State& st) {
    for (auto _ : st) {
        std::string to_insert_str = generate_random_string(5);
        BigString to_insert_bs;
        to_insert_bs.insert(0, (char*)to_insert_str.c_str());

        unsigned int insert_pos = 0;
        if (reference_str.length() > 0) {
            insert_pos = std::uniform_int_distribution<>(0, reference_str.length())(gen);
        }

        bs.insert_big_string_at(to_insert_bs, insert_pos);
        reference_str.insert(insert_pos, to_insert_str);
    }
}

BENCHMARK_F(BigStringBenchmark, OperatorOverload)(benchmark::State& st) {
    for (auto _ : st) {
        unsigned int index = 0;
        if (reference_str.length() > 0) {
            index = std::uniform_int_distribution<>(0, reference_str.length() - 1)(gen);
        }
        benchmark::DoNotOptimize(bs[index]);
    }
}

BENCHMARK_MAIN();
