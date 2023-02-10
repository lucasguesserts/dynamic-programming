#include "longestIncreasingSubsequence.hpp"

#include <algorithm>
#include <functional>

namespace LongestIncreasingSubsequence {

NaiveAlgorithm::NaiveAlgorithm(const Sequence & sequence)
: Algorithm(sequence) {
    if (sequence.empty()) {
        return;
    }
    this->selectIncreasingSubsequences();
    this->selectLongestSubsequences();
    return;
}

bool NaiveAlgorithm::isSequenceIncreasing(const Sequence & sequence) {
    for (SequenceIt it = sequence.cbegin() + 1; it != sequence.cend(); ++it) {
        if (*(it-1) >= *it) {
            return false;
        }
    }
    return true;
}

void NaiveAlgorithm::selectIncreasingSubsequences() {
    const SubsequenceGenerator generator(this->sequence);
    for (const auto & sequence : generator.getSubsequences()) {
        if (isSequenceIncreasing(sequence)) {
            this->increasingSubsequences.insert(sequence);
        }
    }
    return;
}

void NaiveAlgorithm::selectLongestSubsequences() {
    Index currentLongestLength = 0;
    SequenceSet currentLongestSubsequences;
    for (const auto & sequence : this->increasingSubsequences) {
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

}
