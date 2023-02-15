#include "dominoArrangements.hpp"

#include <string>

namespace dominoArrangements {

RecursiveAlgorithm::RecursiveAlgorithm(const Index size)
    : size(size) {
    const auto allSolutions = this->solutionRecursion(this->size);
    for (const auto & solution : allSolutions) {
        Grid grid(this->size);
        grid.addDominoList(solution);
        this->grids.push_back(grid);
    }
    return;
}

Index RecursiveAlgorithm::getNumberOfSolutions() {
    return this->grids.size();
}

DominoVector RecursiveAlgorithm::oneVertical(const Index column) {
    return {
        {{0, column}, Orientation::VERTICAL}
    };
}

DominoVector RecursiveAlgorithm::twoVertical(const Index column) {
    return {
        {{0, column}, Orientation::VERTICAL},
        {{0, column+1}, Orientation::VERTICAL}
    };
}

DominoVector RecursiveAlgorithm::twoHorizontal(const Index column) {
    return {
        {{0, column}, Orientation::HORIZONTAL},
        {{1, column}, Orientation::HORIZONTAL}
    };
}

DominoMatrix RecursiveAlgorithm::solutionRecursion(const Index size) {
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

std::string RecursiveAlgorithm::to_string() const {
    std::string s;
    s += "Solutions for N = " + std::to_string(this->size) + "\n";
    s += "Number of solutions = " + std::to_string(this->grids.size()) + "\n\n";
    for (Index i = 0; i < this->grids.size(); ++i) {
        const auto & grid = this->grids[i];
        s += "Grid " + std::to_string(i) + "\n";
        s += grid.to_string() + "\n\n";
    }
    return s;
}

}
