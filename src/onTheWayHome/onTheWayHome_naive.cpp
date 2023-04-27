#include "onTheWayHome.hpp"

using details::onTheWayHome::previousColumn;
using details::onTheWayHome::previousRow;

long unsigned onTheWayHome_naive(const Position & position) {
    static constexpr long unsigned boundaryValue = 1lu;
    if ((position.row == 0) or (position.column == 0)) return boundaryValue;
    const auto numberOfPathsToPreviousColumnPosition = onTheWayHome_naive(previousColumn(position));
    const auto numberOfPathsToPreviousRowPosition = onTheWayHome_naive(previousRow(position));
    return numberOfPathsToPreviousRowPosition + numberOfPathsToPreviousColumnPosition;
}
