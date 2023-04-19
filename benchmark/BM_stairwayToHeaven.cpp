#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "stairwayToHeaven.hpp"

const long unsigned PROBLEM_SIZE = 18;

TEST_CASE("stairwayToHeaven Benchmark", "[benchmark][stairwayToHeaven]") {

    BENCHMARK("stairwayToHeaven") {
        return stairwayToHeaven(PROBLEM_SIZE);
    };

    BENCHMARK("StairwayToHeaven") {
        StairwayToHeaven solver;
        return solver(PROBLEM_SIZE);
    };

    BENCHMARK("stairwayToHeaven_recursive") {
        return stairwayToHeaven_recursive(PROBLEM_SIZE);
    };

    BENCHMARK("stairwayToHeaven_sum") {
        return stairwayToHeaven(PROBLEM_SIZE);
    };
}
