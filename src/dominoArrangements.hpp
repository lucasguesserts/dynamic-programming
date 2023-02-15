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

        std::string to_string() const;
    };

    enum Orientation: bool {VERTICAL, HORIZONTAL};
    std::string to_string(const Orientation & orientation);

    struct Domino {
        const Position position;
        const Orientation orientation;

        std::string to_string() const;
        std::array<Position,2> getOccupiedPositions() const;
    };

    class Grid {
        public:
            Grid(const Index size);
            Index getSize() const;
            void addDominoList(const std::vector<Domino> list);
            std::string to_string() const;
        private:
            const Index rowsLimit = 2;
            const Index size;
            std::vector<Domino> pieces;
            std::array<std::vector<bool>, 2> positionOccupied;

            void addDomino(const Domino & domino);
            void checkPosition(const Position & position);
            static char getNewChar();
    };

    using DominoVector = std::vector<Domino>;
    using DominoMatrix = std::vector<std::vector<Domino>>;

    class RecursiveAlgorithm {
        public:
            const Index size;
            std::vector<Grid> grids;

            RecursiveAlgorithm(const Index size);
            Index getNumberOfSolutions();
            DominoVector oneVertical(const Index column);
            DominoVector twoVertical(const Index column);
            DominoVector twoHorizontal(const Index column);
            DominoMatrix solutionRecursion(const Index size);
            DominoMatrix join(const DominoMatrix & lhs, const DominoVector & rhs);
            std::string to_string() const;
    };

}

#endif
