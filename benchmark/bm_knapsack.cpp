#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include <memory>

#include "knapsack.hpp"

using namespace knapsack;

const auto values = ValueVector{360, 83, 59, 130, 431, 67, 230, 52, 93, 125, 670, 892, 600, 38, 48, 147};
const auto weights = WeightVector{7, 0, 30, 22, 80, 94, 11, 81, 70, 64, 59, 18, 0, 36, 3, 8};
const auto capacity = Weight{200};
const auto instance = Instance{values, weights, capacity};

TEST_CASE("Knapsack Benchmark", "[benchmark][knapsack]") {
    BENCHMARK("naive") {
        auto algorithm = std::unique_ptr<Algorithm>(std::make_unique<Naive>(instance));
        return algorithm->get_value();
    };
    BENCHMARK("recursion") {
        auto algorithm = std::unique_ptr<Algorithm>(std::make_unique<Recursion>(instance));
        return algorithm->get_value();
    };
    BENCHMARK("dynamic programming") {
        auto algorithm = std::unique_ptr<Algorithm>(std::make_unique<DynamicProgramming>(instance));
        return algorithm->get_value();
    };
}
