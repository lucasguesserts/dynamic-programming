#include "factorial.hpp"

#include <array>

constexpr auto factorialConstexpr(const Value n) -> decltype(n) {
    return n < 1
        ? 1
        : n * factorialConstexpr(n - 1);
}

constexpr std::array factorialConstexprValues = {
    factorialConstexpr(0),
    factorialConstexpr(1),
    factorialConstexpr(2),
    factorialConstexpr(3),
    factorialConstexpr(4),
    factorialConstexpr(5),
    factorialConstexpr(6),
    factorialConstexpr(7),
    factorialConstexpr(8),
    factorialConstexpr(9),
    factorialConstexpr(10),
    factorialConstexpr(11),
    factorialConstexpr(12),
    factorialConstexpr(13),
    factorialConstexpr(14),
    factorialConstexpr(15),
    factorialConstexpr(16),
    factorialConstexpr(17),
    factorialConstexpr(18),
    factorialConstexpr(19),
    factorialConstexpr(20),
}; // Yeah, this code smells. I don't know how to use templates to make it work though.

auto factorial(const long unsigned n) -> decltype(n) {
    return factorialConstexprValues.at(n);
}
