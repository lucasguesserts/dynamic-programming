#include <catch2/catch_test_macros.hpp>

#include "stairwayToHeaven.hpp"

TEST_CASE("stairwayToHeaven", "[stairwayToHeaven]") {
    REQUIRE(stairwayToHeaven( 0) ==    0);
    REQUIRE(stairwayToHeaven( 1) ==    1);
    REQUIRE(stairwayToHeaven( 2) ==    2);
    REQUIRE(stairwayToHeaven( 3) ==    3);
    REQUIRE(stairwayToHeaven( 4) ==    5);
    REQUIRE(stairwayToHeaven( 5) ==    8);
    REQUIRE(stairwayToHeaven( 6) ==   13);
}
