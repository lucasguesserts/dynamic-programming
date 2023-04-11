#include "numberSplitting.hpp"

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <limits>
#include <set>

namespace NumberSplitting {

Natural computeCost(const Partition & partition) {
    if (partition.empty()) {
        throw std::runtime_error("cost of an empty partition is undefined");
    }
    return std::reduce(
        partition.begin(),
        partition.end(),
        Natural(1),
        [](Natural acc, Natural val) { return acc * val; }
    );
}

PartitionSet NaiveAlgorithm::generateAllPartitions(const Natural n, const bool excludeLast) {
    /*
    Generate all partitions of the integer n, sorted and without duplicates, excluding [n],
    in decreasing order of tuple length.
    */
    PartitionSet parts;
    if (n == 0) {
        parts.insert(Partition{});
        return parts;
    }
    if (n == 1) {
        parts.insert(Partition{1});
        return parts;
    }
    for (Natural i = 1; i < n + 1; i++) {
        for (Partition p : generateAllPartitions(n-i, false)) {
            Partition part = p;
            part.push_back(i);
            std::sort(part.begin(), part.end());
            parts.insert(part);
        }
    }
    if (excludeLast) {
        for(auto iter = parts.begin(); iter != parts.end();)
        {
            if((*iter).size() == 1) {
            iter = parts.erase(iter);
            } else {
                ++iter;
            }
        }
    }
    return parts;
}


Partition NaiveAlgorithm::selectMostExpensivePartition(const PartitionSet & partitionSet) {
    if (partitionSet.empty()) {
        throw std::runtime_error("the partition set provided is empty");
    }
    Natural largestCost = std::numeric_limits<Natural>::min();
    const Partition * bestPartition;
    for (const auto & partition : partitionSet) {
        const Natural currentCost = computeCost(partition);
        if (currentCost > largestCost) {
            largestCost = currentCost;
            bestPartition = &partition;
        }
    }
    return *bestPartition;
}

Partition NaiveAlgorithm::solve(const Natural n) {
    const auto allPartitions = generateAllPartitions(n, true);
    const auto optimalPartition = selectMostExpensivePartition(allPartitions);
    return optimalPartition;
}

}
