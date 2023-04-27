#include <catch2/catch_test_macros.hpp>

#include <memory>
#include <vector>

#include "knapsack.hpp"

using namespace knapsack;

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)

TEST_CASE("instance", "[knapsack]") {
    SECTION("error") {
        auto values = ValueVector{60, 100};
        auto weights = WeightVector{10};
        auto capacity = Weight{50};
        REQUIRE_THROWS(Instance{values, weights, capacity});
    }
}

struct Expected {
    Value value{0};
    Weight weight{0};
    ItemSet items{};
};

template <typename AlgorithmType>
void test_algorithm(const Instance & instance, const Expected & expected) {
    auto algorithm = std::unique_ptr<Algorithm>(std::make_unique<AlgorithmType>(instance));
    REQUIRE(algorithm->get_value() == expected.value);
    REQUIRE(algorithm->get_weight() == expected.weight);
    REQUIRE(algorithm->get_items() == expected.items);
}

TEST_CASE("case 1", "[knapsack]") {
    const auto values = ValueVector{60, 100, 120};
    const auto weights = WeightVector{10, 20, 30};
    const auto capacity = Weight{50};
    const auto instance = Instance{values, weights, capacity};
    const auto expected_value = Value{220};
    const auto expected_weight = Weight{50};
    const auto expected_items = ItemSet{1, 2};
    const auto expected = Expected{expected_value, expected_weight, expected_items};
    SECTION("naive") {
        test_algorithm<Naive>(instance, expected);
    }
    SECTION("recursion") {
        test_algorithm<Recursion>(instance, expected);
    }
    SECTION("dynamic programming") {
        test_algorithm<DynamicProgramming>(instance, expected);
    }
}

TEST_CASE("case 2", "[knapsack]") {
    const auto values = ValueVector{360, 83, 59, 130, 431};
    const auto weights = WeightVector{7, 0, 30, 22, 80};
    const auto capacity = Weight{52};
    const auto instance = Instance{values, weights, capacity};
    const auto expected_value = Value{573};
    const auto expected_weight = Weight{29};
    const auto expected_items = ItemSet{0, 1, 3};
    const auto expected = Expected{expected_value, expected_weight, expected_items};
    SECTION("naive") {
        test_algorithm<Naive>(instance, expected);
    }
    SECTION("recursion") {
        test_algorithm<Recursion>(instance, expected);
    }
    SECTION("dynamic programming") {
        test_algorithm<DynamicProgramming>(instance, expected);
    }
}

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
