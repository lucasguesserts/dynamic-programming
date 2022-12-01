#include <benchmark/benchmark.h>

#include <initializer_list>

#include "shareMarket.hpp"

const std::initializer_list<double> prices = {1, 2, 3, 2, 3, 2, 1, 0, 1, 2, 3, 4};

static void BM_shareMarket(benchmark::State& state) {
  for (auto _ : state) {
      shareMarket(prices);
  }
}
BENCHMARK(BM_shareMarket);

BENCHMARK_MAIN();
