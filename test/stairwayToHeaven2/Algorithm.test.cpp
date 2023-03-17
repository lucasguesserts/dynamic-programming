#include <catch2/catch_test_macros.hpp>

#define protected public

#include "stairwayToHeaven2.hpp"

using namespace StairwayToHeaven2;

class TestAlgorithm: public Algorithm {
    public:
        virtual Sequence solve([[maybe_unused]] const Size number_of_steps, [[maybe_unused]] const Size step_limit, [[maybe_unused]] const Fees & fees) const {
            return {};
        }
};

TEST_CASE("compute sequence cost", "[stairwayToHeaven2]") {
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
    const Fees fees = {4, 3, 6, 9, 5, 1};
    const TestAlgorithm algorithm;
    SECTION("case 1") {
        const Sequence sequence = {3, 1, 2};
        const Fee expected = 18;
        CHECK(algorithm.compute_sequence_cost(sequence, fees) == expected);
    }
    SECTION("case 2") {
        const Sequence sequence = {2, 1, 3};
        const Fee expected = 19;
        CHECK(algorithm.compute_sequence_cost(sequence, fees) == expected);
    }
    SECTION("case 3") {
        const Sequence sequence = {1, 2, 1, 1, 1};
        const Fee expected = 22;
        CHECK(algorithm.compute_sequence_cost(sequence, fees) == expected);
    }
    SECTION("case 4") {
        const Sequence sequence = {3, 3};
        const Fee expected = 13;
        CHECK(algorithm.compute_sequence_cost(sequence, fees) == expected);
    }
}

