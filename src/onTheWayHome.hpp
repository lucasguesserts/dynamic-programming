#ifndef ON_THE_WAY_HOME_HPP
#define ON_THE_WAY_HOME_HPP

#include <vector>

struct Position {
    long unsigned row;
    long unsigned column;
};

long unsigned onTheWayHome_opt (Position position);

long unsigned onTheWayHome (Position position);

long unsigned onTheWayHome_naive (const Position& position);

namespace details {
    void swapPosition(Position& position);
    Position previousRow (const Position& position);
    Position previousColumn (const Position& position);
    bool rowExists (
        const long unsigned row,
        const std::vector<std::vector<long unsigned>> list
    );
    bool columnExists (
        const long unsigned column,
        const std::vector<long unsigned> list
    );
};

#endif
