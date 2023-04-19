#include "longestIncreasingSubsequence.hpp"

#include <utility>

namespace LongestIncreasingSubsequence {

OptimalAlgorithm::OptimalAlgorithm(const Sequence & sequence)
    : Algorithm(sequence) {
    if (sequence.empty()) {
        return;
    }
    for (const auto & element : this->sequence) {
        this->expand(element);
    }
    this->optimalLength = this->activeLists.front().size();
    this->optimalSubsequences = {
        this->activeLists.front()
    };
    return;
}

void OptimalAlgorithm::expand(const Element & element) {
    if (this->activeLists.empty()) {
        this->activeLists.push_front({ element });
        return;
    }
    bool isSmallest = true;
    bool isLargest;
    SequenceList::const_iterator it;
    const auto & largestElement = this->activeLists.front().back();
    if (element > largestElement) {
        isLargest = true;
        isSmallest = false;
    } else {
        isLargest = false;
        for (it = this->activeLists.cbegin(); it != this->activeLists.cend(); ++it) {
            const auto & candidate = *it;
            const auto & largestValueOfCandidate = candidate.back();
            if (element > largestValueOfCandidate) {
                isSmallest = false;
                break;
            }
        }
    }
    if (isSmallest) {
        // case 1: 'element' is the smallest among all ends of candidates of active lists,
        // we will start a new list of length 1.
        this->activeLists.remove_if(
            [](const Sequence & s) {
                return s.size() == 1;
            });
        this->activeLists.push_back({ element });
    } else if (isLargest) {
        // case 2: ;element' is the largest among all ends of candidates of active lists,
        // we will clone the largest active list and extend it by 'element'.
        auto currentLargestCandidate = this->activeLists.front();
        currentLargestCandidate.push_back(element);
        this->activeLists.emplace_front(std::move(currentLargestCandidate));
        return;
    } else {
        // case 3: 'element' is in between
        // we will find a list with largest element that is smaller than 'element'.
        // Clone and extend that list by 'element'.
        // We will discard all other lists of same length as that of this modified list.
        // The iterator points to that exact candidate.
        auto newCandidate = *it;
        newCandidate.push_back(element);
        this->activeLists.insert(it, newCandidate);
        const Index sizeOfNewCandidate = newCandidate.size();
        // iterate reverse: remove all lists with the same size
        this->activeLists.remove_if(
            [&sizeOfNewCandidate, &element](const Sequence & s) {
                return s.back() > element && (s.size() == sizeOfNewCandidate);
            });
    }
}

} // namespace LongestIncreasingSubsequence
