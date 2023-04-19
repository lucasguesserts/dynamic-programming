#include "longestIncreasingSubsequence.hpp"

namespace LongestIncreasingSubsequence {

Algorithm::Algorithm(const Sequence & sequence)
    : sequence(sequence)
    , optimalLength(0)
    , optimalSubsequences({}) {}

Index Algorithm::getOptimalLength() const noexcept {
    return this->optimalLength;
}

SequenceSet Algorithm::getOptimalSubsequences() const noexcept {
    return this->optimalSubsequences;
}

} // namespace LongestIncreasingSubsequence
