#include "knapsack.hpp"

#include <stdexcept>
#include <utility>

namespace knapsack {

Instance::Instance(
    ValueVector values,
    WeightVector weights,
    Weight capacity)
    : values(std::move(values))
    , weights(std::move(weights))
    , capacity(std::move(capacity)) {
    if (this->values.size() != this->weights.size()) {
        throw std::runtime_error("values and weights must have the same size");
    }
    for (auto i = Item{0}; i < this->values.size(); ++i) {
        this->items.insert(i);
    }
    return;
}

} // namespace knapsack
