#include <benchmark/benchmark.h>

#include "longestIncreasingSubsequence.hpp"

const LongestIncreasingSubsequence::Sequence sequence = {10, 3, 9, 4, 7, 1, 9};

static void BM_subsequenceGenerator(benchmark::State& state) {
  for (auto _ : state) {
      const LongestIncreasingSubsequence::SubsequenceGenerator gen(sequence);
  }
}
BENCHMARK(BM_subsequenceGenerator);

BENCHMARK_MAIN();
