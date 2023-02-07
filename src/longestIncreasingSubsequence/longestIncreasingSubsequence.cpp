#include "longestIncreasingSubsequence.hpp"

namespace LongestIncreasingSubsequence {

SubsequenceGenerator::SubsequenceGenerator(const std::vector<double> & sequence)
    : sequence(sequence) {
    this->subsequences = this->recursiveGenerator(this->sequence.begin(), this->sequence.end());
}

std::vector<std::vector<double>> SubsequenceGenerator::getSubsequences() const noexcept {
    return this->subsequences;
}

std::vector<std::vector<double>> SubsequenceGenerator::recursiveGenerator(
    std::vector<double>::iterator begin,
    std::vector<double>::iterator end
) {
    if (doesListHasOneElement(begin, end)) {
        return generateFromListOfOneElement(begin);
    } else {
        auto subsequenceWithLastElement = generateFromListOfOneElement(end-1);
        auto subsequencesOfSubproblem = recursiveGenerator(begin, end-1);
        auto subsequencesOfSubproblemWithLastElement = appendElementToSubsequences(*(end-1), subsequencesOfSubproblem);
        std::vector<std::vector<double>> all;
        expandSubsequenceList(all, subsequenceWithLastElement);
        expandSubsequenceList(all, subsequencesOfSubproblem);
        expandSubsequenceList(all, subsequencesOfSubproblemWithLastElement);
        return all;
    }
}

bool SubsequenceGenerator::doesListHasOneElement(
    std::vector<double>::iterator begin,
    std::vector<double>::iterator end
) {
    return begin == (end-1);
}

std::vector<std::vector<double>> SubsequenceGenerator::generateFromListOfOneElement(std::vector<double>::iterator begin) {
    return {{*begin}};
}

std::vector<std::vector<double>> SubsequenceGenerator::appendElementToSubsequences(double element, std::vector<std::vector<double>> & subsequences) {
    auto copy = subsequences;
    for (auto & subsequence: copy) {
        subsequence.push_back(element);
    }
    return copy;
}

void SubsequenceGenerator::expandSubsequenceList(std::vector<std::vector<double>> & toExpand, std::vector<std::vector<double>> & expansion) {
    for (auto & subsequence : expansion) {
        toExpand.push_back(subsequence);
    }
    return;
}

NaiveAlgorithm::NaiveAlgorithm(const std::vector<double> & sequence)
    : sequence(sequence) {}


unsigned NaiveAlgorithm::getOptimalLength() const noexcept {
    return 0u;
}

std::vector<std::vector<double>> NaiveAlgorithm::getOptimalSublists() const noexcept {
    return {};
}

}
