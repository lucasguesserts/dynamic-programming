#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <initializer_list>

#include "rodCutter.hpp"

using namespace Catch::literals;

TEST_CASE("rodCutter", "[rodCutter]") {
    const std::initializer_list<double> pricesOfRodPieces = {2, 4, 7, 8};
    const auto problem = RodCutter::Problem(pricesOfRodPieces);
    auto solver = RodCutter::Solver(problem);
    CHECK(solver(0u) == 0.0_a);
    CHECK(solver(1u) == 2.0_a);
    CHECK(solver(2u) == 4.0_a);
    CHECK(solver(3u) == 7.0_a);
    CHECK(solver(4u) == 9.0_a);
}
