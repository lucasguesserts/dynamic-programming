#include "factorial.hpp"

#include <array>

constexpr auto factorial_constexpr(const Value n) -> decltype(n) {
    return n < 1
        ? 1
        : n * factorial_constexpr(n - 1);
}

constexpr auto factorial_constexpr_values = std::array{
    factorial_constexpr(0),
    factorial_constexpr(1),
    factorial_constexpr(2),
    factorial_constexpr(3),
    factorial_constexpr(4),
    factorial_constexpr(5),
    factorial_constexpr(6),
    factorial_constexpr(7),
    factorial_constexpr(8),
    factorial_constexpr(9),
    factorial_constexpr(10),
    factorial_constexpr(11),
    factorial_constexpr(12),
    factorial_constexpr(13),
    factorial_constexpr(14),
    factorial_constexpr(15),
    factorial_constexpr(16),
    factorial_constexpr(17),
    factorial_constexpr(18),
    factorial_constexpr(19),
    factorial_constexpr(20),
}; // Yeah, this code smells. I don't know how to use templates to make it work though.

auto factorial(const Value n) -> decltype(n) {
    return factorial_constexpr_values.at(n);
}
