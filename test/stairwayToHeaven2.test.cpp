#include <catch2/catch_test_macros.hpp>

#define private public

#include "stairwayToHeaven2.hpp"

#include <memory>

using namespace StairwayToHeaven2;

TEST_CASE("generate all sequences", "[stairwayToHeaven2]") {
    NaiveAlgorithm algorithm;
    SECTION("case 1") {
        const Size number_of_steps = 1;
        const Size step_limit = 1;
        const SequenceVector expected = {
            {}, // size 0
            {1}, // size 1
        };
        const auto all_sequences_generated = algorithm.generate_all_sequences(number_of_steps, step_limit);
        CHECK(all_sequences_generated == expected);
    }
    SECTION("case 2") {
        const Size number_of_steps = 3;
        const Size step_limit = 1;
        const SequenceVector expected = {
            {}, // size 0
            {1}, // size 1
            {1, 1}, // size 2
            {1, 1, 1}, // size 3
        };
        const auto all_sequences_generated = algorithm.generate_all_sequences(number_of_steps, step_limit);
        CHECK(all_sequences_generated == expected);
    }
    SECTION("case 3") {
        const Size number_of_steps = 3;
        const Size step_limit = 3;
        const SequenceVector expected = {
            {}, // size 0
            {1}, {2}, {3}, // size 1
            {1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}, // size 2
            {1, 1, 1}, {1, 1, 2}, {1, 1, 3},
                {1, 2, 1}, {1, 2, 2}, {1, 2, 3},
                {1, 3, 1}, {1, 3, 2}, {1, 3, 3},
                {2, 1, 1}, {2, 1, 2}, {2, 1, 3},
                {2, 2, 1}, {2, 2, 2}, {2, 2, 3},
                {2, 3, 1}, {2, 3, 2}, {2, 3, 3},
                {3, 1, 1}, {3, 1, 2}, {3, 1, 3},
                {3, 2, 1}, {3, 2, 2}, {3, 2, 3},
                {3, 3, 1}, {3, 3, 2}, {3, 3, 3},
                // size 3
        };
        const auto all_sequences_generated = algorithm.generate_all_sequences(number_of_steps, step_limit);
        CHECK(all_sequences_generated == expected);
    }
}

TEST_CASE("generate all valid steps", "[stairwayToHeaven2]") {
    SECTION("case 1") {
        const NaiveAlgorithm algorithm;
        const Size step_limit = 3;
        const Sequence expected = {1, 2, 3};
        const auto all_valid_steps = algorithm.get_all_valid_steps(step_limit);
        CHECK(all_valid_steps == expected);
    }
    SECTION("case 2") {
        const NaiveAlgorithm algorithm;
        const Size step_limit = 6;
        const Sequence expected = {1, 2, 3, 4, 5, 6};
        const auto all_valid_steps = algorithm.get_all_valid_steps(step_limit);
        CHECK(all_valid_steps == expected);
    }
}

TEST_CASE("filter valid sequences", "[stairwayToHeaven2]") {
    NaiveAlgorithm algorithm;
    SECTION("case 1") {
        const Size number_of_steps = 1;
        const SequenceVector sequences = {
            {}, // size 0
            {1}, // size 1
        };
        const SequenceVector expected = {
            {1},
        };
        const auto valid_sequences = algorithm.filter_valid_sequences(number_of_steps, sequences);
        CHECK(valid_sequences == expected);
    }
    SECTION("case 2") {
        const Size number_of_steps = 3;
        const SequenceVector sequences = {
            {}, // size 0
            {1}, // size 1
            {1, 1}, // size 2
            {1, 1, 1}, // size 3
        };
        const SequenceVector expected = {
            {1, 1, 1},
        };
        const auto valid_sequences = algorithm.filter_valid_sequences(number_of_steps, sequences);
        CHECK(valid_sequences == expected);
    }
    SECTION("case 3") {
        const Size number_of_steps = 3;
        const SequenceVector sequences = {
            {}, // size 0
            {1}, {2}, {3}, // size 1
            {1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}, // size 2
            {1, 1, 1}, {1, 1, 2}, {1, 1, 3},
                {1, 2, 1}, {1, 2, 2}, {1, 2, 3},
                {1, 3, 1}, {1, 3, 2}, {1, 3, 3},
                {2, 1, 1}, {2, 1, 2}, {2, 1, 3},
                {2, 2, 1}, {2, 2, 2}, {2, 2, 3},
                {2, 3, 1}, {2, 3, 2}, {2, 3, 3},
                {3, 1, 1}, {3, 1, 2}, {3, 1, 3},
                {3, 2, 1}, {3, 2, 2}, {3, 2, 3},
                {3, 3, 1}, {3, 3, 2}, {3, 3, 3},
                // size 3
        };
        const SequenceVector expected = {
            {3},
            {1, 2}, {2, 1},
            {1, 1, 1},
        };
        const auto valid_sequences = algorithm.filter_valid_sequences(number_of_steps, sequences);
        CHECK(valid_sequences == expected);
    }
}

TEST_CASE("example 1", "[stairwayToHeaven2]") {
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
    const AlgorithmPtr algorithm = std::make_unique<NaiveAlgorithm>();
    CHECK(algorithm->solve(number_of_steps, step_limit, fees) == expected);
}

TEST_CASE("example 2", "[stairwayToHeaven2]") {
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
    const AlgorithmPtr algorithm = std::make_unique<NaiveAlgorithm>();
    CHECK(algorithm->solve(number_of_steps, step_limit, fees) == expected);
}

TEST_CASE("example 3", "[stairwayToHeaven2]") {
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
    const AlgorithmPtr algorithm = std::make_unique<NaiveAlgorithm>();
    CHECK(algorithm->solve(number_of_steps, step_limit, fees) == expected);
}
