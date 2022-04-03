#include <catch2/catch_test_macros.hpp>

#include <vector>

#include "onTheWayHome.hpp"

#include "random.hpp"

struct TestInstance {
    Position position;
    long unsigned numberOfUniquePaths;
};

TEST_CASE("boundary conditions", "[onTheWayHome]") {
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
            CHECK(onTheWayHome(instance.position) == instance.numberOfUniquePaths);
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
            CHECK(onTheWayHome(instance.position) == instance.numberOfUniquePaths);
        }
    }
}

TEST_CASE("solution", "[onTheWayHome]") {
    const std::vector<TestInstance> testInstances = {
        {{0, 0},   1},
        {{3, 4},  35},
        {{5, 5}, 252},
        {{5, 1},   6},
        {{1, 5},   6},
        {{1, 5},   6},
        {{2, 2},   6}
    };
    for (const auto& instance: testInstances) {
        CHECK(onTheWayHome(instance.position) == instance.numberOfUniquePaths);
    }
}
