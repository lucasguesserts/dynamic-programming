#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include <initializer_list>

#include "shareMarket.hpp"

const std::initializer_list<double> prices = { 1, 2, 3, 2, 3, 2, 1, 0, 1, 2, 3, 4 };

TEST_CASE("shareMarket Benchmark", "[benchmark][shareMarket]") {

    BENCHMARK("shareMarket") {
        return shareMarket(prices);
    };

    BENCHMARK("shareMarketSimple") {
        return shareMarketSimple(prices);
    };
}
