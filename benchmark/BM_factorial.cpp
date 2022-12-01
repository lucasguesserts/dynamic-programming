#include <benchmark/benchmark.h>

#include "factorial.hpp"

#include <functional>

void runFactorial(std::function<long unsigned(long unsigned)> f) {
    const long int nMax = 18;
    for (long unsigned n = 0; n < nMax; ++n) {
        f(n);
    }
}

static void BM_factorial(benchmark::State& state) {
  for (auto _ : state) {
      runFactorial(factorial);
  }
}
BENCHMARK(BM_factorial);

static void BM_FactorialMemoization(benchmark::State& state) {
  for (auto _ : state) {
      FactorialMemoization factorialMemoization;
      runFactorial(factorialMemoization);
  }
}
BENCHMARK(BM_FactorialMemoization);

static void BM_factorial_memoization(benchmark::State& state) {
  for (auto _ : state) {
      runFactorial(factorial_memoization);
  }
}
BENCHMARK(BM_factorial_memoization);

static void BM_factorial_naive(benchmark::State& state) {
  for (auto _ : state) {
      runFactorial(factorial_naive);
  }
}
BENCHMARK(BM_factorial_naive);

BENCHMARK_MAIN();
