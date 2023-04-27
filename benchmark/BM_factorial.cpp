#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "factorial.hpp"

#include <functional>

auto run_factorial(FactorialFunction f) -> decltype(f)::result_type {
    const auto nMax = Value{18};
    auto acc = Value{0};
    for (auto n = 0u; n < nMax; ++n) {
        acc += f(n);
    }
    return acc;
}

TEST_CASE("Factorial Benchmark", "[benchmark][factorial]") {
    BENCHMARK("constexpr") {
        return run_factorial(factorial);
    };

    BENCHMARK("naive") {
        return run_factorial(factorial_naive);
    };

    BENCHMARK("memoization object") {
        return run_factorial(factorial_memoization);
    };

    BENCHMARK("memoization") {
        FactorialMemoization factorialMemoization;
        return run_factorial(factorialMemoization);
    };
}
