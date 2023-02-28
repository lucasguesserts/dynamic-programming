#ifndef STAIRWAY_TO_HEAVEN_2_HPP_
#define STAIRWAY_TO_HEAVEN_2_HPP_

#include <cstddef>
#include <vector>

namespace StairwayToHeaven2 {

    using Size = std::size_t;
    using Step = std::size_t;
    using Fees = std::vector<double>;
    using Sequence = std::vector<Step>;
    using SequenceVector = std::vector<Sequence>;

    Sequence naiveAlgorithm(const Size number_of_steps, const Size step_limit, const Fees & fees);

}

#endif
