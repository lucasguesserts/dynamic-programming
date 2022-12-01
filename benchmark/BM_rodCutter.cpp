#include <benchmark/benchmark.h>

#include "rodCutter.hpp"

const std::initializer_list<double> pricesOfRodPieces = {2, 4, 7, 8};

static void BM_rodCutter(benchmark::State& state) {
  for (auto _ : state) {
    const auto problem = RodCutter::Problem(pricesOfRodPieces);
    auto solver = RodCutter::Solver(problem);
    solver(4);
  }
}
BENCHMARK(BM_rodCutter);

BENCHMARK_MAIN();
