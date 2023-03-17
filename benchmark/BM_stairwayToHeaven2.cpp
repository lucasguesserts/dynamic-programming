#include <benchmark/benchmark.h>

#include "stairwayToHeaven2.hpp"

using namespace StairwayToHeaven2;

const Size number_of_steps = 7;
const Size step_limit = 3;
const Fees fees = {7, 3, 6, 7, 1, 2, 5};

static void BM_stairwayToHeaven2_naive(benchmark::State& state) {
    for (auto _ : state) {
        const NaiveAlgorithm algorithm;
        algorithm.solve(number_of_steps, step_limit, fees);
    }
}
BENCHMARK(BM_stairwayToHeaven2_naive);

static void BM_stairwayToHeaven2_dynamic_programming(benchmark::State& state) {
    for (auto _ : state) {
        const DynamicProgrammingAlgorithm algorithm;
        algorithm.solve(number_of_steps, step_limit, fees);
    }
}
BENCHMARK(BM_stairwayToHeaven2_dynamic_programming);

BENCHMARK_MAIN();
