#include "onTheWayHome.hpp"

long unsigned onTheWayHome (const Position& position) {
    if ((position.row == 0) or (position.column == 0)) return 1lu;
    const auto numberOfPathsToPreviousColumnPosition = onTheWayHome({position.row, position.column - 1lu});
    const auto numberOfPathsToPreviousRowPosition = onTheWayHome({position.row - 1lu, position.column});
    return numberOfPathsToPreviousRowPosition + numberOfPathsToPreviousColumnPosition;
}
