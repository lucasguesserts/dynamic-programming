#include <catch2/catch_test_macros.hpp>

#include <vector>
#include <memory>

#include "knapsack.hpp"

using namespace knapsack;

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)

TEST_CASE("instance", "[knapsack]") {
    SECTION("error") {
        auto values = std::vector<Value>{60, 100};
        auto weights = std::vector<Weight>{10};
        auto capacity = Weight{50};
        REQUIRE_THROWS(Instance{values, weights, capacity});
    }
}

TEST_CASE("knapsack", "[knapsack]") {
    SECTION("case 1") {
        auto values = std::vector<Value>{60, 100, 120};
        auto weights = std::vector<Weight>{10, 20, 30};
        auto capacity = Weight{50};
        auto instance = Instance{values, weights, capacity};
        auto algorithm = std::unique_ptr<Algorithm>(std::make_unique<Naive>(instance));
        auto expected_value = Value{220};
        auto expected_weight = Weight{50};
        auto expected_items = ItemSet{1, 2};
        REQUIRE(algorithm->get_value() == expected_value);
        REQUIRE(algorithm->get_weight() == expected_weight);
        REQUIRE(algorithm->get_items() == expected_items);
    }
    SECTION("case 2") {
        auto values = std::vector<Value>{360, 83, 59, 130, 431};
        auto weights = std::vector<Weight>{7, 0, 30, 22, 80};
        auto capacity = Weight{52};
        auto instance = Instance{values, weights, capacity};
        auto algorithm = std::unique_ptr<Algorithm>(std::make_unique<Naive>(instance));
        auto expected_value = Value{573};
        auto expected_weight = Weight{29};
        auto expected_items = ItemSet{0, 1, 3};
        REQUIRE(algorithm->get_value() == expected_value);
        REQUIRE(algorithm->get_weight() == expected_weight);
        REQUIRE(algorithm->get_items() == expected_items);
    }
}

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
