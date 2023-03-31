#include "burglarsNightOut.hpp"

#include <vector>
#include <iterator>
#include <limits>

namespace BurglarsNightOut {

std::vector<BinarySequence> NaiveAlgorithm::generateAllBinarySequences(const Size n) {
    std::vector<BinarySequence> allVectors;
    if (n == 0) {
        allVectors.push_back({});
    } else {
        std::vector<BinarySequence> previousSequences = generateAllBinarySequences(n-1);
        for (Size i = 0; i < previousSequences.size(); ++i) {
            BinarySequence newSequence = previousSequences[i];
            newSequence.push_back(false);
            allVectors.push_back(newSequence);
            newSequence.back() = true;
            allVectors.push_back(newSequence);
        }
    }
    return allVectors;
}

std::vector<BinarySequence> NaiveAlgorithm::filterTrueAlternateSequences(const std::vector<BinarySequence> & binarySequences) {
    std::vector<BinarySequence> trueAlternateSequences;
    std::copy_if(
        binarySequences.cbegin(),
        binarySequences.cend(),
        std::back_inserter(trueAlternateSequences),
        [](const BinarySequence & b) { return isTrueAlternateSequence(b); }
    );
    return trueAlternateSequences;
}



BinarySequence NaiveAlgorithm::selectMostExpensiveSequence(const std::vector<BinarySequence> & binarySequences, const RealSequence & costs) {
    if (binarySequences.empty()) {
        return {};
    }
    Cost largestCost = std::numeric_limits<Cost>::lowest();
    const BinarySequence * bestSequence;
    for (const auto & sequence : binarySequences) {
        const Cost currentCost = costOfSequence(sequence, costs);
        if (currentCost > largestCost) {
            largestCost = currentCost;
            bestSequence = &sequence;
        }
    }
    return *bestSequence;
}

}
