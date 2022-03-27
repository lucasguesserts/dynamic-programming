#include "factorial.hpp"

#include <vector>

long unsigned factorial_naive(const long unsigned n) {
    if (n < 1) return 1;
    else return n * factorial_naive(n - 1);
}
