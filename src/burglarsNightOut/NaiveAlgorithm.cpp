#include "burglarsNightOut.hpp"

#include <vector>

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
