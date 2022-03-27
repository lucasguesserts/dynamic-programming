#include "factorial.hpp"

#include <initializer_list>
#include <vector>

constexpr auto initialFactorialValues = { 1lu };

long unsigned factorial_memoization(const long unsigned n) {
    static std::vector<long unsigned> values = initialFactorialValues;
    if (n < values.size()) return values[n];
    else {
        const long unsigned result = n * factorial_memoization(n - 1);
        values.push_back(result);
        return result;
    }
}
