#include "dominoArrangements.hpp"

#include <string>

namespace dominoArrangements {

Grid::Grid(const Index size)
    : size(size) {
    for (auto & vectorOfOccupation : this->positionOccupied) {
        vectorOfOccupation.resize(this->size);
        std::fill(vectorOfOccupation.begin(), vectorOfOccupation.end(), false);
    }
    return;
}

Index Grid::getSize() const {
    return this->size;
}

void Grid::addDomino(const Domino & domino) {
    for (const auto & position : domino.getOccupiedPositions()) {
        this->checkPosition(position);
        if (this->positionOccupied[position.row][position.column]) {
            throw DominoArrangementError("position " + position.to_string() + " already occupied");
        }
    }
    this->dominoPieces.push_back(domino);
    for (const auto & position : domino.getOccupiedPositions()) {
        this->positionOccupied[position.row][position.column] = true;
    }
    return;
}

void Grid::checkPosition(const Position & position) {
    if (position.column >= this->size) {
        throw DominoArrangementError("invalid column position. Got " + std::to_string(position.column) + " but expected at most " + std::to_string(this->size - 1));
    }
    if (position.row >= this->rowLimit) {
        throw DominoArrangementError("invalid row position. Got " + std::to_string(position.row) + " but expected at most " + std::to_string(this->rowLimit - 1));
    }
    return;
}

void Grid::addDominoList(const DominoVector dominoVector) {
    for (const auto & domino : dominoVector) {
        this->addDomino(domino);
    }
    return;
}

char Grid::getNewChar() {
    static size_t currentIndex = 0;
    static std::array characterArray = {'a', 'b', 'c', 'd', 'e'};
    const auto ret = characterArray[currentIndex];
    currentIndex = (currentIndex + 1) % characterArray.size();
    return ret;
}

std::string Grid::to_string() const {
    std::string s;
#define ADD_HORIZONTAL_LINE                        \
    for (std::size_t i = 0; i < this->size; ++i) { \
        s += "--";                                 \
    }                                              \
    s += "-";                                      \
    s += "\n";
    // print domino pieces
    s += "Domino pieces: {\n";
    for (const auto & d : this->dominoPieces) {
        s += d.to_string() + ", ";
    }
    s += "}\n";
    // print grid and occupied positions
    ADD_HORIZONTAL_LINE
    s += "|";
    std::array<std::vector<char>, 2> charMatrix;
    for (auto & charVector : charMatrix) {
        charVector.resize(this->size);
        std::fill(charVector.begin(), charVector.end(), ' ');
    }
    for (const auto & domino : this->dominoPieces) {
        const auto c = getNewChar();
        for (const auto & position : domino.getOccupiedPositions()) {
            charMatrix[position.row][position.column] = c;
        }
    }
    std::size_t row;
    row = 0;
    for (std::size_t column = 0; column < this->size; ++column) {
        s += charMatrix[row][column];
        s += "|";
    }
    s += "\n";
    ADD_HORIZONTAL_LINE
    s += "|";
    row = 1;
    for (std::size_t column = 0; column < this->size; ++column) {
        s += charMatrix[row][column];
        s += "|";
    }
    s += "\n";
    ADD_HORIZONTAL_LINE
    return s;
}

} // namespace dominoArrangements
