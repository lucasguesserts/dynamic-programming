#include "longestIncreasingSubsequence.hpp"

namespace LongestIncreasingSubsequence {

NaiveAlgorithm::NaiveAlgorithm(const Sequence & sequence)
    : sequence(sequence) {}


unsigned NaiveAlgorithm::getOptimalLength() const noexcept {
    return 0u;
}

SequenceList NaiveAlgorithm::getOptimalSubsequences() const noexcept {
    return {};
}

}
