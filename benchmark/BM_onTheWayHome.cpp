#include <benchmark/benchmark.h>

#include <vector>

#include "onTheWayHome.hpp"

const std::vector<Position> problemInstances = {
    {0, 0},
    {1, 1},
    {2, 2},
    {0, 3},
    {3, 0},
    {0, 9},
    {9, 0},
    {3, 4},
    {5, 5},
    {5, 1},
    {1, 5},
    {12, 5},
    {5, 12},
};

static void BM_onTheWayHome_opt(benchmark::State& state) {
  for (auto _ : state) {
      for (const auto& instance: problemInstances) {
        onTheWayHome_memoization(instance);
      }
  }
}
BENCHMARK(BM_onTheWayHome_opt);

static void BM_onTheWayHome_class(benchmark::State& state) {
  for (auto _ : state) {
      for (const auto& instance: problemInstances) {
        OnTheWayHome::compute(instance);
      }
  }
}
BENCHMARK(BM_onTheWayHome_class);

static void BM_onTheWayHome_naive(benchmark::State& state) {
  for (auto _ : state) {
      for (const auto& instance: problemInstances) {
        onTheWayHome_naive(instance);
      }
  }
}
BENCHMARK(BM_onTheWayHome_naive);

BENCHMARK_MAIN();
