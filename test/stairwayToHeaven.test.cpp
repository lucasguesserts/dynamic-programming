#include <catch2/catch_test_macros.hpp>

#include "stairwayToHeaven.hpp"

TEST_CASE("stairwayToHeaven", "[stairwayToHeaven]") {
    REQUIRE(stairwayToHeaven(0) == 1);
    REQUIRE(stairwayToHeaven(1) == 1);
    REQUIRE(stairwayToHeaven(2) == 2);
    REQUIRE(stairwayToHeaven(3) == 3);
    REQUIRE(stairwayToHeaven(4) == 5);
    REQUIRE(stairwayToHeaven(5) == 8);
    REQUIRE(stairwayToHeaven(6) == 13);
}

TEST_CASE("StairwayToHeaven - class", "[stairwayToHeaven]") {
    StairwayToHeaven solver;
    REQUIRE(solver(0) == 1);
    REQUIRE(solver(1) == 1);
    REQUIRE(solver(2) == 2);
    REQUIRE(solver(3) == 3);
    REQUIRE(solver(4) == 5);
    REQUIRE(solver(5) == 8);
    REQUIRE(solver(6) == 13);
}

TEST_CASE("stairwayToHeaven_recursive", "[stairwayToHeaven_recursive]") {
    REQUIRE(stairwayToHeaven_recursive(0) == 1);
    REQUIRE(stairwayToHeaven_recursive(1) == 1);
    REQUIRE(stairwayToHeaven_recursive(2) == 2);
    REQUIRE(stairwayToHeaven_recursive(3) == 3);
    REQUIRE(stairwayToHeaven_recursive(4) == 5);
    REQUIRE(stairwayToHeaven_recursive(5) == 8);
    REQUIRE(stairwayToHeaven_recursive(6) == 13);
}

TEST_CASE("stairwayToHeaven_sum", "[stairwayToHeaven_sum]") {
    REQUIRE(stairwayToHeaven_sum(0) == 1);
    REQUIRE(stairwayToHeaven_sum(1) == 1);
    REQUIRE(stairwayToHeaven_sum(2) == 2);
    REQUIRE(stairwayToHeaven_sum(3) == 3);
    REQUIRE(stairwayToHeaven_sum(4) == 5);
    REQUIRE(stairwayToHeaven_sum(5) == 8);
    REQUIRE(stairwayToHeaven_sum(6) == 13);
}
