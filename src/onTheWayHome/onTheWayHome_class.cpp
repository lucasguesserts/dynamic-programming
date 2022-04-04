#include "onTheWayHome.hpp"

#include <vector>

using details::onTheWayHome::swapPosition;
using details::onTheWayHome::previousRow;
using details::onTheWayHome::previousColumn;
using details::onTheWayHome::rowExists;
using details::onTheWayHome::columnExists;

const std::vector<long unsigned> OnTheWayHome::newRow = { boundaryValue };
std::vector<std::vector<long unsigned>> OnTheWayHome::values {{ boundaryValue }};

long unsigned OnTheWayHome::compute (Position position) {
    const auto& row = position.row;
    const auto& column = position.column;
    if (rowExists(row, values)) {
        auto& valuesRow = values[row];
        if (columnExists(column, valuesRow)) {
            return valuesRow[column];
        } else {
            const auto& previousRowValue = (row == 0) ? 0 : OnTheWayHome::compute(previousRow(position));
            const auto& previousColumnValue = (column == 0) ? 0 : OnTheWayHome::compute(previousColumn(position));
            const auto result = previousRowValue + previousColumnValue;
            valuesRow.push_back(result);
            return result;
        }
    } else {
        const auto& previousRowValue = (row == 0) ? 0 : OnTheWayHome::compute(previousRow(position));
        values.push_back(newRow);
        auto& valuesRow = values[row];
        const auto& previousColumnValue =(column == 0) ? 0 : OnTheWayHome::compute(previousColumn(position));
        const auto result = previousRowValue + previousColumnValue;
        if (column != 0) valuesRow.push_back(result);
        return result;
    }
}
