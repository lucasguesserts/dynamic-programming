#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <initializer_list>

#include "shareMarket.hpp"

using namespace Catch::literals;

TEST_CASE("shareMarket", "[shareMarket]") {
    SECTION("example 1") {
        const std::initializer_list<double> prices = {8, 1, 2, 4, 6, 3};
        const auto expected_value = 5.0_a;
        CHECK(shareMarket(prices) == expected_value);
    }
    SECTION("example 2") {
        const std::initializer_list<double> prices = {10, 18, 26, 31, 4, 54, 70};
        const auto expected_value = 87.0_a;
        CHECK(shareMarket(prices) == expected_value);
    }
    SECTION("example 3") {
        const std::initializer_list<double> prices = {1, 2, 3, 2, 3, 2, 1, 0, 1, 2, 3, 4};
        const auto expected_value = 7.0_a;
        CHECK(shareMarket(prices) == expected_value);
    }
}
