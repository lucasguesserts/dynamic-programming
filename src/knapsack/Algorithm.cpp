#include "knapsack.hpp"

#include <utility>

namespace knapsack {

Algorithm::Algorithm(const Instance instance)
    : instance(std::move(instance)) {}

auto Algorithm::get_instance() -> Instance {
    return this->instance;
}

auto Algorithm::compute_value(const ItemSet & items) -> Value {
    auto acc = Value{0};
    for (const auto & item : items) {
        acc += this->instance.values[item];
    }
    return acc;
}

auto Algorithm::compute_weight(const ItemSet & items) -> Weight {
    auto acc = Value{0};
    for (const auto & item : items) {
        acc += this->instance.weights[item];
    }
    return acc;
}

} // namespace knapsack
