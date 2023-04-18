#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "stairwayToHeaven2.hpp"

using namespace StairwayToHeaven2;

const Size number_of_steps = 7;
const Size step_limit = 3;
const Fees fees = {7, 3, 6, 7, 1, 2, 5};

TEST_CASE("stairwayToHeaven2 Benchmark", "[benchmark][stairwayToHeaven2]") {

    BENCHMARK("stairwayToHeaven2_naive") {
        const NaiveAlgorithm algorithm;
        return algorithm.solve(number_of_steps, step_limit, fees);
    };

    BENCHMARK("stairwayToHeaven2_dynamic_programming") {
        const DynamicProgrammingAlgorithm algorithm;
        return algorithm.solve(number_of_steps, step_limit, fees);
    };

}
