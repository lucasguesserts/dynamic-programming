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
            Fee compute_sequence_cost(const Sequence & sequence, const Fees & fees) const;
    };

    using AlgorithmPtr = std::unique_ptr<Algorithm>;

    class NaiveAlgorithm: public Algorithm {
        public:
            virtual Sequence solve(const Size number_of_steps, const Size step_limit, const Fees & fees) const final;
        private:
            SequenceVector generate_all_sequences(const Size number_of_steps, const Size step_limit) const;
            Sequence get_all_valid_steps(const Size step_limit) const;
            SequenceVector get_sequences_with_exact_size(const Size size, const SequenceVector & sequences) const;
            SequenceVector filter_valid_sequences(const Size number_of_steps, const SequenceVector & sequences) const;
            Sequence select_sequence_with_the_lowest_cost(const SequenceVector & sequences, const Fees & fees) const;
    };

    class SequenceWithCost {
        public:
            SequenceWithCost(const Fee & initial_cost);
            inline Sequence get_sequence() const noexcept;
            inline Fee get_cost() const noexcept;
            void push_back(const Step & step, const Fee & extra_cost);
        private:
            Sequence sequence;
            Fee cost;
    };

    class DynamicProgrammingAlgorithm: public Algorithm {
        public:
            virtual Sequence solve(const Size number_of_steps, const Size step_limit, const Fees & fees) const final;
        private:
            SequenceWithCost get_initial_solution(const Fees & fees) const;
            std::vector<SequenceWithCost> get_all_options(const std::vector<SequenceWithCost> & previous_optimal_solutions, const Size & step_limit, const Fees & fees) const;
            SequenceWithCost select_best_option(const std::vector<SequenceWithCost> & options) const;
    };
}

#endif
