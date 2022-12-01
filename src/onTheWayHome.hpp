#ifndef ON_THE_WAY_HOME_HPP
#define ON_THE_WAY_HOME_HPP

#include <vector>

struct Position {
    long unsigned row;
    long unsigned column;
};

long unsigned onTheWayHome_memoization (const Position& position);

long unsigned onTheWayHome_naive (const Position& position);

class OnTheWayHome {
    public:
        OnTheWayHome();
        long unsigned compute(const Position& position);
    private:
        std::vector<std::vector<long unsigned>> values;

        bool positionExists(const Position& position);
        long unsigned getValue(const Position& position);
        bool rowExists(const Position& position);
        bool columnExists(const Position& position);
        long unsigned getPreviousRowValue(const Position& referencePosition);
        long unsigned getPreviousColumnValue(const Position& referencePosition);
        void addRowIfItDoesntExist(const Position& position);
        void addValue(const long unsigned& value, const Position& position);
        Position previousRow(const Position& position);
        Position previousColumn(const Position& position);
};

namespace details {
    namespace onTheWayHome {
        Position swapPosition(const Position& position);
        Position previousRow (const Position& position);
        Position previousColumn (const Position& position);
        bool rowExists (
            const long unsigned& row,
            const std::vector<std::vector<long unsigned>>& list
        );
        bool columnExists (
            const long unsigned& column,
            const std::vector<long unsigned>& list
        );
    }
}

#endif
