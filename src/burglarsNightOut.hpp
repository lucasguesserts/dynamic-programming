#ifndef BLURGARS_NIGHT_OUT_HPP_
#define BLURGARS_NIGHT_OUT_HPP_

#include <vector>

using BinarySequence = std::vector<bool>;

bool is_true_alternate_sequence(const BinarySequence & b) {
    if (b.empty()) return true;
    for (auto i = 0u; i < b.size() - 1; ++i) {
        if (b[i] && b[i+1]) {
            return false;
        }
    }
    return true;
}


#endif
