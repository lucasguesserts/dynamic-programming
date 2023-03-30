#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <vector>

#define private public

#include "burglarsNightOut.hpp"

TEST_CASE("is true alternate", "[burglarsNightOut]") {
    CHECK(is_true_alternate_sequence({}) == true);
    CHECK(is_true_alternate_sequence({true}) == true);
    CHECK(is_true_alternate_sequence({false}) == true);
    CHECK(is_true_alternate_sequence({false, true, false, true, false, true, false}) == true);
    CHECK(is_true_alternate_sequence({false, false, false, false, false}) == true);
    CHECK(is_true_alternate_sequence({false, false, false, false, true, false, true, true, false, false, false, false, true}) == false);
    CHECK(is_true_alternate_sequence({false, true, false, true, false, false, false, false, true, false, true, false}) == true);
    CHECK(is_true_alternate_sequence({true, true, true, false}) == false);
    CHECK(is_true_alternate_sequence({false, true, true, false, true, false, false, false, true}) == false);
    CHECK(is_true_alternate_sequence({false, true, false}) == true);
    CHECK(is_true_alternate_sequence({false, false}) == true);
}

TEST_CASE("cost_of_sequence", "[burglarsNightOut]") {
    SECTION("case 0") {
        const BinarySequence b = {true, true, true};
        const RealSequence r = {19, 17, 10};
        CHECK_THAT(cost_of_sequence(b, r), Catch::Matchers::WithinAbs(46.0, 0.01));
    }
    SECTION("case 1") {
        const BinarySequence b = {false, true};
        const RealSequence r = {2, 4};
        CHECK_THAT(cost_of_sequence(b, r), Catch::Matchers::WithinAbs(4.0, 0.01));
    }
    SECTION("case 2") {
        const BinarySequence b = {true, false, false, true};
        const RealSequence r = {9, 7, 2, 3};
        CHECK_THAT(cost_of_sequence(b, r), Catch::Matchers::WithinAbs(12.0, 0.01));
    }
    SECTION("case 3") {
        const BinarySequence b = {false, false};
        const RealSequence r = {12, 10};
        CHECK_THAT(cost_of_sequence(b, r), Catch::Matchers::WithinAbs(0.0, 0.01));
    }
}

TEST_CASE("NaiveAlgorithm - generateAllBinarySequences", "[burglarsNightOut]") {
    SECTION("case n = 0") {
        const Size n = 0;
        const std::vector<BinarySequence> expected = {{}};
        CHECK(NaiveAlgorithm::generateAllBinarySequences(n) == expected);
    }
    SECTION("case n = 1") {
        const Size n = 1;
        const std::vector<BinarySequence> expected = {{false}, {true}};
        CHECK(NaiveAlgorithm::generateAllBinarySequences(n) == expected);
    }
    SECTION("case n = 2") {
        const Size n = 2;
        const std::vector<BinarySequence> expected = {{false, false}, {false, true}, {true, false}, {true, true}};
        CHECK(NaiveAlgorithm::generateAllBinarySequences(n) == expected);
    }
    SECTION("case n = 3") {
        const Size n = 3;
        const std::vector<BinarySequence> expected = {{false, false, false}, {false, false, true}, {false, true, false}, {false, true, true}, {true, false, false}, {true, false, true}, {true, true, false}, {true, true, true}};
        CHECK(NaiveAlgorithm::generateAllBinarySequences(n) == expected);
    }
}

TEST_CASE("NaiveAlgorithm - filterTrueAlternateSequences", "[burglarsNightOut]") {
    SECTION("case 0") {
        const std::vector<BinarySequence> binarySequences = {{true, true}};
        const std::vector<BinarySequence> expected = {};
        CHECK(NaiveAlgorithm::filterTrueAlternateSequences(binarySequences) == expected);
    }
    SECTION("case 1") {
        const std::vector<BinarySequence> binarySequences = {{false, false}};
        const std::vector<BinarySequence> expected = {{false, false}};
        CHECK(NaiveAlgorithm::filterTrueAlternateSequences(binarySequences) == expected);
    }
    SECTION("case 0") {
        const std::vector<BinarySequence> binarySequences = {{false, false, false}, {false, true, true}, {false, true, false}, {true, false, true}, {true, true, false}};
        const std::vector<BinarySequence> expected = {{false, false, false}, {false, true, false}, {true, false, true}};
        CHECK(NaiveAlgorithm::filterTrueAlternateSequences(binarySequences) == expected);
    }
}

