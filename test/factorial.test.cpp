#include <catch2/catch_test_macros.hpp>

#include "factorial.hpp"
#include <iostream>

TEST_CASE("compute factorials - naive", "[factorial]") {
    REQUIRE(factorial_naive(1) == 1lu);
    REQUIRE(factorial_naive(2) == 2lu);
    REQUIRE(factorial_naive(3) == 6lu);
    REQUIRE(factorial_naive(10) == 3628800lu);
    REQUIRE(factorial_naive(20) == 2432902008176640000lu);
}

TEST_CASE("compute factorials - memoization - class", "[factorial]") {
    FactorialMemoization factorialMemoization;
    REQUIRE(factorialMemoization(1) == 1lu);
    REQUIRE(factorialMemoization(2) == 2lu);
    REQUIRE(factorialMemoization(3) == 6lu);
    REQUIRE(factorialMemoization(10) == 3628800lu);
    REQUIRE(factorialMemoization(20) == 2432902008176640000lu);
}

TEST_CASE("compute factorials - memoization", "[factorial]") {
    REQUIRE(factorial_memoization(1) == 1lu);
    REQUIRE(factorial_memoization(2) == 2lu);
    REQUIRE(factorial_memoization(3) == 6lu);
    REQUIRE(factorial_memoization(10) == 3628800lu);
    REQUIRE(factorial_memoization(20) == 2432902008176640000lu);
}

TEST_CASE("compute factorials", "[factorial]") {
    REQUIRE(factorial(1) == 1lu);
    REQUIRE(factorial(2) == 2lu);
    REQUIRE(factorial(3) == 6lu);
    REQUIRE(factorial(10) == 3628800lu);
    REQUIRE(factorial(20) == 2432902008176640000lu);
    REQUIRE_THROWS(factorial(21));
}
