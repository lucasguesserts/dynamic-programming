#include <catch2/catch_test_macros.hpp>

#include <vector>

#include "burglarsNightOut.hpp"

TEST_CASE("is true alternate", "[burglarsNightOut]") {
    CHECK(is_true_alternate_sequence({}) == true);
    CHECK(is_true_alternate_sequence({true}) == true);
    CHECK(is_true_alternate_sequence({false}) == true);
    CHECK(is_true_alternate_sequence({false, true, false, true, false, true, false}) == true);
    CHECK(is_true_alternate_sequence({false, false, false, false, false}) == true);
    CHECK(is_true_alternate_sequence({false, false, false, false, true, false, true, true, false, false, false, false, true}) == false);
    CHECK(is_true_alternate_sequence({false, true, false, true, false, false, false, false, true, false, true, false}) == true);
    CHECK(is_true_alternate_sequence({true, true, true, false}) == false);
    CHECK(is_true_alternate_sequence({false, true, true, false, true, false, false, false, true}) == false);
    CHECK(is_true_alternate_sequence({false, true, false}) == true);
    CHECK(is_true_alternate_sequence({false, false}) == true);

}
