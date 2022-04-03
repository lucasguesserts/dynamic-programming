#ifndef ON_THE_WAY_HOME_HPP
#define ON_THE_WAY_HOME_HPP

#include <utility>

struct Position {
    long unsigned row;
    long unsigned column;
};

long unsigned onTheWayHome (Position position);

long unsigned onTheWayHome_naive (const Position& position);

#endif
