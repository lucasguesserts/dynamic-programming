#include "stairwayToHeaven.hpp"
#include "factorial.hpp"

long int stairwayToHeaven_sum (const long int n) {
    const auto remainder = n % 2lu;
    const auto quotient = (n - remainder) / 2;
    long int acc = 0lu;
    for (long unsigned i = 0lu; i <= quotient; ++i) {
        acc += factorial(n - i) / ( factorial(i) * factorial(n - 2*i) );
    }
    return acc;
}
