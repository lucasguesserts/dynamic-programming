#include "stairwayToHeaven2.hpp"

#include <algorithm>
#include <vector>

namespace StairwayToHeaven2 {

SequenceWithCost::SequenceWithCost(const Fee & initial_cost)
    : sequence()
    , cost(initial_cost) {}

Sequence SequenceWithCost::get_sequence() const noexcept {
    return this->sequence;
}

Fee SequenceWithCost::get_cost() const noexcept {
    return this->cost;
}

void SequenceWithCost::push_back(const Step & step, const Fee & extra_cost) {
    this->sequence.push_back(step);
    this->cost += extra_cost;
    return;
}

Sequence DynamicProgrammingAlgorithm::solve(const Size number_of_steps, const Size step_limit, const Fees & fees) const {
    this->check_input(number_of_steps, step_limit, fees);
    // initialization
    std::vector<SequenceWithCost> optimal_solutions;
    optimal_solutions.push_back(this->get_initial_solution(fees));
    // dp
    for (Size i = 0; i < number_of_steps; ++i) {
        const auto all_options = this->get_all_options(optimal_solutions, step_limit, fees);
        const auto best_option = this->select_best_option(all_options);
        optimal_solutions.push_back(best_option);
    }
    return optimal_solutions.back().get_sequence();
}

SequenceWithCost DynamicProgrammingAlgorithm::get_initial_solution(const Fees & fees) const {
    return SequenceWithCost(fees[0]);
}

std::vector<SequenceWithCost> DynamicProgrammingAlgorithm::get_all_options(const std::vector<SequenceWithCost> & previous_optimal_solutions, const Size & step_limit, const Fees & fees) const {
    const Size begin = static_cast<Size>(std::max(0l, static_cast<long int>(previous_optimal_solutions.size()) - static_cast<long int>(step_limit)));
    std::vector<SequenceWithCost> options;
    const auto cost_of_goal_position = fees[previous_optimal_solutions.size()];
    for (Size i = begin; i < previous_optimal_solutions.size(); ++i) {
        auto current_option = previous_optimal_solutions[i];
        const auto current_step_size = previous_optimal_solutions.size() - i;
        current_option.push_back(current_step_size, cost_of_goal_position);
        options.push_back(current_option);
    }
    return options;
}

SequenceWithCost DynamicProgrammingAlgorithm::select_best_option(const std::vector<SequenceWithCost> & options) const {
    auto * best_option = &options[0];
    auto cost_of_best_option = options[0].get_cost();
    for (Size i = 0; i < options.size(); ++i) {
        const auto current_cost = options[i].get_cost();
        if (current_cost < cost_of_best_option) {
            best_option = &options[i];
            cost_of_best_option = current_cost;
        }
    }
    return *best_option;
}

} // namespace StairwayToHeaven2
