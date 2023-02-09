#include "longestIncreasingSubsequence.hpp"

#include <vector>

namespace LongestIncreasingSubsequence {

DynamicProgrammingAlgorithm::DynamicProgrammingAlgorithm(const Sequence & sequence)
: sequence(sequence) {
    this->makeB();
    this->makeSolutions();
    this->selectLongestSubsequences();
    return;
}


Index DynamicProgrammingAlgorithm::getOptimalLength() const noexcept {
    return this->optimalLength;
}

SequenceSet DynamicProgrammingAlgorithm::getOptimalSubsequences() const noexcept {
    return this->optimalSubsequences;
}

void DynamicProgrammingAlgorithm::makeB() noexcept {
    this->B.resize(this->sequence.size());
    for(Index i = 0; i < this->sequence.size(); ++i) {
        for (Index j = 0; j < i; ++j) {
            if (this->sequence[j] < this->sequence[i]) {
                this->B[i].insert(j);
            }
        }
    }
    return;
}

void DynamicProgrammingAlgorithm::makeSolutions() {
    this->solutions.resize(this->sequence.size());
    for (Index i = 0; i < this->sequence.size(); ++i) {
        this->solutions[i] = this->makeSubproblemSolution(i);
    }
    return;
}

void DynamicProgrammingAlgorithm::selectLongestSubsequences() {
    Index currentLongestLength = 0;
    SequenceSet currentLongestSubsequences;
    for (const auto & sequence : this->solutions) {
        if (sequence.size() > currentLongestLength) {
            currentLongestLength = sequence.size();
            currentLongestSubsequences.clear();
            currentLongestSubsequences.insert(sequence);
        } else if (sequence.size() == currentLongestLength) {
            currentLongestSubsequences.insert(sequence);
        }
    }
    this->optimalLength = currentLongestLength;
    this->optimalSubsequences = currentLongestSubsequences;
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

Sequence DynamicProgrammingAlgorithm::findLongest(const std::vector<Sequence> & subsequences) {
    if (subsequences.empty()) {
        return {};
    }
    auto longestSequence = subsequences.cbegin();
    for (auto it = subsequences.cbegin(); it != subsequences.cend(); ++it) {
        if ((*it).size() > (*longestSequence).size()) {
            longestSequence = it;
        }
    }
    return *longestSequence;
}

}
