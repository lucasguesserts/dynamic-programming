#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "numberSplitting.hpp"

const NumberSplitting::Natural n = 15;

TEST_CASE("numberSplitting Benchmark", "[benchmark][numberSplitting]") {

    BENCHMARK("naive") {
        NumberSplitting::NaiveAlgorithm algorithm;
        return algorithm.solve(n);
    };

    BENCHMARK("dynamic programming") {
        NumberSplitting::DynamicProgrammingAlgorithm algorithm;
        return algorithm.solve(n);
    };
}
