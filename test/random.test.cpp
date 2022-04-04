#include <catch2/catch_test_macros.hpp>

#include "random.hpp"

TEST_CASE("default low and high", "[random]") {
    const unsigned numberOfTestsToRun = 1000;
    for (unsigned i = 0; i < numberOfTestsToRun; ++i) {
        const auto randomNumberGenerated = generateRandomNumber();
        // REQUIRE(0lu <= randomNumberGenerated); // obviously satified, it is a unsigned
        REQUIRE(randomNumberGenerated <= 100lu);
    }
}

TEST_CASE("not default low and high", "[random]") {
    const long unsigned low = 10;
    const long unsigned high = 1000;
    const unsigned numberOfTestsToRun = 1000;
    for (unsigned i = 0; i < numberOfTestsToRun; ++i) {
        const auto randomNumberGenerated = generateRandomNumber(low, high);
        REQUIRE(low <= randomNumberGenerated);
        REQUIRE(randomNumberGenerated <= high);
    }
}

TEST_CASE("low == high", "[random]") {
    const long unsigned low = 10;
    const long unsigned high = low;
    const unsigned numberOfTestsToRun = 1000;
    for (unsigned i = 0; i < numberOfTestsToRun; ++i) {
        const auto randomNumberGenerated = generateRandomNumber(low, high);
        REQUIRE(low <= randomNumberGenerated);
        REQUIRE(randomNumberGenerated <= high);
    }
}
