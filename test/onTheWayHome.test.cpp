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
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
            {{0, generateRandomNumber()}, 1},
        };
        for (const auto& instance: testInstances) {
            REQUIRE(onTheWayHome(instance.position) == instance.numberOfUniquePaths);
        }
    }
    SECTION("first column") {
        const std::vector<TestInstance> testInstances = {
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
            {{generateRandomNumber(), 0}, 1},
        };
        for (const auto& instance: testInstances) {
            REQUIRE(onTheWayHome(instance.position) == instance.numberOfUniquePaths);
        }
    }
}
