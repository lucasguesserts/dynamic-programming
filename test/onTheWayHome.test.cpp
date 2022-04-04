#include <catch2/catch_test_macros.hpp>

#include <vector>

#include "onTheWayHome.hpp"

#include "random.hpp"

struct TestInstance {
    Position position;
    long unsigned numberOfUniquePaths;
};

TEST_CASE("boundary conditions - memoization solution", "[onTheWayHome]") {
    SECTION("first row") {
        const std::vector<TestInstance> testInstances = {
            {{0, 0                     }, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
        };
        for (const auto& instance: testInstances) {
            CHECK(onTheWayHome_memoization(instance.position) == instance.numberOfUniquePaths);
        }
    }
    SECTION("first column") {
        const std::vector<TestInstance> testInstances = {
            {{0,                      0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
        };
        for (const auto& instance: testInstances) {
            CHECK(onTheWayHome_memoization(instance.position) == instance.numberOfUniquePaths);
        }
    }
}

TEST_CASE("solution memoization", "[onTheWayHome]") {
    const std::vector<TestInstance> testInstances = {
        {{0, 0},   1},
        {{1, 1},   2},
        {{2, 2},   6},
        {{0, 3},   1},
        {{3, 0},   1},
        {{0, 9},   1},
        {{9, 0},   1},
        {{3, 4},  35},
        {{5, 5}, 252},
        {{5, 1},   6},
        {{1, 5},   6},
        {{1, 5},   6},
    };
    for (const auto& instance: testInstances) {
        CHECK(onTheWayHome_memoization(instance.position) == instance.numberOfUniquePaths);
    }
}

TEST_CASE("boundary conditions - naive", "[onTheWayHome]") {
    SECTION("first row") {
        const std::vector<TestInstance> testInstances = {
            {{0, 0                     }, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
        };
        for (const auto& instance: testInstances) {
            CHECK(onTheWayHome_naive(instance.position) == instance.numberOfUniquePaths);
        }
    }
    SECTION("first column") {
        const std::vector<TestInstance> testInstances = {
            {{0,                      0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
        };
        for (const auto& instance: testInstances) {
            CHECK(onTheWayHome_naive(instance.position) == instance.numberOfUniquePaths);
        }
    }
}

TEST_CASE("solution - naive", "[onTheWayHome]") {
    const std::vector<TestInstance> testInstances = {
        {{0, 0},   1},
        {{0, 9},   1},
        {{9, 0},   1},
        {{3, 4},  35},
        {{5, 5}, 252},
        {{5, 1},   6},
        {{1, 5},   6},
        {{1, 5},   6},
        {{2, 2},   6}
    };
    for (const auto& instance: testInstances) {
        CHECK(onTheWayHome_naive(instance.position) == instance.numberOfUniquePaths);
    }
}

TEST_CASE("boundary conditions - class", "[onTheWayHome]") {
    SECTION("first row") {
        const std::vector<TestInstance> testInstances = {
            {{0, 0                     }, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
        };
        for (const auto& instance: testInstances) {
            CHECK(OnTheWayHome::compute(instance.position) == instance.numberOfUniquePaths);
        }
    }
    SECTION("first column") {
        const std::vector<TestInstance> testInstances = {
            {{0,                      0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
        };
        for (const auto& instance: testInstances) {
            CHECK(OnTheWayHome::compute(instance.position) == instance.numberOfUniquePaths);
        }
    }
}

TEST_CASE("solution - class", "[onTheWayHome]") {
    const std::vector<TestInstance> testInstances = {
        {{0, 0},   1},
        {{0, 9},   1},
        {{9, 0},   1},
        {{3, 4},  35},
        {{5, 5}, 252},
        {{5, 1},   6},
        {{1, 5},   6},
        {{1, 5},   6},
        {{2, 2},   6}
    };
    for (const auto& instance: testInstances) {
        CHECK(OnTheWayHome::compute(instance.position) == instance.numberOfUniquePaths);
    }
}
