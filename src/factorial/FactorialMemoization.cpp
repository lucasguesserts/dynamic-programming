#include "factorial.hpp"

#include <initializer_list>
#include <vector>

FactorialMemoization::FactorialMemoization() {
    constexpr long unsigned RESERVED_SIZE = 20;
    constexpr long unsigned INITIAL_VALUE = 1lu;
    this->values.reserve(RESERVED_SIZE);
    this->values.push_back(INITIAL_VALUE);
}

long unsigned FactorialMemoization::operator()(const long unsigned n) {
    if (n < values.size()) {
        return values[n];
    } else {
        const long unsigned result = n * (*this)(n - 1);
        values.push_back(result);
        return result;
    }
}
