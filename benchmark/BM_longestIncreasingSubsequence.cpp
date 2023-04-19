#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "longestIncreasingSubsequence.hpp"

const LongestIncreasingSubsequence::Sequence sequence = { 10, 3, 9, 4, 7, 1, 9 };

const LongestIncreasingSubsequence::Sequence sequenceAlgorithms = { 17, 46, 3, 22, 10, 35, 28, 21, 13, 19, 27, 8, 12, 25, 18 };

TEST_CASE("longestIncreasingSubsequence Benchmark", "[benchmark][longestIncreasingSubsequence]") {

    BENCHMARK("subsequenceGenerator") {
        return LongestIncreasingSubsequence::SubsequenceGenerator(sequence);
    };

    BENCHMARK("naive") {
        return LongestIncreasingSubsequence::NaiveAlgorithm(sequenceAlgorithms);
    };

    BENCHMARK("recursive") {
        return LongestIncreasingSubsequence::RecursiveAlgorithm(sequenceAlgorithms);
    };

    BENCHMARK("dynamic pprogramming") {
        return LongestIncreasingSubsequence::DynamicProgrammingAlgorithm(sequenceAlgorithms);
    };

    BENCHMARK("optimal") {
        return LongestIncreasingSubsequence::OptimalAlgorithm(sequenceAlgorithms);
    };
}
