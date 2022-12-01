#include <benchmark/benchmark.h>

#include "stairwayToHeaven.hpp"

const long unsigned PROBLEM_SIZE = 18;

static void BM_stairwayToHeaven(benchmark::State& state) {
  for (auto _ : state) {
      stairwayToHeaven(PROBLEM_SIZE);
  }
}
BENCHMARK(BM_stairwayToHeaven);

static void BM_StairwayToHeaven(benchmark::State& state) {
  for (auto _ : state) {
      StairwayToHeaven solver;
      solver(PROBLEM_SIZE);
  }
}
BENCHMARK(BM_StairwayToHeaven);

static void BM_stairwayToHeaven_recursive(benchmark::State& state) {
  for (auto _ : state) {
      stairwayToHeaven_recursive(PROBLEM_SIZE);
  }
}
BENCHMARK(BM_stairwayToHeaven_recursive);

static void BM_stairwayToHeaven_sum(benchmark::State& state) {
  for (auto _ : state) {
      stairwayToHeaven(PROBLEM_SIZE);
  }
}
BENCHMARK(BM_stairwayToHeaven_sum);

BENCHMARK_MAIN();
