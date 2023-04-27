#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <memory>
#include <random>
#include <vector>

#if __clang__
#pragma clang diagnostic ignored "-Wkeyword-macro"
#endif

#define private public
#define protected public

#include "burglars_night_out.hpp"

using namespace BurglarsNightOut;

constexpr auto TOLERANCE = 0.01;

auto generateRandomCosts();

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)

TEST_CASE("is true alternate", "[burglarsNightOut]") {
    CHECK(Algorithm::is_true_alternate_sequence({}) == true);
    CHECK(Algorithm::is_true_alternate_sequence({true}) == true);
    CHECK(Algorithm::is_true_alternate_sequence({false}) == true);
    CHECK(Algorithm::is_true_alternate_sequence({false, true, false, true, false, true, false}) == true);
    CHECK(Algorithm::is_true_alternate_sequence({false, false, false, false, false}) == true);
    CHECK(Algorithm::is_true_alternate_sequence({false, false, false, false, true, false, true, true, false, false, false, false, true}) == false);
    CHECK(Algorithm::is_true_alternate_sequence({false, true, false, true, false, false, false, false, true, false, true, false}) == true);
    CHECK(Algorithm::is_true_alternate_sequence({true, true, true, false}) == false);
    CHECK(Algorithm::is_true_alternate_sequence({false, true, true, false, true, false, false, false, true}) == false);
    CHECK(Algorithm::is_true_alternate_sequence({false, true, false}) == true);
    CHECK(Algorithm::is_true_alternate_sequence({false, false}) == true);
}

TEST_CASE("cost of sequence", "[burglarsNightOut]") {
    SECTION("case -1") {
        const auto b = BinarySequence{
            true,
        };
        const auto r = RealSequence{19, 17};
        REQUIRE_THROWS(Algorithm::cost_of_sequence(b, r));
    }
    SECTION("case 0") {
        const auto b = BinarySequence{true, true, true};
        const auto r = RealSequence{19, 17, 10};
        const auto expected = Cost{46.0};
        CHECK_THAT(Algorithm::cost_of_sequence(b, r), Catch::Matchers::WithinAbs(expected, TOLERANCE));
    }
    SECTION("case 1") {
        const auto b = BinarySequence{false, true};
        const auto r = RealSequence{2, 4};
        const auto expected = Cost{4.0};
        CHECK_THAT(Algorithm::cost_of_sequence(b, r), Catch::Matchers::WithinAbs(expected, TOLERANCE));
    }
    SECTION("case 2") {
        const auto b = BinarySequence{true, false, false, true};
        const auto r = RealSequence{9, 7, 2, 3};
        const auto expected = Cost{12.0};
        CHECK_THAT(Algorithm::cost_of_sequence(b, r), Catch::Matchers::WithinAbs(expected, TOLERANCE));
    }
    SECTION("case 3") {
        const auto b = BinarySequence{false, false};
        const auto r = RealSequence{12, 10};
        const auto expected = Cost{0.0};
        CHECK_THAT(Algorithm::cost_of_sequence(b, r), Catch::Matchers::WithinAbs(expected, TOLERANCE));
    }
}

TEST_CASE("NaiveAlgorithm - generateAllBinarySequences", "[burglarsNightOut]") {
    SECTION("case n = 0") {
        const auto n = Size{0};
        const auto expected = std::vector<BinarySequence>{{}};
        CHECK(NaiveAlgorithm::generate_all_binary_sequences(n) == expected);
    }
    SECTION("case n = 1") {
        const auto n = Size{1};
        const auto expected = std::vector<BinarySequence>{{false}, {true}};
        CHECK(NaiveAlgorithm::generate_all_binary_sequences(n) == expected);
    }
    SECTION("case n = 2") {
        const auto n = Size{2};
        const auto expected = std::vector<BinarySequence>{{false, false}, {false, true}, {true, false}, {true, true}};
        CHECK(NaiveAlgorithm::generate_all_binary_sequences(n) == expected);
    }
    SECTION("case n = 3") {
        const auto n = Size{3};
        const auto expected = std::vector<BinarySequence>{{false, false, false}, {false, false, true}, {false, true, false}, {false, true, true}, {true, false, false}, {true, false, true}, {true, true, false}, {true, true, true}};
        CHECK(NaiveAlgorithm::generate_all_binary_sequences(n) == expected);
    }
}

TEST_CASE("NaiveAlgorithm - filterTrueAlternateSequences", "[burglarsNightOut]") {
    SECTION("case 0") {
        const auto binary_sequences = std::vector<BinarySequence>{};
        const auto expected = std::vector<BinarySequence>{};
        CHECK(NaiveAlgorithm::filter_true_alternate_sequences(binary_sequences) == expected);
    }
    SECTION("case 1") {
        const auto binary_sequences = std::vector<BinarySequence>{{true, true}};
        const auto expected = std::vector<BinarySequence>{};
        CHECK(NaiveAlgorithm::filter_true_alternate_sequences(binary_sequences) == expected);
    }
    SECTION("case 2") {
        const auto binary_sequences = std::vector<BinarySequence>{{false, false}};
        const auto expected = std::vector<BinarySequence>{{false, false}};
        CHECK(NaiveAlgorithm::filter_true_alternate_sequences(binary_sequences) == expected);
    }
    SECTION("case 3") {
        const auto binary_sequences = std::vector<BinarySequence>{{false, false, false}, {false, true, true}, {false, true, false}, {true, false, true}, {true, true, false}};
        const auto expected = std::vector<BinarySequence>{{false, false, false}, {false, true, false}, {true, false, true}};
        CHECK(NaiveAlgorithm::filter_true_alternate_sequences(binary_sequences) == expected);
    }
}

TEST_CASE("NaiveAlgorithm - selectMostExpensiveSequence", "[burglarsNightOut]") {
    SECTION("case 0") {
        const auto binary_sequences = std::vector<BinarySequence>{};
        const auto costs = RealSequence{};
        const auto expected = BinarySequence{};
        CHECK(NaiveAlgorithm::select_most_expensive_sequence(binary_sequences, costs) == expected);
    }
    SECTION("case 1") {
        const auto binary_sequences = std::vector<BinarySequence>{{false}};
        const auto costs = RealSequence{-10};
        const auto expected = BinarySequence{false};
        CHECK(NaiveAlgorithm::select_most_expensive_sequence(binary_sequences, costs) == expected);
    }
    SECTION("case 2") {
        const auto binary_sequences = std::vector<BinarySequence>{
            {false, false},
            {false, true},
            {true, false},
            {true, true},
        };
        const auto costs = RealSequence{13, 16};
        const auto expected = BinarySequence{true, true};
        CHECK(NaiveAlgorithm::select_most_expensive_sequence(binary_sequences, costs) == expected);
    }
    SECTION("case 3") {
        const auto binary_sequences = std::vector<BinarySequence>{
            {false, false, false, true, true, true, true, true, true},
            {true, false, true, true, true, true, true, false, true},
            {true, false, true, true, true, false, false, false, true},
            {true, true, true, false, true, false, false, false, false},
            {false, true, true, true, true, true, true, false, true},
            {false, false, false, false, true, true, false, true, false},
        };
        const auto costs = RealSequence{-2, -19, 10, 1, 17, 17, 13, -5, 19};
        const auto expected = BinarySequence{true, false, true, true, true, true, true, false, true};
        CHECK(NaiveAlgorithm::select_most_expensive_sequence(binary_sequences, costs) == expected);
    }
}

TEST_CASE("NaiveAlgorithm - solve", "[burglarsNightOut]") {
    const auto algorithm = std::make_unique<NaiveAlgorithm>();
    SECTION("case 0") {
        const auto costs = RealSequence{};
        const auto expected = BinarySequence{};
        CHECK(algorithm->solve(costs) == expected);
    }
    SECTION("case 1") {
        const auto costs = RealSequence{-10};
        const auto expected = BinarySequence{false};
        CHECK(algorithm->solve(costs) == expected);
    }
    SECTION("case 2") {
        const auto costs = RealSequence{13, 16};
        const auto expected = BinarySequence{false, true};
        CHECK(algorithm->solve(costs) == expected);
    }
    SECTION("case 3") {
        const auto costs = RealSequence{13, 16, 4};
        const auto expected = BinarySequence{true, false, true};
        CHECK(algorithm->solve(costs) == expected);
    }
    SECTION("case 4") {
        const auto costs = RealSequence{13, 160, 4};
        const auto expected = BinarySequence{false, true, false};
        CHECK(algorithm->solve(costs) == expected);
    }
    SECTION("case 5") {
        const auto costs = RealSequence{2, 8, -4, 1, 6};
        const auto expected = BinarySequence{false, true, false, false, true};
        CHECK(algorithm->solve(costs) == expected);
    }
}

TEST_CASE("DynamicProgrammingAlgorithm - solve", "[burglarsNightOut]") {
    const auto algorithm = std::make_unique<DynamicProgrammingAlgorithm>();
    SECTION("case 0") {
        const auto costs = RealSequence{};
        const auto expected = BinarySequence{};
        CHECK(algorithm->solve(costs) == expected);
    }
    SECTION("case 1") {
        const auto costs = RealSequence{-10};
        const auto expected = BinarySequence{false};
        CHECK(algorithm->solve(costs) == expected);
    }
    SECTION("case 2") {
        const auto costs = RealSequence{13, 16};
        const auto expected = BinarySequence{false, true};
        CHECK(algorithm->solve(costs) == expected);
    }
    SECTION("case 3") {
        const auto costs = RealSequence{13, 16, 4};
        const auto expected = BinarySequence{true, false, true};
        CHECK(algorithm->solve(costs) == expected);
    }
    SECTION("case 4") {
        const auto costs = RealSequence{13, 160, 4};
        const auto expected = BinarySequence{false, true, false};
        CHECK(algorithm->solve(costs) == expected);
    }
    SECTION("case 5") {
        const auto costs = RealSequence{2, 8, -4, 1, 6};
        const auto expected = BinarySequence{false, true, false, false, true};
        CHECK(algorithm->solve(costs) == expected);
    }
}

auto generateRandomCosts() {
    static constexpr Size MINIMUM_COST_SIZE = 1;
    static constexpr Size MAXIMUM_COST_SIZE = 12;
    static constexpr double MINIMUM_COST_VALUE = -10.0;
    static constexpr double MAXIMUM_COST_VALUE = 10.0;

    std::random_device rd;
    std::mt19937 random_generator(rd());
    std::uniform_real_distribution<Cost> uniform_distribution(MINIMUM_COST_VALUE, MAXIMUM_COST_VALUE);
    std::uniform_int_distribution<Size> integer_uniform_distribution(MINIMUM_COST_SIZE, MAXIMUM_COST_SIZE);

    const auto costs_size = Size{integer_uniform_distribution(random_generator)};
    auto costs = RealSequence(costs_size);
    for (Size i = 0; i < costs_size; ++i) {
        costs[i] = uniform_distribution(random_generator);
    }

    return costs;
}

TEST_CASE("compare algorithms - Naive and DynamicProgramming", "[burglarsNightOut]") {
    constexpr auto numberOfCases = Size{10};
    for (auto i = 0u; i < numberOfCases; ++i) {
        const auto costs = generateRandomCosts();
        const auto dpSolution = std::make_unique<DynamicProgrammingAlgorithm>()->solve(costs);
        const auto naiveSolution = std::make_unique<NaiveAlgorithm>()->solve(costs);
        REQUIRE(dpSolution == naiveSolution);
    }
}

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
