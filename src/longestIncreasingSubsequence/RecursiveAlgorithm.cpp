#include "longestIncreasingSubsequence.hpp"

namespace LongestIncreasingSubsequence {

RecursiveAlgorithm::RecursiveAlgorithm(const Sequence & sequence)
: Algorithm(sequence) {
    this->makeB();
    this->makeSolutions();
    this->selectLongestSubsequences();
    return;
}

void RecursiveAlgorithm::makeB() noexcept {
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

void RecursiveAlgorithm::makeSolutions() {
    this->solutions.reserve(this->sequence.size());
    for (Index i = 0; i < this->sequence.size(); ++i) {
        this->solutions.emplace_back(this->makeSubproblemSolution(i));
    }
    return;
}

void RecursiveAlgorithm::selectLongestSubsequences() {
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

Sequence RecursiveAlgorithm::makeSubproblemSolution(const Index i) {
    SequenceList subproblemSolutions;
    for (const auto & j : this->B[i]) {
        subproblemSolutions.push_back(this->makeSubproblemSolution(j));
    }
    Sequence solution = findLongest(subproblemSolutions);
    solution.push_back(this->sequence[i]);
    return solution;
}

Sequence RecursiveAlgorithm::findLongest(const SequenceList & subsequences) {
    if (subsequences.empty()) {
        return {};
    }
    SequenceList::const_iterator longestSequence = subsequences.cbegin();
    for (auto it = subsequences.cbegin(); it != subsequences.cend(); ++it) {
        if ((*it).size() > (*longestSequence).size()) {
            longestSequence = it;
        }
    }
    return *longestSequence;
}

}
