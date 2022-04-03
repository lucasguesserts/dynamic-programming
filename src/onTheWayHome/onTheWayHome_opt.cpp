#include "onTheWayHome.hpp"

#include <vector>

using details::swapPosition;
using details::previousRow;
using details::previousColumn;
using details::rowExists;
using details::columnExists;

long unsigned onTheWayHome_opt (Position position) {
    static constexpr long unsigned boundaryValue = 1lu;
    static const std::vector<long unsigned> newRow = { boundaryValue };
    static std::vector<std::vector<long unsigned>> values {{ boundaryValue }};
    // handle only half of the problem: if row > column, swap them
    swapPosition(position);
    const auto& row = position.row;
    const auto& column = position.column;
    if (rowExists(row, values)) {
        auto& valuesRow = values[row];
        if (columnExists(column, valuesRow)) {
            return valuesRow[column];
        } else {
            const auto& previousRowValue = (row == 0) ? 0 : onTheWayHome_opt(previousRow(position));
            const auto& previousColumnValue = (column == 0) ? 0 : onTheWayHome_opt(previousColumn(position));
            const auto result = previousRowValue + previousColumnValue;
            valuesRow.push_back(result);
            return result;
        }
    } else {
        const auto& previousRowValue = (row == 0) ? 0 : onTheWayHome_opt(previousRow(position));
        values.push_back(newRow);
        auto& valuesRow = values[row];
        const auto& previousColumnValue =(column == 0) ? 0 : onTheWayHome_opt(previousColumn(position));
        const auto result = previousRowValue + previousColumnValue;
        if (column != 0) valuesRow.push_back(result);
        return result;
    }
}
