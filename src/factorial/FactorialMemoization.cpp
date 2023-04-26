#include "factorial.hpp"

#include <initializer_list>
#include <vector>

FactorialMemoization::FactorialMemoization() {
    constexpr auto RESERVED_SIZE = Value{20};
    constexpr auto INITIAL_VALUE = Value{1};
    this->values.reserve(RESERVED_SIZE);
    this->values.push_back(INITIAL_VALUE);
}

auto FactorialMemoization::operator()(const Value n) -> decltype(n) {
    if (n < values.size()) {
        return values[n];
    } else {
        const long unsigned result = n * (*this)(n - 1);
        values.push_back(result);
        return result;
    }
}
