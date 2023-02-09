#include <benchmark/benchmark.h>

#include "longestIncreasingSubsequence.hpp"

const LongestIncreasingSubsequence::Sequence sequence = {10, 3, 9, 4, 7, 1, 9};

static void BM_longestIncreasingSubsequence_subsequenceGenerator(benchmark::State& state) {
  for (auto _ : state) {
      const LongestIncreasingSubsequence::SubsequenceGenerator gen(sequence);
  }
}
BENCHMARK(BM_longestIncreasingSubsequence_subsequenceGenerator);


const LongestIncreasingSubsequence::Sequence sequenceAlgorithms = {7, 2, 2, 9, 9, 1, 7, 10, 7, 1, 8, 7, 7, 3, 9};

static void BM_longestIncreasingSubsequence_naive(benchmark::State& state) {
  for (auto _ : state) {
      const LongestIncreasingSubsequence::NaiveAlgorithm solver(sequenceAlgorithms);
  }
}
BENCHMARK(BM_longestIncreasingSubsequence_naive);

static void BM_longestIncreasingSubsequence_recursive(benchmark::State& state) {
  for (auto _ : state) {
      const LongestIncreasingSubsequence::RecursiveAlgorithm solver(sequenceAlgorithms);
  }
}
BENCHMARK(BM_longestIncreasingSubsequence_recursive);

BENCHMARK_MAIN();
