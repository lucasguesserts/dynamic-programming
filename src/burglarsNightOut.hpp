#ifndef BLURGARS_NIGHT_OUT_HPP_
#define BLURGARS_NIGHT_OUT_HPP_

#include <cstddef>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>

using Size = std::size_t;
using BinarySequence = std::vector<bool>;
using Cost = double;
using RealSequence = std::vector<Cost>;

bool isTrueAlternateSequence(const BinarySequence &b) {
    if (b.empty()) return true;
    return std::adjacent_find(b.begin(), b.end(), [](bool a, bool b){ return a && b; }) == b.end();
}

Cost costOfSequence(const BinarySequence &b, const RealSequence &r) {
    if (b.size() != r.size()) {
        throw std::runtime_error("the binary and real sequences must have the same size");
    }
    return std::inner_product(b.begin(), b.end(), r.begin(), 0.0);
}

class NaiveAlgorithm {
    private:
        static std::vector<BinarySequence> generateAllBinarySequences(const Size n);
        static std::vector<BinarySequence> filterTrueAlternateSequences(const std::vector<BinarySequence> & binarySequences);
};

#endif
