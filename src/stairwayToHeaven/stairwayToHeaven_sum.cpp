#include "factorial.hpp"
#include "stairwayToHeaven.hpp"

long unsigned stairwayToHeaven_sum(const long unsigned n) {
    const auto remainder = n % 2lu;
    const auto quotient = (n - remainder) / 2;
    long unsigned acc = 0lu;
    for (long unsigned i = 0lu; i <= quotient; ++i) {
        acc += factorial(n - i) / (factorial(i) * factorial(n - 2 * i));
    }
    return acc;
}
