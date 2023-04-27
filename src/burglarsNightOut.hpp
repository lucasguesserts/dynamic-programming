#ifndef BURGLARS_NIGHT_OUT_HPP_
#define BURGLARS_NIGHT_OUT_HPP_

#include <algorithm>
#include <cstddef>
#include <numeric>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace BurglarsNightOut {

using Size = std::size_t;
using BinarySequence = std::vector<bool>;
using Cost = double;
using RealSequence = std::vector<Cost>;

class Algorithm { // NOLINT(cppcoreguidelines-special-member-functions)
public:
    virtual auto solve(const RealSequence & costs) -> BinarySequence = 0;
    virtual ~Algorithm() = default;

protected:
    static auto is_true_alternate_sequence(const BinarySequence & b) -> bool;
    static auto cost_of_sequence(const BinarySequence & b, const RealSequence & r) -> Cost;
};

class NaiveAlgorithm : public Algorithm {
public:
    auto solve(const RealSequence & costs) -> BinarySequence override;

private:
    static auto generate_all_binary_sequences(const Size n) -> std::vector<BinarySequence>;
    static auto filter_true_alternate_sequences(const std::vector<BinarySequence> & binary_sequences) -> std::remove_reference<decltype(binary_sequences)>::type;
    static auto select_most_expensive_sequence(const std::vector<BinarySequence> & binary_sequences, const RealSequence & costs) -> std::remove_reference<decltype(binary_sequences)>::type::value_type;
};

class DynamicProgrammingAlgorithm : public Algorithm {
public:
    auto solve(const RealSequence & costs) -> BinarySequence override;
};

} // namespace BurglarsNightOut

#endif
