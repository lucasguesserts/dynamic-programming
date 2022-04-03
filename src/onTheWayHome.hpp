#ifndef ON_THE_WAY_HOME_HPP
#define ON_THE_WAY_HOME_HPP

#include <utility>

struct Position {
    const long unsigned row;
    const long unsigned column;
};

long unsigned onTheWayHome (const Position& position);

#endif
