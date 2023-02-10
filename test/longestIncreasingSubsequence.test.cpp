#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <vector>
#include <string>

#include "longestIncreasingSubsequence.hpp"

using LongestIncreasingSubsequence::Sequence;
using LongestIncreasingSubsequence::SequenceSet;
using LongestIncreasingSubsequence::SubsequenceGenerator;
using LongestIncreasingSubsequence::NaiveAlgorithm;
using LongestIncreasingSubsequence::RecursiveAlgorithm;
using LongestIncreasingSubsequence::DynamicProgrammingAlgorithm;

struct SubsequenceTestCase {
    const std::string name;
    const Sequence sequence;
    const SequenceSet expected;
};

struct LongestIncreasingSubsequenceTestCase {
    const Sequence sequence;
    const unsigned expectedLength;
};

TEST_CASE("subsequences") {
    const std::vector<SubsequenceTestCase> testCaseDataList = {
        {
            "sequence with three elements",
            {7, 4, 8},
            {
                {7},
                {4},
                {8},
                {7, 4},
                {7, 8},
                {4, 8},
                {7, 4, 8},
            }
        },
        {
            "sequence with three elements and repetition",
            {1, 1, 2},
            {
                {1},
                {2},
                {1, 1},
                {1, 2},
                {1, 1, 2}
            }
        },
        {
            "sequence with four elements",
            {10, 3, 9, 4},
            {
                {10},
                {3},
                {9},
                {4},
                {10, 3},
                {10, 9},
                {10, 4},
                {3, 9},
                {3, 4},
                {9, 4},
                {10, 3, 9},
                {10, 3, 4},
                {10, 9, 4},
                {3, 9, 4},
                {10, 3, 9, 4}
            }
        }
    };
    for (const auto & data : testCaseDataList) {
        SECTION(data.name) {
            const LongestIncreasingSubsequence::SubsequenceGenerator gen(data.sequence);
            CHECK(gen.getSubsequences() == data.expected);
        }
    }
}

TEST_CASE("LongestIncreasingSubsequence", "[LongestIncreasingSubsequence]") {
    const std::vector<LongestIncreasingSubsequenceTestCase> test_case_list = {
        {{}, 0}, // empty sequence
        {{10, 3, 9, 4}, 2}, // opt solution: (3, 9)
        {{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}, 6}, // (0, 2, 6, 9, 11, 15) // https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
        {{10, 5, 4, 3, 9, 6, 3, 8, 6, 6, 8, 9, 3, 5, 4}, 4}, // opt solution: (5, 6, 8, 9)
        {{3, 2, 3, 2, 6, 8, 8, 10, 6, 8, 10, 2, 4, 7, 7}, 5}, // opt solution: (2, 3, 6, 8, 10)
        {{7, 1, 7, 10, 4, 7, 3, 4, 5, 3, 4, 10, 6, 1, 6}, 5}, // opt solution: (1, 3, 4, 5, 10)
        {{6, 9, 1, 10, 8, 10, 1, 4, 5, 6, 7, 3, 5, 4, 10}, 6}, // opt solution: (1, 4, 5, 6, 7, 10)
        {{2, 6, 10, 2, 6, 9, 8, 9, 2, 4, 9, 9, 10, 3, 9}, 5}, // opt solution: (2, 6, 8, 9, 10)
    };
    SECTION("naive algorithm") {
        for (const auto & test_case : test_case_list) {
            const NaiveAlgorithm solver(test_case.sequence);
            CHECK(solver.getOptimalLength() == test_case.expectedLength);
        }
    }
    SECTION("recursive algorithm") {
        for (const auto & test_case : test_case_list) {
            const RecursiveAlgorithm solver(test_case.sequence);
            CHECK(solver.getOptimalLength() == test_case.expectedLength);
        }
    }
    SECTION("dynamic programming algorithm") {
        for (const auto & test_case : test_case_list) {
            const DynamicProgrammingAlgorithm solver(test_case.sequence);
            CHECK(solver.getOptimalLength() == test_case.expectedLength);
        }
    }
}
