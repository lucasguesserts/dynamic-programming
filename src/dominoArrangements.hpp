#ifndef DOMINO_ARRANGEMENTS_HPP_
#define DOMINO_ARRANGEMENTS_HPP_

#include <cstddef>
#include <algorithm>
#include <array>
#include <vector>
#include <stdexcept>
#include <string>

namespace dominoArrangements {

    using Index = std::size_t;

    struct Position {
        const Index row;
        const Index column;
        operator std::string() const {
            return "{" + std::to_string(this->row) + ", " + std::to_string(this->column) + "}";
        };
    };

    enum Orientation: bool {VERTICAL, HORIZONTAL};
    std::string to_string(const Orientation & orientation) {
        return orientation == Orientation::HORIZONTAL
            ? "horizontal"
            : "vertical";
    }

    struct Domino {
        const Position position;
        const Orientation orientation;
        operator std::string() const {
            return "Domino{" + std::string(this->position) + ", " + to_string(this->orientation) + "}";
        };
        std::array<Position,2> getOccupiedPositions() const {
            if (this->orientation == Orientation::HORIZONTAL) {
                return {
                    this->position,
                    {this->position.row, this->position.column + 1}
                };
            } else {
                return {
                    this->position,
                    {this->position.row + 1, this->position.column}
                };
            }
        }
    };

    class Grid {
        public:
            Grid(const Index size)
                : size(size) {
                    for(auto & v : this->positionOccupied) {
                        v.resize(this->size);
                        std::fill(v.begin(), v.end(), false);
                    }
                    return;
                };
            Index getSize() const { return this->size; };
            void addDomino(const Domino & domino) {
                for (const auto & position : domino.getOccupiedPositions()) {
                    if (this->positionOccupied[position.row][position.column]) {;
                        throw std::runtime_error("position " + std::string(position) + " already occupied");
                    }
                }
                this->pieces.push_back(domino);
                for (const auto & position : domino.getOccupiedPositions()) {
                    this->positionOccupied[position.row][position.column] = true;
                }
                return;
            }
            operator std::string() const {
                std::string s;
                std::size_t r;
                // print domino pieces
                s += "Domino pieces: {\n";
                for (const auto & d : this->pieces) {
                    s += std::string(d) + ", ";
                }
                s += "}\n";
                // print grid and occupied positions
                for (std::size_t i = 0 ; i < this->size; ++i) {
                    s += "--";
                }
                s += "-";
                s += "\n";
                s += "|";
                r = 0;
                for (std::size_t c = 0 ; c < this->size; ++c) {
                    if (this->positionOccupied[r][c]) s += "x";
                    else s += " ";
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
                    if (this->positionOccupied[r][c]) s += "x";
                    else s += " ";
                    s += "|";
                }
                s += "\n";
                for (std::size_t i = 0 ; i < this->size; ++i) {
                    s += "--";
                }
                s += "-";
                return s;
            };
        private:
            const Index size;
            std::vector<Domino> pieces;
            std::array<std::vector<bool>, 2> positionOccupied;
    };

    // class RecursiveAlgorithm {
    //     public:
    //         RecursiveAlgorithm(const Index size)
    //         : size(size) {}

    //         bool isValid() {

    //         }
    //     private:
    //         const Index size;
    // };

}

#endif
