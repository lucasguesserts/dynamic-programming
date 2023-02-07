#include "longestIncreasingSubsequence.hpp"

namespace LongestIncreasingSubsequence {

SubsequenceGenerator::SubsequenceGenerator(const Sequence & sequence)
    : sequence(sequence) {
    this->subsequences = this->recursiveGenerator(this->sequence.begin(), this->sequence.end());
}

SequenceList SubsequenceGenerator::getSubsequences() const noexcept {
    return this->subsequences;
}

SequenceList SubsequenceGenerator::recursiveGenerator(
    SequenceIt begin,
    SequenceIt end
) {
    if (doesListHasOneElement(begin, end)) {
        return generateFromListOfOneElement(begin);
    } else {
        auto subsequenceWithLastElement = generateFromListOfOneElement(end-1);
        auto subsequencesOfSubproblem = recursiveGenerator(begin, end-1);
        auto subsequencesOfSubproblemWithLastElement = appendElementToSubsequences(*(end-1), subsequencesOfSubproblem);
        SequenceList all;
        expandSubsequenceList(all, subsequenceWithLastElement);
        expandSubsequenceList(all, subsequencesOfSubproblem);
        expandSubsequenceList(all, subsequencesOfSubproblemWithLastElement);
        return all;
    }
}

bool SubsequenceGenerator::doesListHasOneElement(
    SequenceIt begin,
    SequenceIt end
) {
    return begin == (end-1);
}

SequenceList SubsequenceGenerator::generateFromListOfOneElement(SequenceIt begin) {
    return {{*begin}};
}

SequenceList SubsequenceGenerator::appendElementToSubsequences(Element element, SequenceList & subsequences) {
    auto copy = subsequences;
    for (auto & subsequence: copy) {
        subsequence.push_back(element);
    }
    return copy;
}

void SubsequenceGenerator::expandSubsequenceList(SequenceList & toExpand, SequenceList & expansion) {
    for (auto & subsequence : expansion) {
        toExpand.push_back(subsequence);
    }
    return;
}

NaiveAlgorithm::NaiveAlgorithm(const Sequence & sequence)
    : sequence(sequence) {}


unsigned NaiveAlgorithm::getOptimalLength() const noexcept {
    return 0u;
}

SequenceList NaiveAlgorithm::getOptimalSublists() const noexcept {
    return {};
}

}
