#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "burglarsNightOut.hpp"

const BurglarsNightOut::RealSequence costs = { -4.03, -1.50, 2.50, 4.36, 0.14, -9.55, 7.01, 0.53, 4.23, -9.21 };

TEST_CASE("BurglarsNightOut Benchmark", "[benchmark][burglarsNightOut]") {

    BENCHMARK("naive") {
        return BurglarsNightOut::NaiveAlgorithm::solve(costs);
    };

    BENCHMARK("dynamic programming") {
        return BurglarsNightOut::DynamicProgrammingAlgorithm::solve(costs);
    };
}
