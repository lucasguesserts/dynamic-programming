#include "factorial.hpp"

long unsigned factorial_memoization(const long unsigned n) {
    static FactorialMemoization factorial_calculator;
    return factorial_calculator(n);
}
