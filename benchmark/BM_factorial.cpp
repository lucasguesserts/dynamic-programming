#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "factorial.hpp"

#include <functional>

long unsigned runFactorial(std::function<long unsigned(long unsigned)> f) {
    const long unsigned nMax = 18;
    long unsigned acc = 0;
    for (long unsigned n = 0; n < nMax; ++n) {
        acc += f(n);
    }
    return acc;
}

TEST_CASE("Factorial Benchmark", "[factorial]") {

    BENCHMARK("constexpr") {
        return runFactorial(factorial);
    };

    BENCHMARK("naive") {
        return runFactorial(factorial_naive);
    };

    BENCHMARK("memoization object") {
        return runFactorial(factorial_memoization);
    };

    BENCHMARK("memoization") {
        FactorialMemoization factorialMemoization;
        return runFactorial(factorialMemoization);
    };

}
