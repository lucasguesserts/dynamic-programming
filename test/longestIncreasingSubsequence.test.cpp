#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <vector>

#include "longestIncreasingSubsequence.hpp"

struct LongestIncreasingSubsequenceTestCase {
    const std::vector<double> values;
    const unsigned expected_length;
};

TEST_CASE("LongestIncreasingSubsequence", "[LongestIncreasingSubsequence]") {
    const std::vector<LongestIncreasingSubsequenceTestCase> test_case_list = {
        {{10, 5, 4, 3, 9, 6, 3, 8, 6, 6, 8, 9, 3, 5, 4}, 4}, // opt solution: (5, 6, 8, 9)
        {{3, 2, 3, 2, 6, 8, 8, 10, 6, 8, 10, 2, 4, 7, 7}, 5}, // opt solution: (2, 3, 6, 8, 10)
        {{7, 1, 7, 10, 4, 7, 3, 4, 5, 3, 4, 10, 6, 1, 6}, 5}, // opt solution: (1, 3, 4, 5, 10)
        {{6, 9, 1, 10, 8, 10, 1, 4, 5, 6, 7, 3, 5, 4, 10}, 6}, // opt solution: (1, 4, 5, 6, 7, 10)
        {{2, 6, 10, 2, 6, 9, 8, 9, 2, 4, 9, 9, 10, 3, 9}, 5}, // opt solution: (2, 6, 8, 9, 10)
    };
    for (const auto & test_case : test_case_list) {
        CHECK(longestIncreasingSubsequence(test_case.values) == test_case.expected_length);
    }
}
