#include "burglarsNightOut.hpp"

#include <iterator>
#include <limits>
#include <vector>

namespace BurglarsNightOut {

struct Solution {
    BinarySequence sequence;
    Cost cost;
};

struct SubproblemSolutions {
    Solution last_included;
    Solution last_excluded;
};

auto DynamicProgrammingAlgorithm::solve(const RealSequence & costs) -> BinarySequence {
    if (costs.empty()) {
        return {};
    }
    // Initialization
    auto subproblem_solutions = std::vector<SubproblemSolutions>{};
    subproblem_solutions.push_back({{{true}, costs[0]},
        {{false}, 0}});
    // Recursive solver
    for (auto i = 1u; i < costs.size(); ++i) {
        // compute solution with entry i included
        auto last_included = subproblem_solutions[i - 1].last_excluded;
        last_included.sequence.push_back(true);
        last_included.cost += costs[i];
        // compute solution with entry i excluded
        auto last_excluded = subproblem_solutions[i - 1].last_included.cost > subproblem_solutions[i - 1].last_excluded.cost
            ? subproblem_solutions[i - 1].last_included
            : subproblem_solutions[i - 1].last_excluded;
        last_excluded.sequence.push_back(false);
        // next entry
        subproblem_solutions.push_back({last_included, last_excluded});
    }
    // Optimal solution of the original problem
    const auto & opt_solution_candidates = subproblem_solutions.back();
    const auto optimal_sequence = opt_solution_candidates.last_included.cost > opt_solution_candidates.last_excluded.cost
        ? opt_solution_candidates.last_included.sequence
        : opt_solution_candidates.last_excluded.sequence;
    return optimal_sequence;
}

} // namespace BurglarsNightOut
