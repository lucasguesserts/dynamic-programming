#include "numberSplitting.hpp"

#include <cmath>
#include <iterator>
#include <limits>

namespace NumberSplitting {

bool SubproblemSolution::operator<(SubproblemSolution const& other) const {
    return this->partition < other.partition;
}

Natural halfFloor(const Natural n) {
    const auto x = static_cast<Natural>(std::lround(std::floor(n / 2.0)));
    return x;
}

SubproblemSolution joinSolutions(const SubproblemSolution & lhs, const SubproblemSolution & rhs) {
    auto result = lhs;
    std::copy(rhs.partition.begin(), rhs.partition.end(), std::back_inserter(result.partition));
    result.cost = lhs.cost * rhs.cost;
    return result;
}

Partition DynamicProgrammingAlgorithm::solve(const Natural n) {
    if (n == 0) {
        throw std::runtime_error("n must be greater than zero");
    }
    return dpSolver(n, false).partition;
}

SubproblemSolution DynamicProgrammingAlgorithm::dpSolver(const Natural n, const bool includeLast) {
    if (n == 1) {
        return SubproblemSolution{{1}, 1};
    } else {
        SubproblemSolutionSet candidates;
        if (includeLast) {
            candidates.insert(SubproblemSolution{{n}, n});
        }
        for (Natural i = 1; i <= halfFloor(n); ++i) {
            auto lhs = dpSolver(i, true);
            auto rhs = dpSolver(n - i, true);
            auto result = joinSolutions(lhs, rhs);
            candidates.insert(result);
        }
        return selectBestCandidate(candidates);
    }
}

SubproblemSolution DynamicProgrammingAlgorithm::selectBestCandidate(const SubproblemSolutionSet & candidatesSet) {
    if (candidatesSet.empty()) {
        throw std::runtime_error("the candidates set provided is empty");
    }
    auto bestCandidate = candidatesSet.begin();
    for (auto candidateIterator = candidatesSet.begin(); candidateIterator != candidatesSet.end(); ++candidateIterator) {
        if ((*candidateIterator).cost > (*bestCandidate).cost) {
            bestCandidate = candidateIterator;
        }
    }
    return *bestCandidate;
}

}
