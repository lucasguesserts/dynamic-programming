#include "factorial.hpp"

#include <initializer_list>
#include <vector>

constexpr auto initialFactorialValues = { 1lu };

FactorialMemoization::FactorialMemoization () {
    this->values = initialFactorialValues;
}

long unsigned FactorialMemoization::operator() (const long unsigned n) {
    if (n < values.size()) return values[n];
    else {
        const long unsigned result = n * (*this)(n - 1);
        values.push_back(result);
        return result;
    }
}
