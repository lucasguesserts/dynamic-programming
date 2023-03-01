#ifndef STAIRWAY_TO_HEAVEN_2_HPP_
#define STAIRWAY_TO_HEAVEN_2_HPP_

#include <cstddef>
#include <vector>
#include <memory>

namespace StairwayToHeaven2 {

    using Size = std::size_t;
    using Step = std::size_t;
    using Fee = double;
    using Fees = std::vector<Fee>;
    using Sequence = std::vector<Step>;
    using SequenceVector = std::vector<Sequence>;

    class Algorithm {
        public:
            virtual Sequence solve(const Size number_of_steps, const Size step_limit, const Fees & fees) const = 0;
        protected:
            void check_input(const Size number_of_steps, const Size step_limit, const Fees & fees) const;
    };

    using AlgorithmPtr = std::unique_ptr<Algorithm>;

    class NaiveAlgorithm: public Algorithm {
        public:
            virtual Sequence solve(const Size number_of_steps, const Size step_limit, const Fees & fees) const final;
    };


}

#endif
