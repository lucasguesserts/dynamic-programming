#ifndef NUMBER_SPPLITTING_HPP_
#define NUMBER_SPPLITTING_HPP_

#include <cstddef>
#include <vector>
#include <set>

namespace NumberSplitting {

    using Natural = std::size_t;
    using Partition = std::vector<Natural>;
    using PartitionSet = std::set<Partition>;

    Natural computeCost(const Partition & partition);

    class NaiveAlgorithm {
        public:
            static Partition solve(const Natural n);
        private:
            static PartitionSet generateAllPartitions(const Natural n, const bool excludeLast = true);
            static Partition selectMostExpensivePartition(const PartitionSet & partitionSet);
    };

    struct SubproblemSolution {
        Partition partition;
        Natural cost;
        bool operator<(SubproblemSolution const& other) const;
    };
    using SubproblemSolutionSet = std::set<SubproblemSolution>;


    class DynamicProgrammingAlgorithm {
        public:
            static Partition solve(const Natural n);
        private:
            static SubproblemSolution dpSolver(const Natural n, const bool includeLast = false);
            static SubproblemSolution selectBestCandidate(const SubproblemSolutionSet & candidates);
    };

}

#endif
