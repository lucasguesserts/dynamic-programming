#include <catch2/catch_test_macros.hpp>

#include "factorial.hpp"

TEST_CASE( "compute factorials - naive", "[factorial]" ) {
    REQUIRE(factorial_naive(1) == 1);
    REQUIRE(factorial_naive(2) == 2);
    REQUIRE(factorial_naive(3) == 6);
    REQUIRE(factorial_naive(10) == 3628800);
}

TEST_CASE( "compute factorials - memoization", "[factorial]" ) {
    REQUIRE(factorial_memoization(1) == 1);
    REQUIRE(factorial_memoization(2) == 2);
    REQUIRE(factorial_memoization(3) == 6);
    REQUIRE(factorial_memoization(10) == 3628800);
}

TEST_CASE( "compute factorials", "[factorial]" ) {
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(10) == 3628800);
}

