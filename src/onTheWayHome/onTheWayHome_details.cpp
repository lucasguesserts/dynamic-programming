#include "onTheWayHome.hpp"

#include <vector>
#include <algorithm>

void details::swapPosition(Position& position) {
    const auto row = std::min(position.row, position.column);
    const auto column = std::max(position.row, position.column);
    position.row = row;
    position.column = column;
}

bool details::columnExists (
    const long unsigned column,
    const std::vector<long unsigned> list
);

Position details::previousRow (const Position& position) {
    return {position.row - 1, position.column};
}

Position details::previousColumn (const Position& position) {
    return {position.row, position.column - 1};
}

bool details::rowExists (
    const long unsigned row,
    const std::vector<std::vector<long unsigned>> list
) {
    return row < list.size();
}

bool details::columnExists (
    const long unsigned column,
    const std::vector<long unsigned> list
) {
    return column < list.size();
}
