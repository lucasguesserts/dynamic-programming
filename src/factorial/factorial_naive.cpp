#include "factorial.hpp"

#include <vector>

auto factorial_naive(const Value n) -> decltype(n) {
    if (n < 1) return 1;
    else return n * factorial_naive(n - 1);
}
