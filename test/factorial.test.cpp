#include <catch2/catch_test_macros.hpp>

#include "factorial.hpp"
#include <iostream>

void runTest(FactorialFunction f) {
    REQUIRE(f(1) == 1lu);
    REQUIRE(f(2) == 2lu);
    REQUIRE(f(3) == 6lu);
    REQUIRE(f(10) == 3628800lu);
    REQUIRE(f(20) == 2432902008176640000lu);
    return;
}

TEST_CASE("Basic values", "[factorial]") {
    SECTION("naive") {
        runTest(factorial_naive);
    }
    SECTION("factorial constexpr") {
        runTest(factorial);
    }
    SECTION("memoization") {
        runTest(factorial_memoization);
    }
    SECTION("memoization class") {
        auto factorialMemoization = FactorialMemoization{};
        runTest(factorialMemoization);
    }
}
