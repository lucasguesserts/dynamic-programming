#include "longestIncreasingSubsequence.hpp"

#include <vector>

namespace LongestIncreasingSubsequence {

DynamicProgrammingAlgorithm::DynamicProgrammingAlgorithm(const Sequence & sequence)
: RecursiveAlgorithm(sequence) {
    this->makeB();
    this->makeSolutions();
    this->selectLongestSubsequences();
    return;
}

Sequence DynamicProgrammingAlgorithm::makeSubproblemSolution(const Index i) {
    if (!this->solutions[i].empty()) {
        return this->solutions[i];
    } else {
        std::vector<Sequence> subproblemSolutions;
        for (const auto & j : this->B[i]) {
            subproblemSolutions.push_back(this->makeSubproblemSolution(j));
        }
        Sequence solution = findLongest(subproblemSolutions);
        solution.push_back(this->sequence[i]);
        return solution;
    }
}

}
