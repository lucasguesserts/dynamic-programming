#include "factorial.hpp"

auto factorial_memoization(const Value n) -> decltype(n) {
    static FactorialMemoization factorial_calculator;
    return factorial_calculator(n);
}
