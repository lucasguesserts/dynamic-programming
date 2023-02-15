#include "dominoArrangements.hpp"

#include <string>

namespace dominoArrangements {

Grid::Grid(const Index size)
: size(size) {
    for(auto & v : this->positionOccupied) {
        v.resize(this->size);
        std::fill(v.begin(), v.end(), false);
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
            throw std::runtime_error("position " + position.to_string() + " already occupied");
        }
    }
    this->pieces.push_back(domino);
    for (const auto & position : domino.getOccupiedPositions()) {
        this->positionOccupied[position.row][position.column] = true;
    }
    return;
}

void Grid::checkPosition(const Position & position) {
    if (position.column >= this->size) {
        throw std::runtime_error("invalid column position. Got " + std::to_string(position.column) + " but expected at most " + std::to_string(this->size-1));
    }
    if (position.row >= this->rowsLimit) {
        throw std::runtime_error("invalid row position. Got " + std::to_string(position.row) + " but expected at most " + std::to_string(this->rowsLimit-1));
    }
    return;
}

void Grid::addDominoList(const std::vector<Domino> list) {
    for (const auto & d : list) {
        this->addDomino(d);
    }
    return;
}

char Grid::getNewChar() {
    static size_t i = 0;
    static std::array characterArray = {'a', 'b', 'c', 'd', 'e'};
    const auto ret = characterArray[i];
    i = (i  + 1) % characterArray.size();
    return ret;
}

std::string Grid::to_string() const {
    std::string s;
    std::size_t r;
    // print domino pieces
    s += "Domino pieces: {\n";
    for (const auto & d : this->pieces) {
        s += d.to_string() + ", ";
    }
    s += "}\n";
    // print grid and occupied positions
    for (std::size_t i = 0 ; i < this->size; ++i) {
        s += "--";
    }
    s += "-";
    s += "\n";
    s += "|";
    std::array<std::vector<char>,2> charMatrix;
    for (auto & m : charMatrix) {
        m.resize(this->size);
        std::fill(m.begin(), m.end(), ' ');
    }
    for (const auto & d : this->pieces) {
        const auto c = getNewChar();
        for (const auto & p : d.getOccupiedPositions()) {
            charMatrix[p.row][p.column] = c;
        }
    }
    r = 0;
    for (std::size_t c = 0 ; c < this->size; ++c) {
        s += charMatrix[r][c];
        s += "|";
    }
    s += "\n";
    for (std::size_t i = 0 ; i < this->size; ++i) {
        s += "--";
    }
    s += "-";
    s += "\n";
    s += "|";
    r = 1;
    for (std::size_t c = 0 ; c < this->size; ++c) {
        s += charMatrix[r][c];
        s += "|";
    }
    s += "\n";
    for (std::size_t i = 0 ; i < this->size; ++i) {
        s += "--";
    }
    s += "-";
    return s;
}

}
