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
}

#endif
