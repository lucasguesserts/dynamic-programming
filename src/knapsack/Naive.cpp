#include "knapsack.hpp"

#include <utility>

#include <cppitertools/itertools.hpp>

namespace knapsack {

Naive::Naive(const Instance instance)
    : Algorithm(std::move(instance)) {
    auto all_possibilities = iter::powerset(this->get_instance().items);
    for (auto && item_set_gen : all_possibilities) {
        auto item_set = ItemSet{item_set_gen.begin(), item_set_gen.end()};
        auto current_value = this->compute_value(item_set);
        auto current_weight = this->compute_weight(item_set);
        if ((current_value > this->value) && (current_weight <= this->get_instance().capacity)) {
            this->value = std::move(current_value);
            this->weight = std::move(current_weight);
            this->items = std::move(item_set);
        }
    }
    return;
}

auto Naive::get_value() -> Value {
    return this->value;
}

auto Naive::get_weight() -> Value {
    return this->weight;
}

auto Naive::get_items() -> ItemSet {
    return this->items;
}

} // namespace knapsack
