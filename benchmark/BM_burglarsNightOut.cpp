#include <benchmark/benchmark.h>

#include "burglarsNightOut.hpp"

const BurglarsNightOut::RealSequence costs = {-4.03, -1.50, 2.50, 4.36, 0.14, -9.55, 7.01, 0.53, 4.23, -9.21};

static void BM_burglarsNightOut_naive(benchmark::State& state) {
  for (auto _ : state) {
      BurglarsNightOut::NaiveAlgorithm::solve(costs);
  }
}
BENCHMARK(BM_burglarsNightOut_naive);

static void BM_burglarsNightOut_dynamicProgramming(benchmark::State& state) {
  for (auto _ : state) {
      BurglarsNightOut::DynamicProgrammingAlgorithm::solve(costs);
  }
}
BENCHMARK(BM_burglarsNightOut_dynamicProgramming);

BENCHMARK_MAIN();
