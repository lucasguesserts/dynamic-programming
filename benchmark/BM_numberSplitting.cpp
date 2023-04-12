#include <benchmark/benchmark.h>

#include "numberSplitting.hpp"

const NumberSplitting::Natural n = 15;

static void BM_numberSplitting_naive(benchmark::State& state) {
    for (auto _ : state) {
        NumberSplitting::NaiveAlgorithm algorithm;
        algorithm.solve(n);
    }
}
BENCHMARK(BM_numberSplitting_naive);

static void BM_numberSplitting_dynamicProgramming(benchmark::State& state) {
    for (auto _ : state) {
        NumberSplitting::DynamicProgrammingAlgorithm algorithm;
        algorithm.solve(n);
    }
}
BENCHMARK(BM_numberSplitting_dynamicProgramming);

BENCHMARK_MAIN();
