#include <catch2/catch_test_macros.hpp>

#include <cppitertools/itertools.hpp>

#include <vector>

TEST_CASE("powerset", "[cppitertools]") {
    SECTION("case 1") {
        auto v = std::vector<int>{1, 2, 3, 4};
        auto c = iter::powerset(v);
        auto actual = std::vector<std::vector<int>>();
        for (auto && x : c) {
            auto v = std::vector<int>(x.begin(), x.end());
            actual.push_back(v);
        }
        auto expected = std::vector<std::vector<int>>{
            {1, 2},
            {1, 3},
            {1, 4},
            {2, 3},
            {2, 4},
            {3, 4},
        };
        REQUIRE(actual == expected);
    }
}
