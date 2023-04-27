#include "burglars_night_out.hpp"

#include <iterator>
#include <limits>
#include <type_traits>
#include <vector>

namespace BurglarsNightOut {

auto NaiveAlgorithm::generate_all_binary_sequences(const Size n) -> std::vector<BinarySequence> {
    auto all_vectors = std::vector<BinarySequence>{};
    if (n == 0) {
        all_vectors.emplace_back();
    } else {
        auto previousSequences = generate_all_binary_sequences(n - 1);
        for (auto & sequence : previousSequences) {
            auto new_sequence = BinarySequence{sequence};
            new_sequence.push_back(false);
            all_vectors.push_back(new_sequence);
            new_sequence.back() = true;
            all_vectors.push_back(new_sequence);
        }
    }
    return all_vectors;
}

auto NaiveAlgorithm::filter_true_alternate_sequences(
    const std::vector<BinarySequence> & binary_sequences)
    -> std::remove_reference<decltype(binary_sequences)>::type {
    auto true_alternate_sequences = std::vector<BinarySequence>{};
    std::copy_if(
        binary_sequences.cbegin(),
        binary_sequences.cend(),
        std::back_inserter(true_alternate_sequences),
        [](const BinarySequence & b) { return is_true_alternate_sequence(b); });
    return true_alternate_sequences;
}

auto NaiveAlgorithm::select_most_expensive_sequence(
    const std::vector<BinarySequence> & binary_sequences,
    const RealSequence & costs)
    -> std::remove_reference<decltype(binary_sequences)>::type::value_type {
    if (binary_sequences.empty()) {
        return {};
    }
    auto largest_cost = std::numeric_limits<Cost>::lowest();
    auto best_sequence = binary_sequences.begin();
    for (auto sequence_it = binary_sequences.begin(); sequence_it != binary_sequences.end(); ++sequence_it) {
        const auto & sequence = *sequence_it;
        const auto current_cost = cost_of_sequence(sequence, costs);
        if (current_cost > largest_cost) {
            largest_cost = current_cost;
            best_sequence = sequence_it;
        }
    }
    return *best_sequence;
}

auto NaiveAlgorithm::solve(const RealSequence & costs) -> BinarySequence {
    const auto binary_sequences = generate_all_binary_sequences(costs.size());
    const auto true_alternate_binary_sequences = filter_true_alternate_sequences(binary_sequences);
    const auto optimal_binary_sequence = select_most_expensive_sequence(true_alternate_binary_sequences, costs);
    return optimal_binary_sequence;
}

} // namespace BurglarsNightOut
