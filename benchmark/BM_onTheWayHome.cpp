#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include <vector>
#include <functional>

#include "onTheWayHome.hpp"

const std::vector<Position> problemInstances = {
    {0, 0},
    {1, 1},
    {2, 2},
    {0, 3},
    {3, 0},
    {0, 9},
    {9, 0},
    {3, 4},
    {5, 5},
    {5, 1},
    {1, 5},
    {12, 5},
    {5, 12},
};

long unsigned run(std::function<long unsigned(const Position &)> f) {
    long unsigned acc = 0;
        for (const auto& instance: problemInstances) {
            acc += f(instance);
        }
    return acc;
}

TEST_CASE("onTheWayHome Benchmark", "[benchmark][onTheWayHome]") {

    BENCHMARK("opt") {
        return run(onTheWayHome_memoization);
    };

    BENCHMARK("class") {
        OnTheWayHome solver;
        return run([&solver](const Position & p) {return solver.compute(p); });
    };

    BENCHMARK("naive") {
        return run(onTheWayHome_naive);
    };

}
