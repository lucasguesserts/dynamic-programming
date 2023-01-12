#include <benchmark/benchmark.h>

#include "sumOfTheRange.hpp"

const std::vector<double> values = {1, -2, 3, 10, -8, 0};
const std::vector<Query> queries = {
    {0, 2},
    {1, 4},
    {3, 3}
};

static void BM_sumOfTheRange(benchmark::State& state) {
  for (auto _ : state) {
    const Naive solver(values);
    const auto answers = solver(queries);
  }
}
BENCHMARK(BM_sumOfTheRange);

BENCHMARK_MAIN();
