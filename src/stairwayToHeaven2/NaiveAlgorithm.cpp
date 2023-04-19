#include "stairwayToHeaven2.hpp"

#include <algorithm>
#include <iterator>
#include <numeric>

namespace StairwayToHeaven2 {

template <typename T>
void append_vectors(std::vector<T> & to_expand, const std::vector<T> & expansion) {
    to_expand.insert(to_expand.end(), expansion.begin(), expansion.end());
    return;
}

Sequence NaiveAlgorithm::solve(const Size number_of_steps, const Size step_limit, const Fees & fees) const {
    this->check_input(number_of_steps, step_limit, fees);
    const auto all_sequences = this->generate_all_sequences(number_of_steps, step_limit);
    const auto valid_sequences = this->filter_valid_sequences(number_of_steps, all_sequences);
    const auto lowest_cost_sequence = this->select_sequence_with_the_lowest_cost(valid_sequences, fees);
    return lowest_cost_sequence;
}

SequenceVector NaiveAlgorithm::generate_all_sequences(const Size size, const Size step_limit) const {
    if (size == 0) {
        return { Sequence() };
    }
    const Sequence valid_steps = this->get_all_valid_steps(step_limit);
    const auto previous_sequences = this->generate_all_sequences(size - 1, step_limit);
    const auto previous_sequences_exact = this->get_sequences_with_exact_size(size - 1, previous_sequences);
    SequenceVector output;
    append_vectors(output, previous_sequences);
    for (const auto & sequence : previous_sequences_exact) {
        for (const auto & step : valid_steps) {
            auto new_sequence = sequence;
            new_sequence.push_back(step);
            output.push_back(std::move(new_sequence));
        }
    }
    return output;
}

Sequence NaiveAlgorithm::get_all_valid_steps(const Size step_limit) const {
    Sequence valid_steps(step_limit);
    for (std::size_t i = 0; i <= step_limit - 1; ++i) {
        valid_steps[i] = i + 1;
    }
    return valid_steps;
}

SequenceVector NaiveAlgorithm::get_sequences_with_exact_size(const Size size, const SequenceVector & sequences) const {
    SequenceVector sequences_with_size;
    std::copy_if(
        sequences.cbegin(),
        sequences.cend(),
        std::back_inserter(sequences_with_size),
        [&size](const Sequence & s) { return s.size() == size; });
    return sequences_with_size;
}

SequenceVector NaiveAlgorithm::filter_valid_sequences(const Size number_of_steps, const SequenceVector & sequences) const {
    SequenceVector valid_sequences;
    std::copy_if(
        sequences.cbegin(),
        sequences.cend(),
        std::back_inserter(valid_sequences),
        [&number_of_steps](const Sequence & s) { return std::reduce(s.cbegin(), s.cend()) == number_of_steps; });
    return valid_sequences;
}

Sequence NaiveAlgorithm::select_sequence_with_the_lowest_cost(const SequenceVector & sequences, const Fees & fees) const {
    const Sequence * current_best_sequence = &sequences[0];
    Fee current_lowest_cost = this->compute_sequence_cost(*current_best_sequence, fees);
    for (const auto & sequence : sequences) {
        const Fee current_sequence_cost = this->compute_sequence_cost(sequence, fees);
        if (current_sequence_cost < current_lowest_cost) {
            current_lowest_cost = current_sequence_cost;
            current_best_sequence = &sequence;
        }
    }
    return *current_best_sequence;
}

} // namespace StairwayToHeaven2
