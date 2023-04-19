#include <catch2/catch_test_macros.hpp>

#if __clang__
#pragma clang diagnostic ignored "-Wkeyword-macro"
#endif

#define private public

#include "numberSplitting.hpp"

using namespace NumberSplitting;

TEST_CASE("compute cost", "[numberSplitting]") {
    SECTION("case 0") {
        const Partition partition = {};
        CHECK_THROWS(computeCost(partition));
    }
    SECTION("case 1") {
        const Partition partition = { 1 };
        CHECK(computeCost(partition) == 1);
    }
    SECTION("case 2") {
        const Partition partition = { 6, 5, 2 };
        CHECK(computeCost(partition) == 60);
    }
    SECTION("case 3") {
        const Partition partition = { 2, 2, 5, 8, 6, 7 };
        CHECK(computeCost(partition) == 6720);
    }
}

TEST_CASE("naive algorithm - generate all partitions", "[numberSplitting]") {
    SECTION("n = 3") {
        const Natural n = 3;
        const PartitionSet expected = {
            { 1, 1, 1 },
            { 1, 2 },
        };
        NaiveAlgorithm na;
        CHECK(na.generateAllPartitions(n) == expected);
    }
    SECTION("n = 4") {
        const Natural n = 4;
        const PartitionSet expected = {
            { 1, 1, 1, 1 },
            { 1, 1, 2 },
            { 2, 2 },
            { 1, 3 },
        };
        NaiveAlgorithm na;
        CHECK(na.generateAllPartitions(n) == expected);
    }
    SECTION("n = 6") {
        const Natural n = 6;
        const PartitionSet expected = {
            { 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 2 },
            { 1, 1, 1, 3 },
            { 1, 1, 2, 2 },
            { 2, 2, 2 },
            { 1, 2, 3 },
            { 1, 1, 4 },
            { 1, 5 },
            { 2, 4 },
            { 3, 3 },
        };
        NaiveAlgorithm na;
        CHECK(na.generateAllPartitions(n) == expected);
    }
    SECTION("n = 8") {
        const Natural n = 8;
        const PartitionSet expected = {
            { 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 2 },
            { 1, 1, 1, 1, 1, 3 },
            { 1, 1, 1, 1, 2, 2 },
            { 1, 1, 1, 2, 3 },
            { 1, 1, 1, 1, 4 },
            { 1, 1, 2, 2, 2 },
            { 1, 1, 2, 4 },
            { 1, 2, 2, 3 },
            { 1, 1, 1, 5 },
            { 2, 2, 2, 2 },
            { 1, 1, 3, 3 },
            { 1, 2, 5 },
            { 2, 3, 3 },
            { 1, 1, 6 },
            { 2, 2, 4 },
            { 1, 3, 4 },
            { 1, 7 },
            { 2, 6 },
            { 3, 5 },
            { 4, 4 },
        };
        NaiveAlgorithm na;
        CHECK(na.generateAllPartitions(n) == expected);
    }
}

TEST_CASE("naive algorithm - select most expensive partition", "[numberSplitting]") {
    SECTION("case 0") {
        const PartitionSet partitionSet = {};
        NaiveAlgorithm na;
        CHECK_THROWS(na.selectMostExpensivePartition(partitionSet));
    }
    SECTION("case 1") {
        const PartitionSet partitionSet = {
            { 1, 1, 1, 1 },
            { 1, 1, 2 },
            { 1, 3 },
        };
        const Partition expected = { 1, 3 };
        NaiveAlgorithm na;
        CHECK(na.selectMostExpensivePartition(partitionSet) == expected);
    }
    SECTION("case 2") {
        const PartitionSet partitionSet = {
            { 1, 1, 1, 5 },
            { 1, 1, 3, 3 },
            { 1, 1, 6 },
            { 1, 2, 2, 3 },
            { 1, 2, 5 },
            { 1, 3, 4 },
            { 1, 7 },
        }; // be careful with the way c++ order the partitions
        const Partition expected = { 1, 2, 2, 3 };
        NaiveAlgorithm na;
        CHECK(na.selectMostExpensivePartition(partitionSet) == expected);
    }
    SECTION("case 3") {
        const PartitionSet partitionSet = {
            { 2, 6, 4, 2 },
            { 1, 7, 2 },
            { 2, 5, 9, 6 },
            { 6, 2, 6, 5 },
        };
        const Partition expected = { 2, 5, 9, 6 };
        NaiveAlgorithm na;
        CHECK(na.selectMostExpensivePartition(partitionSet) == expected);
    }
}

TEST_CASE("naive algorithm - solve", "[numberSplitting]") {
    SECTION("case 0") {
        const Natural n = 0;
        NaiveAlgorithm na;
        CHECK_THROWS(na.solve(n));
    }
    SECTION("case n = 2") {
        const Natural n = 2;
        const Partition expected = { 1, 1 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
    SECTION("case n = 3") {
        const Natural n = 3;
        const Partition expected = { 1, 2 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
    SECTION("case n = 4") {
        const Natural n = 4;
        const Partition expected = { 2, 2 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
    SECTION("case n = 5") {
        const Natural n = 5;
        const Partition expected = { 2, 3 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
    SECTION("case n = 6") {
        const Natural n = 6;
        const Partition expected = { 3, 3 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
    SECTION("case n = 7") {
        const Natural n = 7;
        const Partition expected = { 2, 2, 3 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
    SECTION("case n = 8") {
        const Natural n = 8;
        const Partition expected = { 2, 3, 3 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
    SECTION("case n = 9") {
        const Natural n = 9;
        const Partition expected = { 3, 3, 3 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
    SECTION("case n = 10") {
        const Natural n = 10;
        const Partition expected = { 2, 2, 3, 3 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
    SECTION("case n = 11") {
        const Natural n = 11;
        const Partition expected = { 2, 3, 3, 3 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
    SECTION("case n = 12") {
        const Natural n = 12;
        const Partition expected = { 3, 3, 3, 3 };
        NaiveAlgorithm na;
        CHECK(na.solve(n) == expected);
    }
}

TEST_CASE("dynamic programming algorithm - solve", "[numberSplitting]") {
    SECTION("case 0") {
        const Natural n = 0;
        DynamicProgrammingAlgorithm dp;
        CHECK_THROWS(dp.solve(n));
    }
    SECTION("case n = 2") {
        const Natural n = 2;
        DynamicProgrammingAlgorithm dp;
        const Partition expected = { 1, 1 };
        CHECK(dp.solve(n) == expected);
    }
    SECTION("case n = 3") {
        const Natural n = 3;
        DynamicProgrammingAlgorithm dp;
        const Partition expected = { 1, 2 };
        CHECK(dp.solve(n) == expected);
    }
    SECTION("case n = 4") {
        const Natural n = 4;
        DynamicProgrammingAlgorithm dp;
        const Partition expected = { 2, 2 };
        CHECK(dp.solve(n) == expected);
    }
    SECTION("case n = 8") {
        const Natural n = 8;
        DynamicProgrammingAlgorithm dp;
        const Partition expected = { 2, 3, 3 };
        CHECK(dp.solve(n) == expected);
    }
}

TEST_CASE("compare algorithms", "[numberSplitting]") {
    SECTION("case 1") {
        const Natural n = 10;
        DynamicProgrammingAlgorithm dp;
        NaiveAlgorithm na;
        CHECK(na.solve(n) == dp.solve(n));
    }
}
