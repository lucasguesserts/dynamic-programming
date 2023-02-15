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

    using DominoVector = std::vector<Domino>;
    using DominoMatrix = std::vector<std::vector<Domino>>;

    class DominoArrangementError: public std::runtime_error {
        public:
            DominoArrangementError(std::string s);
    };

    class Grid {
        public:
            Grid(const Index size);
            Index getSize() const;
            void addDominoList(const DominoVector list);
            std::string to_string() const;
        private:
            const Index rowLimit = 2;
            const Index size;
            DominoVector dominoPieces;
            std::array<std::vector<bool>, 2> positionOccupied;

            void addDomino(const Domino & domino);
            void checkPosition(const Position & position);
            static char getNewChar();
    };

    class RecursiveAlgorithm {
        public:
            const Index size;
            std::vector<Grid> solvedGrids;

            RecursiveAlgorithm(const Index size);
            Index getNumberOfSolutions();
            std::string to_string() const;
        private:
            DominoVector oneVerticalDominoAt(const Index column);
            DominoVector twoVerticalDominosAt(const Index column);
            DominoVector twoHorizontalDominosAt(const Index column);
            DominoMatrix solve(const Index size);
            DominoMatrix join(const DominoMatrix & lhs, const DominoVector & rhs);
    };

}

#endif
