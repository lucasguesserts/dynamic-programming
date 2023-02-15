#include "dominoArrangements.hpp"

#include <string>

namespace dominoArrangements {

RecursiveAlgorithm::RecursiveAlgorithm(const Index size)
    : size(size) {
    const auto allSolutions = this->solve(this->size);
    for (const auto & solution : allSolutions) {
        Grid grid(this->size);
        grid.addDominoList(solution);
        this->solvedGrids.push_back(grid);
    }
    return;
}

Index RecursiveAlgorithm::getNumberOfSolutions() {
    return this->solvedGrids.size();
}

std::string RecursiveAlgorithm::to_string() const {
    std::string s;
    s += "Solutions for N = " + std::to_string(this->size) + "\n";
    s += "Number of solutions = " + std::to_string(this->solvedGrids.size()) + "\n\n";
    for (Index i = 0; i < this->solvedGrids.size(); ++i) {
        const auto & grid = this->solvedGrids[i];
        s += "Grid " + std::to_string(i) + "\n";
        s += grid.to_string() + "\n\n";
    }
    return s;
}

DominoVector RecursiveAlgorithm::oneVerticalDominoAt(const Index column) {
    return {
        {{0, column}, Orientation::VERTICAL}
    };
}

DominoVector RecursiveAlgorithm::twoVerticalDominosAt(const Index column) {
    return {
        {{0, column}, Orientation::VERTICAL},
        {{0, column+1}, Orientation::VERTICAL}
    };
}

DominoVector RecursiveAlgorithm::twoHorizontalDominosAt(const Index column) {
    return {
        {{0, column}, Orientation::HORIZONTAL},
        {{1, column}, Orientation::HORIZONTAL}
    };
}

DominoMatrix RecursiveAlgorithm::solve(const Index size) {
    if (size == 1) {
        return { this->oneVerticalDominoAt(size-1) };
    } else if (size == 2) {
        return {
            twoHorizontalDominosAt(size-2),
            twoVerticalDominosAt(size-2)
        };
    } else {
        DominoMatrix solutions;
        // vertical part
        const auto solutionVerticalPart = this->join(
            this->solve(size-1),
            oneVerticalDominoAt(size-1)
        );
        for (const auto & s : solutionVerticalPart) {
            solutions.push_back(s);
        }
        // horizontal part
        const auto solutionHorizontalPart = this->join(
            this->solve(size-2),
            twoHorizontalDominosAt(size-2)
        );
        for (const auto & s : solutionHorizontalPart) {
            solutions.push_back(s);
        }
        return solutions;
    }
}

DominoMatrix RecursiveAlgorithm::join(const DominoMatrix & lhs, const DominoVector & rhs) {
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

}
