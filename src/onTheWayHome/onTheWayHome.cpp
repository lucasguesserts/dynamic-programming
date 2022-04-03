#include "onTheWayHome.hpp"

#include <initializer_list>
#include <vector>
#include <algorithm>

constexpr long unsigned boundaryValue = 1lu;
const std::vector<long unsigned> newRow = { boundaryValue };

void swapPosition(Position& position);
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

long unsigned onTheWayHome (Position position) {
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
            const auto& previousRowValue = (row == 0) ? 0 : onTheWayHome(previousRow(position));
            const auto& previousColumnValue = (column == 0) ? 0 : onTheWayHome(previousColumn(position));
            const auto result = previousRowValue + previousColumnValue;
            valuesRow.push_back(result);
            return result;
        }
    } else {
        const auto& previousRowValue = (row == 0) ? 0 : onTheWayHome(previousRow(position));
        values.push_back(newRow);
        auto& valuesRow = values[row];
        const auto& previousColumnValue =(column == 0) ? 0 : onTheWayHome(previousColumn(position));
        const auto result = previousRowValue + previousColumnValue;
        valuesRow.push_back(result);
        return result;
    }
}

void swapPosition(Position& position) {
    const auto row = std::min(position.row, position.column);
    const auto column = std::max(position.row, position.column);
    position.row = row;
    position.column = column;
}
Position previousRow (const Position& position) {
    return {position.row - 1, position.column};
}
Position previousColumn (const Position& position) {
    return {position.row, position.column - 1};
}

bool rowExists (
    const long unsigned row,
    const std::vector<std::vector<long unsigned>> list
) {
    return row < list.size();
}

bool columnExists (
    const long unsigned column,
    const std::vector<long unsigned> list
) {
    return column < list.size();
}

// long unsigned onTheWayHome (const Position& position) {
//     static std::vector<std::vector<long unsigned>> values = {{ boundaryValue }};
//     // handle only half of the problem: if column > row, swap them
//     const auto& row = std::max(position.row, position.column);
//     const auto& column = std::min(position.row, position.column);
//     if (row < values.size()) {
//         auto& rowValues = values[row];
//         if (column < rowValues.size()) {
//             // case value present
//             return rowValues[column];
//         } else {
//             // case row present but column not
//             const auto numberOfPathsToPreviousColumnPosition = onTheWayHome({position.row, position.column - 1lu});
//             const auto numberOfPathsToPreviousRowPosition = onTheWayHome({position.row - 1lu, position.column});
//             const auto result = numberOfPathsToPreviousRowPosition + numberOfPathsToPreviousColumnPosition;
//             rowValues.push_back(result);
//             return result;
//         }
//     } else {
//         // case row not present
//         values.emplace_back(newRow);
//         const auto numberOfPathsToPreviousColumnPosition = onTheWayHome({position.row, position.column - 1lu});
//         const auto numberOfPathsToPreviousRowPosition = onTheWayHome({position.row - 1lu, position.column});
//         const auto result = numberOfPathsToPreviousRowPosition + numberOfPathsToPreviousColumnPosition;
//         values[row].push_back(result);
//         return result;
//     }
// }

long unsigned onTheWayHome_naive (const Position& position) {
    if ((position.row == 0) or (position.column == 0)) return 1lu;
    const auto numberOfPathsToPreviousColumnPosition = onTheWayHome_naive({position.row, position.column - 1lu});
    const auto numberOfPathsToPreviousRowPosition = onTheWayHome_naive({position.row - 1lu, position.column});
    return numberOfPathsToPreviousRowPosition + numberOfPathsToPreviousColumnPosition;
}
