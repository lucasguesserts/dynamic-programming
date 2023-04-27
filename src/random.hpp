#ifndef RANDOM_HPP_
#define RANDOM_HPP_

#include <random>
#include <stdexcept>

long unsigned generateRandomNumber(
    const long unsigned low = 0lu,
    const long unsigned high = 100lu);

#endif
