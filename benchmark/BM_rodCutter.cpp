#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "rodCutter.hpp"

const std::initializer_list<double> pricesOfRodPieces = {2, 4, 7, 8};

TEST_CASE("rodCutter Benchmark", "[benchmark][rodCutter]") {

    BENCHMARK("rodCutter") {
        const auto problem = RodCutter::Problem(pricesOfRodPieces);
        auto solver = RodCutter::Solver(problem);
        return solver(4);
    };
}
