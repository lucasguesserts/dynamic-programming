#include "stairwayToHeaven2.hpp"

#include <stdexcept>

namespace StairwayToHeaven2 {

void Algorithm::check_input(const Size number_of_steps, const Size step_limit, const Fees & fees) const {
    if (fees.size() != number_of_steps) {
        throw std::runtime_error("number of fees does not match with the number of steps");
    }
    if (step_limit > number_of_steps) {
        throw std::runtime_error("step limit is larger than the number of steps");
    }
    return;
}

Fee Algorithm::compute_sequence_cost(const Sequence & sequence, const Fees & fees) const {
    Size current_index = 0;
    Fee total = fees[0];
    for (Size i = 0; i < sequence.size() - 1; ++i) {
        current_index += sequence[i];
        total += fees[current_index];
    }
    return total;
}

} // namespace StairwayToHeaven2
