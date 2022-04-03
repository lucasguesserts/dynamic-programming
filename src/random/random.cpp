#include "random.hpp"

#include <random>
#include <stdexcept>

long unsigned generateRandomNumber(
    const long unsigned low,
    const long unsigned high
)
{
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<long unsigned> distrib(0lu);
    if (!(low <= high)) throw std::invalid_argument("'low' argument of random number generation must be lower or equal 'high'");
    else if (low == high) return low;
    const long unsigned range = high - low;
    return (distrib(gen) % range) + low;
}
