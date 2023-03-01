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

}
