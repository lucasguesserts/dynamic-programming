#include "onTheWayHome.hpp"

#include <vector>

const std::vector<long unsigned> OnTheWayHome::newRow = {};
std::vector<std::vector<long unsigned>> OnTheWayHome::values {{ boundaryValue }};

long unsigned OnTheWayHome::compute (Position position) {
    if (positionExists(position)) {
        return getValue(position);
    } else {
        const auto& previousRowValue = getPreviousRowValue(position);
        addRowIfItDoesntExist(position);
        const auto& previousColumnValue = getPreviousColumnValue(position);
        const auto value = previousRowValue + previousColumnValue;
        addValue(value, position);
        return value;
    }
}

long unsigned OnTheWayHome::getPreviousRowValue (const Position& referencePosition) {
    if (referencePosition.row == 0) return outOfRangeValue;
    const Position position = previousRow(referencePosition);
    if (positionExists(position)) {
        return getValue(position);
    } else {
        const auto& previousRowValue = getPreviousRowValue(position);
        addRowIfItDoesntExist(position);
        const auto& previousColumnValue = getPreviousColumnValue(position);
        const auto value = previousRowValue + previousColumnValue;
        addValue(value, position);
        return value;
    }
}

long unsigned OnTheWayHome::getPreviousColumnValue (const Position& referencePosition) {
    // condition: row exists
    if (referencePosition.column == 0) return outOfRangeValue;
    const Position position = previousColumn(referencePosition);
    if (positionExists(position)) {
        return getValue(position);
    } else {
        const auto& previousRowValue = getPreviousRowValue(position);
        const auto& previousColumnValue = getPreviousColumnValue(position);
        const auto value = previousRowValue + previousColumnValue;
        addValue(value, position);
        return value;
    }
}

void OnTheWayHome::addValue(
    const long unsigned& value,
    const Position& position
) {
    values[position.row].push_back(value);
}

void OnTheWayHome::addRowIfItDoesntExist (const Position& position) {
    if (!rowExists(position)) {
        values.push_back(newRow);
    }
}

long unsigned OnTheWayHome::getValue (const Position& position) {
    // condition: position exists
    return values[position.row][position.column];
}

bool OnTheWayHome::positionExists (const Position& position) {
    return rowExists(position) and columnExists(position);
}

bool OnTheWayHome::rowExists (const Position& position) {
    return position.row < values.size();
}

bool OnTheWayHome::columnExists (const Position& position) {
    // condition: row must exist
    return position.column < values[position.row].size();
}

Position OnTheWayHome::previousRow(const Position& position) {
    return {position.row - 1, position.column};
}

Position OnTheWayHome::previousColumn(const Position& position) {
    return {position.row, position.column - 1};
}
