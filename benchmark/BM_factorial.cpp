#include <benchmark/benchmark.h>

#include "factorial.hpp"

const long unsigned N = 18;

static void BM_factorial(benchmark::State& state) {
  for (auto _ : state) {
      factorial(N);
  }
}
BENCHMARK(BM_factorial);

static void BM_factorial_memoization(benchmark::State& state) {
  for (auto _ : state) {
      factorial_memoization(N);
  }
}
BENCHMARK(BM_factorial_memoization);

static void BM_factorial_naive(benchmark::State& state) {
  for (auto _ : state) {
      factorial_naive(N);
  }
}
BENCHMARK(BM_factorial_naive);

BENCHMARK_MAIN();
