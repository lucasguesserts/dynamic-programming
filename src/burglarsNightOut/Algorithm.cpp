#include "burglarsNightOut.hpp"

#include <iterator>
#include <limits>
#include <vector>

namespace BurglarsNightOut {

auto Algorithm::is_true_alternate_sequence(const BinarySequence & b) -> bool {
    if (b.empty()) return true;
    return std::adjacent_find(
               b.begin(),
               b.end(),
               [](bool a, bool b) { return a && b; })
        == b.end();
}

auto Algorithm::cost_of_sequence(const BinarySequence & b, const RealSequence & r) -> Cost {
    if (b.size() != r.size()) {
        throw std::runtime_error("the binary and real sequences must have the same size");
    }
    return std::inner_product(b.begin(), b.end(), r.begin(), 0.0);
}

} // namespace BurglarsNightOut
