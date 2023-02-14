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
                    this->checkPosition(position);
                    if (this->positionOccupied[position.row][position.column]) {
                        throw std::runtime_error("position " + std::string(position) + " already occupied");
                    }
                }
                this->pieces.push_back(domino);
                for (const auto & position : domino.getOccupiedPositions()) {
                    this->positionOccupied[position.row][position.column] = true;
                }
                return;
            }
            void addDominoList(const std::vector<Domino> list) {
                for (const auto & d : list) {
                    this->addDomino(d);
                }
                return;
            }
            void checkPosition(const Position & position) {
                if (position.column >= this->size) {
                    throw std::runtime_error("invalid column position. Got " + std::to_string(position.column) + " but expected at most " + std::to_string(this->size-1));
                }
                if (position.row >= this->rowsLimit) {
                    throw std::runtime_error("invalid row position. Got " + std::to_string(position.row) + " but expected at most " + std::to_string(this->rowsLimit-1));
                }
                return;
            }
            static char getNewChar() {
                static size_t i = 0;
                static std::array characterArray = {'a', 'b', 'c', 'd', 'e'};
                const auto ret = characterArray[i];
                i = (i  + 1) % characterArray.size();
                return ret;
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
            };
        private:
            const Index rowsLimit = 2;
            const Index size;
            std::vector<Domino> pieces;
            std::array<std::vector<bool>, 2> positionOccupied;
    };

    using DominoVector = std::vector<Domino>;
    using DominoMatrix = std::vector<std::vector<Domino>>;

    class RecursiveAlgorithm {
        public:
            const Index size;
            std::vector<Grid> grids;

            RecursiveAlgorithm(const Index size)
                : size(size) {
                const auto allSolutions = this->solutionRecursion(this->size);
                for (const auto & solution : allSolutions) {
                    Grid grid(this->size);
                    grid.addDominoList(solution);
                    this->grids.push_back(grid);
                }
                return;
            }
            Index getNumberOfSolutions() {
                return this->grids.size();
            }
            DominoVector oneVertical(const Index column) {
                return {
                    {{0, column}, Orientation::VERTICAL}
                };
            }
            DominoVector twoVertical(const Index column) {
                return {
                    {{0, column}, Orientation::VERTICAL},
                    {{0, column+1}, Orientation::VERTICAL}
                };
            }
            DominoVector twoHorizontal(const Index column) {
                return {
                    {{0, column}, Orientation::HORIZONTAL},
                    {{1, column}, Orientation::HORIZONTAL}
                };
            }
            DominoMatrix solutionRecursion(const Index size) {
                if (size == 1) {
                    return { this->oneVertical(size-1) };
                } else if (size == 2) {
                    return {
                        twoHorizontal(size-2),
                        twoVertical(size-2)
                    };
                } else {
                    DominoMatrix solutions;
                    // 1
                    const auto x1 = this->join(
                        this->solutionRecursion(size-1),
                        oneVertical(size-1)
                    );
                    for (const auto & x : x1) {
                        solutions.push_back(x);
                    }
                    // 2
                    const auto x2 = this->join(
                        this->solutionRecursion(size-2),
                        twoHorizontal(size-2)
                    );
                    for (const auto & x : x2) {
                        solutions.push_back(x);
                    }
                    return solutions;
                }
            }
            DominoMatrix join(const DominoMatrix & lhs, const DominoVector & rhs) {
                DominoMatrix result;
                for (const auto & l : lhs) {
                    auto temp = l;
                    for (const auto & r : rhs) {
                        temp.push_back(r);
                    }
                    result.push_back(temp);
                }
                return result;
            }
            operator std::string() const {
                std::string s;
                s += "Solutions for N = " + std::to_string(this->size) + "\n";
                s += "Number of solutions = " + std::to_string(this->grids.size()) + "\n\n";
                for (Index i = 0; i < this->grids.size(); ++i) {
                    const auto & grid = this->grids[i];
                    s += "Grid " + std::to_string(i) + "\n";
                    s += std::string(grid) + "\n\n";
                }
                return s;
            }
    };

}

#endif
