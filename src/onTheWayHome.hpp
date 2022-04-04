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

class OnTheWayHome {
    public:
        static long unsigned compute(Position position);
    private:
        static constexpr long unsigned boundaryValue = 1lu;
        static const std::vector<long unsigned> newRow;
        static std::vector<std::vector<long unsigned>> values;
};

namespace details {
    namespace onTheWayHome {
        Position swapPosition(const Position& position);
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
};

#endif
