#ifndef FACTORIAL_HPP_
#define FACTORIAL_HPP_

#include <functional>
#include <vector>

using Value = long unsigned;
using FactorialFunction = std::function<auto(const Value n)->decltype(n)>;

auto factorial(const Value n) -> decltype(n);
auto factorial_memoization(const Value n) -> decltype(n);
auto factorial_naive(const Value n) -> decltype(n);

class FactorialMemoization {
public:
    FactorialMemoization();
    auto operator()(const Value n) -> decltype(n);

private:
    std::vector<Value> values;
};

#endif
