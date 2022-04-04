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
        static long unsigned compute(const Position& position);
    private:
        static constexpr long unsigned outOfRangeValue = 0lu;
        static constexpr long unsigned boundaryValue = 1lu;
        static const std::vector<long unsigned> newRow;
        static std::vector<std::vector<long unsigned>> values;

        static bool positionExists(const Position& position);
        static long unsigned getValue(const Position& position);
        static bool rowExists(const Position& position);
        static bool columnExists(const Position& position);
        static long unsigned getPreviousRowValue(const Position& referencePosition);
        static long unsigned getPreviousColumnValue(const Position& referencePosition);
        static void addRowIfItDoesntExist(const Position& position);
        static void addValue(const long unsigned& value, const Position& position);
        static Position previousRow(const Position& position);
        static Position previousColumn(const Position& position);
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
