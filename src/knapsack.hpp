#ifndef SRC_KNAPSACK_HPP_
#define SRC_KNAPSACK_HPP_

#include <cstddef>
#include <limits>
#include <map>
#include <set>
#include <utility>
#include <vector>

namespace knapsack {

using Item = std::size_t;
using ItemSet = std::set<Item>;
using Value = unsigned;
using ValueVector = std::vector<Value>;
using Weight = unsigned;
using WeightVector = std::vector<Weight>;

struct Instance {
    ValueVector values;
    WeightVector weights;
    Weight capacity;
    ItemSet items;

    Instance(
        ValueVector values,
        WeightVector weights,
        Weight capacity);
};

class Algorithm { // NOLINT(cppcoreguidelines-special-member-functions)
public:
    virtual auto get_value() -> Value = 0;
    virtual auto get_weight() -> Weight = 0;
    virtual auto get_items() -> ItemSet = 0;
    virtual ~Algorithm() = default;

protected:
    Algorithm(const Instance instance);
    auto get_instance() -> Instance;
    auto compute_value(const ItemSet & items) -> Value;
    auto compute_weight(const ItemSet & items) -> Weight;

private:
    const Instance instance;
};

class Naive : public Algorithm {
public:
    Naive(const Instance instance);
    auto get_value() -> Value override;
    auto get_weight() -> Value override;
    auto get_items() -> ItemSet override;

private:
    Value value{std::numeric_limits<Value>::min()};
    Weight weight{std::numeric_limits<Value>::min()};
    ItemSet items{};
};

class Recursion : public Algorithm {
public:
    Recursion(const Instance instance);
    auto get_value() -> Value override;
    auto get_weight() -> Value override;
    auto get_items() -> ItemSet override;

private:
    auto recursive_solution(const Weight & current_capacity, const Item & item) -> ItemSet;

    Value value{std::numeric_limits<Value>::min()};
    Weight weight{std::numeric_limits<Value>::min()};
    ItemSet items{};
};

class DynamicProgramming : public Algorithm {
public:
    DynamicProgramming(const Instance instance);
    auto get_value() -> Value override;
    auto get_weight() -> Value override;
    auto get_items() -> ItemSet override;

private:
    auto recursive_solution(const Weight & current_capacity, const Item & item) -> ItemSet;

    Value value{std::numeric_limits<Value>::min()};
    Weight weight{std::numeric_limits<Value>::min()};
    ItemSet items{};

    std::map<std::pair<Weight, Item>, ItemSet> previous_results;
};

} // namespace knapsack

#endif
