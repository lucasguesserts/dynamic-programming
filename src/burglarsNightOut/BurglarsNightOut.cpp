#include "burglarsNightOut.hpp"

#include <iterator>
#include <limits>
#include <vector>

namespace BurglarsNightOut {

bool isTrueAlternateSequence(const BinarySequence & b) {
    if (b.empty()) return true;
    return std::adjacent_find(
               b.begin(),
               b.end(),
               [](bool a, bool b) { return a && b; })
        == b.end();
}

Cost costOfSequence(const BinarySequence & b, const RealSequence & r) {
    if (b.size() != r.size()) {
        throw std::runtime_error("the binary and real sequences must have the same size");
    }
    return std::inner_product(b.begin(), b.end(), r.begin(), 0.0);
}

} // namespace BurglarsNightOut
