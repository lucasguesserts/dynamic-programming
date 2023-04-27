#include <catch2/catch_test_macros.hpp>

#if __clang__
#pragma clang diagnostic ignored "-Wkeyword-macro"
#endif

#define private public

#include "stairwayToHeaven2.hpp"

using namespace StairwayToHeaven2;

TEST_CASE("solve", "[stairwayToHeaven2]") {
    SECTION("case 1") {
        /**
         * ===== Example 1 =====
         * number_of_steps = 3
         * step_limit = 3
         * fees = [2, 3, 4]
         * sequences and costs:
         *         cost = 2, sequence = (3,)
         *         cost = 5, sequence = (1, 2)
         *         cost = 6, sequence = (2, 1)
         *         cost = 9, sequence = (1, 1, 1)
         * optimal cost sequence: (3,)
         * cost of optimal sequence: 2
         */
        const Size number_of_steps = 3;
        const Size step_limit = 3;
        const Fees fees = {2, 3, 4};
        const Sequence expected = {3};
        const DynamicProgrammingAlgorithm algorithm;
        CHECK(algorithm.solve(number_of_steps, step_limit, fees) == expected);
    }
    SECTION("case 2") {
        /**
         * ===== Example 2 =====
         * number_of_steps = 4
         * step_limit = 3
         * fees = [1, 1, 1, 3]
         * sequences and costs:
         *         cost = 2, sequence = (1, 3)
         *         cost = 2, sequence = (2, 2)
         *         cost = 4, sequence = (3, 1)
         *         cost = 3, sequence = (1, 1, 2)
         *         cost = 5, sequence = (1, 2, 1)
         *         cost = 5, sequence = (2, 1, 1)
         *         cost = 6, sequence = (1, 1, 1, 1)
         * optimal cost sequence: (1, 3)
         * cost of optimal sequence: 2
         */
        const Size number_of_steps = 4;
        const Size step_limit = 3;
        const Fees fees = {1, 1, 1, 3};
        const Sequence expected = {1, 3};
        const DynamicProgrammingAlgorithm algorithm;
        CHECK(algorithm.solve(number_of_steps, step_limit, fees) == expected);
    }
    SECTION("case 3") {
        /**
         * ===== random case =====
         * number_of_steps = 6
         * step_limit = 3
         * fees = [4, 3, 6, 9, 5, 1]
         * sequences and costs:
         *         cost = 13, sequence = (3, 3)
         *         cost = 16, sequence = (1, 2, 3)
         *         cost = 12, sequence = (1, 3, 2)
         *         cost = 19, sequence = (2, 1, 3)
         *         cost = 15, sequence = (2, 2, 2)
         *         cost = 11, sequence = (2, 3, 1)
         *         cost = 18, sequence = (3, 1, 2)
         *         cost = 14, sequence = (3, 2, 1)
         *         cost = 22, sequence = (1, 1, 1, 3)
         *         cost = 18, sequence = (1, 1, 2, 2)
         *         cost = 14, sequence = (1, 1, 3, 1)
         *         cost = 21, sequence = (1, 2, 1, 2)
         *         cost = 17, sequence = (1, 2, 2, 1)
         *         cost = 13, sequence = (1, 3, 1, 1)
         *         cost = 24, sequence = (2, 1, 1, 2)
         *         cost = 20, sequence = (2, 1, 2, 1)
         *         cost = 16, sequence = (2, 2, 1, 1)
         *         cost = 19, sequence = (3, 1, 1, 1)
         *         cost = 27, sequence = (1, 1, 1, 1, 2)
         *         cost = 23, sequence = (1, 1, 1, 2, 1)
         *         cost = 19, sequence = (1, 1, 2, 1, 1)
         *         cost = 22, sequence = (1, 2, 1, 1, 1)
         *         cost = 25, sequence = (2, 1, 1, 1, 1)
         *         cost = 28, sequence = (1, 1, 1, 1, 1, 1)
         * optimal cost sequence: (2, 3, 1)
         * cost of optimal sequence: 11
         */
        const Size number_of_steps = 6;
        const Size step_limit = 3;
        const Fees fees = {4, 3, 6, 9, 5, 1};
        const Sequence expected = {2, 3, 1};
        const DynamicProgrammingAlgorithm algorithm;
        CHECK(algorithm.solve(number_of_steps, step_limit, fees) == expected);
    }
    SECTION("case 4") {
        /**
         * ===== random case =====
         * number_of_steps = 10
         * step_limit = 4
         * fees = [7, 3, 6, 7, 1, 2, 5, 7, 10, 9]
         * optimal cost sequence: (4, 2, 4)
         * cost of optimal sequence: 13
         */
        const Size number_of_steps = 10;
        const Size step_limit = 4;
        const Fees fees = {7, 3, 6, 7, 1, 2, 5, 7, 10, 9};
        const Sequence expected = {4, 2, 4};
        const DynamicProgrammingAlgorithm algorithm;
        CHECK(algorithm.solve(number_of_steps, step_limit, fees) == expected);
    }
}
