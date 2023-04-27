#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "burglars_night_out.hpp"
#include <memory>

const auto costs = BurglarsNightOut::RealSequence{-4.03, -1.50, 2.50, 4.36, 0.14, -9.55, 7.01, 0.53, 4.23, -9.21};

TEST_CASE("BurglarsNightOut Benchmark", "[benchmark][burglarsNightOut]") {
    auto naiveAlgorithm = std::unique_ptr<BurglarsNightOut::Algorithm>(std::make_unique<BurglarsNightOut::NaiveAlgorithm>());
    auto dynamicProgrammingAlgorithm = std::unique_ptr<BurglarsNightOut::Algorithm>(std::make_unique<BurglarsNightOut::DynamicProgrammingAlgorithm>());

    BENCHMARK("naive") {
        return naiveAlgorithm->solve(costs);
    };

    BENCHMARK("dynamic programming") {
        return dynamicProgrammingAlgorithm->solve(costs);
    };
}
