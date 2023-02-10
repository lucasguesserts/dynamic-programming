#include <benchmark/benchmark.h>

#include "longestIncreasingSubsequence.hpp"

const LongestIncreasingSubsequence::Sequence sequence = {10, 3, 9, 4, 7, 1, 9};

static void BM_longestIncreasingSubsequence_subsequenceGenerator(benchmark::State& state) {
  for (auto _ : state) {
      const LongestIncreasingSubsequence::SubsequenceGenerator gen(sequence);
  }
}
BENCHMARK(BM_longestIncreasingSubsequence_subsequenceGenerator);


const LongestIncreasingSubsequence::Sequence sequenceAlgorithms = {17, 46, 3, 22, 10, 35, 28, 21, 13, 19, 27, 8, 12, 25, 18};

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

static void BM_longestIncreasingSubsequence_dynamicProgramming(benchmark::State& state) {
  for (auto _ : state) {
      const LongestIncreasingSubsequence::DynamicProgrammingAlgorithm solver(sequenceAlgorithms);
  }
}
BENCHMARK(BM_longestIncreasingSubsequence_dynamicProgramming);

static void BM_longestIncreasingSubsequence_optimal(benchmark::State& state) {
  for (auto _ : state) {
      const LongestIncreasingSubsequence::OptimalAlgorithm solver(sequenceAlgorithms);
  }
}
BENCHMARK(BM_longestIncreasingSubsequence_optimal);

BENCHMARK_MAIN();
