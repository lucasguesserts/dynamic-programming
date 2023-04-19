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
    Solution lastIncluded;
    Solution lastExcluded;
};

BinarySequence DynamicProgrammingAlgorithm::solve(const RealSequence & costs) {
    if (costs.empty()) {
        return {};
    }
    // Initialization
    std::vector<SubproblemSolutions> subproblemSolutions;
    subproblemSolutions.push_back({ { { true }, costs[0] },
        { { false }, 0 } });
    // Recursive solver
    for (Size i = 1; i < costs.size(); ++i) {
        // compute solution with entry i included
        Solution lastIncluded = subproblemSolutions[i - 1].lastExcluded;
        lastIncluded.sequence.push_back(true);
        lastIncluded.cost += costs[i];
        // compute solution with entry i excluded
        Solution lastExcluded = subproblemSolutions[i - 1].lastIncluded.cost > subproblemSolutions[i - 1].lastExcluded.cost
            ? subproblemSolutions[i - 1].lastIncluded
            : subproblemSolutions[i - 1].lastExcluded;
        lastExcluded.sequence.push_back(false);
        // next entry
        subproblemSolutions.push_back({ lastIncluded, lastExcluded });
    }
    // Optimal solution of the original problem
    const auto & optSolutionCandidates = subproblemSolutions.back();
    const BinarySequence optimalSequence = optSolutionCandidates.lastIncluded.cost > optSolutionCandidates.lastExcluded.cost
        ? optSolutionCandidates.lastIncluded.sequence
        : optSolutionCandidates.lastExcluded.sequence;
    return optimalSequence;
}

} // namespace BurglarsNightOut
