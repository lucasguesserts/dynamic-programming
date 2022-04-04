#include "onTheWayHome.hpp"

#include <vector>
#include <algorithm>

Position details::onTheWayHome::swapPosition(const Position& position) {
    const auto row = std::min(position.row, position.column);
    const auto column = std::max(position.row, position.column);
    return {row, column};
}

bool details::onTheWayHome::columnExists (
    const long unsigned column,
    const std::vector<long unsigned> list
);

Position details::onTheWayHome::previousRow (const Position& position) {
    return {position.row - 1, position.column};
}

Position details::onTheWayHome::previousColumn (const Position& position) {
    return {position.row, position.column - 1};
}

bool details::onTheWayHome::rowExists (
    const long unsigned row,
    const std::vector<std::vector<long unsigned>> list
) {
    return row < list.size();
}

bool details::onTheWayHome::columnExists (
    const long unsigned column,
    const std::vector<long unsigned> list
) {
    return column < list.size();
}
