#include <catch2/catch_test_macros.hpp>

#include <initializer_list>

#include "rodCutter.hpp"

TEST_CASE("rodCutter", "[rodCutter]") {
    const unsigned rodSize = 4;
    const std::initializer_list<unsigned> pricesOfRodPieces = {2, 4, 7, 8};
    const auto problem = RodCutter::ProblemBuilder()
        .rodSize(rodSize)
        .prices(pricesOfRodPieces)
        .build();
    auto solver = RodCutter::Solver(problem);
    CHECK(solver(0u) == 0u);
    CHECK(solver(1u) == 2u);
    CHECK(solver(2u) == 4u);
    CHECK(solver(3u) == 7u);
    CHECK(solver(4u) == 9u);
}
