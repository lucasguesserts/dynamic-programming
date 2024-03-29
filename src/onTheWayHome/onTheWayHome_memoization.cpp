#include "onTheWayHome.hpp"

#include <vector>

using details::onTheWayHome::columnExists;
using details::onTheWayHome::previousColumn;
using details::onTheWayHome::previousRow;
using details::onTheWayHome::rowExists;
using details::onTheWayHome::swapPosition;

long unsigned onTheWayHome_memoization(const Position & position) {
    static constexpr long unsigned boundaryValue = 1lu;
    static const std::vector<long unsigned> newRow = {};
    static std::vector<std::vector<long unsigned>> values{{boundaryValue}};
    // handle only half of the problem: if row > column, swap them
    // const auto position = swapPosition(pos);
    const auto & row = position.row;
    const auto & column = position.column;
    if (rowExists(row, values)) {
        auto & valuesRow = values[row];
        if (columnExists(column, valuesRow)) {
            return valuesRow[column];
        } else {
            const auto & previousRowValue = (row == 0) ? 0 : onTheWayHome_memoization(previousRow(position));
            const auto & previousColumnValue = (column == 0) ? 0 : onTheWayHome_memoization(previousColumn(position));
            const auto result = previousRowValue + previousColumnValue;
            valuesRow.push_back(result);
            return result;
        }
    } else {
        const auto & previousRowValue = (row == 0) ? 0 : onTheWayHome_memoization(previousRow(position));
        values.push_back(newRow);
        auto & valuesRow = values[row];
        const auto & previousColumnValue = (column == 0) ? 0 : onTheWayHome_memoization(previousColumn(position));
        const auto result = previousRowValue + previousColumnValue;
        if (column != 0) valuesRow.push_back(result);
        return result;
    }
}
