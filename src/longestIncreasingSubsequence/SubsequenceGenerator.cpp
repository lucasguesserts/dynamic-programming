#include "longestIncreasingSubsequence.hpp"

namespace LongestIncreasingSubsequence {

SubsequenceGenerator::SubsequenceGenerator(const Sequence & sequence)
    : sequence(sequence) {
    const auto subsequenceList = this->recursiveGenerator(this->sequence.cbegin(), this->sequence.cend());
    this->subsequences = SequenceSet(subsequenceList.cbegin(), subsequenceList.cend());
}

SequenceSet SubsequenceGenerator::getSubsequences() const noexcept {
    return this->subsequences;
}

SequenceVector SubsequenceGenerator::recursiveGenerator(
    const SequenceIt begin,
    const SequenceIt end) {
    if (doesListHasOneElement(begin, end)) {
        return generateFromListOfOneElement(begin);
    } else {
        const auto onlyLastElement = generateFromListOfOneElement(end - 1);
        const auto subsequencesOfSubproblem = recursiveGenerator(begin, end - 1);
        const auto subsequencesOfSubproblemWithLastElement = appendElementToSubsequences(*(end - 1), subsequencesOfSubproblem);
        SequenceVector all;
        expandSubsequenceList(all, onlyLastElement);
        expandSubsequenceList(all, subsequencesOfSubproblem);
        expandSubsequenceList(all, subsequencesOfSubproblemWithLastElement);
        return all;
    }
}

bool SubsequenceGenerator::doesListHasOneElement(
    const SequenceIt begin,
    const SequenceIt end) noexcept {
    return begin == (end - 1);
}

SequenceVector SubsequenceGenerator::generateFromListOfOneElement(const SequenceIt begin) noexcept {
    return { { *begin } };
}

SequenceVector SubsequenceGenerator::appendElementToSubsequences(const Element element, const SequenceVector & subsequences) {
    auto copy = subsequences;
    for (auto & subsequence : copy) {
        subsequence.push_back(element);
    }
    return copy;
}

void SubsequenceGenerator::expandSubsequenceList(SequenceVector & toExpand, const SequenceVector & expansion) {
    toExpand.insert(toExpand.end(), expansion.cbegin(), expansion.cend());
    return;
}

} // namespace LongestIncreasingSubsequence
