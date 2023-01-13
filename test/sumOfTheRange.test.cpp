#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <vector>

#include "sumOfTheRange.hpp"

using namespace Catch::literals;

void check_solution(
    const SumOfTheRangeAlgorithm & solver,
    const std::vector<Query> queries,
    const std::vector<Catch::Approx> expected
) {
    const auto answers = solver(queries);
    for(unsigned k = 0; k < expected.size(); ++k) {
        REQUIRE(answers[k] == expected[k]);
    }
    return;
}

TEST_CASE("sumOfTheRange", "[rodCutter]") {
    const std::vector<double> values = {1, -2, 3, 10, -8, 0};
    const std::vector<Query> queries = {
        {0, 2},
        {1, 4},
        {3, 3}
    };
    const std::vector<Catch::Approx> expected = {2_a, 3_a, 10_a};
    SECTION("naive algorithm") {
        const SumOfTheRangeAlgorithm solver = Naive(values);
        check_solution(solver, queries, expected);
    }
}
