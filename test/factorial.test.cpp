#include <catch2/catch_test_macros.hpp>

#include "factorial.hpp"

TEST_CASE( "compute factorials", "[factorial]" ) {
    REQUIRE( factorial(1) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
}
