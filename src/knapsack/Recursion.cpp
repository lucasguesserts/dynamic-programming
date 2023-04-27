#include "knapsack.hpp"

#include <utility>

#include <cppitertools/itertools.hpp>

namespace knapsack {

Recursion::Recursion(const Instance instance)
    : Algorithm(std::move(instance)) {
    this->items = this->recursive_solution(this->get_instance().capacity, 0);
    this->value = this->compute_value(this->items);
    this->weight = this->compute_weight(this->items);
    return;
}

auto Recursion::get_value() -> Value {
    return this->value;
}

auto Recursion::get_weight() -> Value {
    return this->weight;
}

auto Recursion::get_items() -> ItemSet {
    return this->items;
}

auto Recursion::recursive_solution(const Weight & current_capacity, const Item & item) -> ItemSet {
    if ((current_capacity <= 0) || (item >= this->get_instance().values.size())) {
        return {};
    }

    auto item_weight = this->get_instance().weights[item];

    auto item_included = ItemSet{};
    if (item_weight <= current_capacity) {
        item_included = this->recursive_solution(current_capacity - item_weight, item + 1);
        item_included.insert(item);
    }

    auto item_excluded = this->recursive_solution(current_capacity, item + 1);

    return this->compute_value(item_included) > this->compute_value(item_excluded)
        ? item_included
        : item_excluded;
}

} // namespace knapsack
