#include "fibonacci.hpp"

#include <initializer_list>
#include <vector>

constexpr auto initialFibonacciValues = { 0lu, 1lu };

long unsigned fibonacci(const long unsigned n) {
    static std::vector<long unsigned> values(initialFibonacciValues);
    if (n < values.size()) return values[n];
    else {
        const long int result = fibonacci(n - 1) + fibonacci(n - 2);
        values.push_back(result);
        return result;
    }
}
