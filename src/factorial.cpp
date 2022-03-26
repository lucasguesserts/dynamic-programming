#include "factorial.hpp"

#include <initializer_list>
#include <vector>

constexpr auto initialFactorialValues = { 1lu };

long unsigned factorial(const long unsigned n) {
    static std::vector<long unsigned> values = initialFactorialValues;
    if (n < values.size()) return values[n];
    else {
        const long unsigned result = n * factorial(n - 1);
        values.push_back(result);
        return result;
    }
}

long unsigned factorial_memoization(const long unsigned n) {
    static std::vector<long unsigned> values = initialFactorialValues;
    if (n < values.size()) return values[n];
    else {
        const long unsigned result = n * factorial(n - 1);
        values.push_back(result);
        return result;
    }
}

long unsigned factorial_naive(const long unsigned n) {
    static std::vector<long unsigned> values = initialFactorialValues;
    if (n < 1) return 1;
    else return n * factorial_naive(n - 1);
}
