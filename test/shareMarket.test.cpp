#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <initializer_list>

#include "shareMarket.hpp"

using namespace Catch::literals;

TEST_CASE("shareMarket", "[shareMarket]") {
    SECTION("base cases") {
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
    SECTION("zero cases", "[shareMarket]") {
        SECTION("example 1") {
            const std::initializer_list<double> prices = {5, 4, 3, 2, 1};
            const auto expected_value = 0.0_a;
            CHECK(shareMarket(prices) == expected_value);
        }
    }
    SECTION("maximum cases", "[shareMarket]") {
        SECTION("example 1") {
            const std::initializer_list<double> prices = {0, 1, 2, 3, 4, 5};
            const auto expected_value = 5.0_a;
            CHECK(shareMarket(prices) == expected_value);
        }
    }
}

TEST_CASE("shareMarketSimple", "[shareMarket]") {
    SECTION("base cases") {
        SECTION("example 1") {
            const std::initializer_list<double> prices = {8, 1, 2, 4, 6, 3};
            const auto expected_value = 5.0_a;
            CHECK(shareMarketSimple(prices) == expected_value);
        }
        SECTION("example 2") {
            const std::initializer_list<double> prices = {10, 18, 26, 31, 4, 54, 70};
            const auto expected_value = 87.0_a;
            CHECK(shareMarketSimple(prices) == expected_value);
        }
        SECTION("example 3") {
            const std::initializer_list<double> prices = {1, 2, 3, 2, 3, 2, 1, 0, 1, 2, 3, 4};
            const auto expected_value = 7.0_a;
            CHECK(shareMarketSimple(prices) == expected_value);
        }
    }
    SECTION("zero cases", "[shareMarketSimple]") {
        SECTION("example 1") {
            const std::initializer_list<double> prices = {5, 4, 3, 2, 1};
            const auto expected_value = 0.0_a;
            CHECK(shareMarketSimple(prices) == expected_value);
        }
    }
    SECTION("maximum cases", "[shareMarketSimple]") {
        SECTION("example 1") {
            const std::initializer_list<double> prices = {0, 1, 2, 3, 4, 5};
            const auto expected_value = 5.0_a;
            CHECK(shareMarketSimple(prices) == expected_value);
        }
    }
}
