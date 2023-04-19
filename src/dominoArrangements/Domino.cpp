#include "dominoArrangements.hpp"

#include <string>

namespace dominoArrangements {

std::string Domino::to_string() const {
    return "Domino{" + this->position.to_string() + ", " + dominoArrangements::to_string(this->orientation) + "}";
}

std::array<Position, 2> Domino::getOccupiedPositions() const {
    if (this->orientation == Orientation::HORIZONTAL) {
        return {
            this->position,
            { this->position.row, this->position.column + 1 }
        };
    } else {
        return {
            this->position,
            { this->position.row + 1, this->position.column }
        };
    }
}

} // namespace dominoArrangements
