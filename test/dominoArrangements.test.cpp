#include <catch2/catch_test_macros.hpp>

// #include <iostream>
// #include <string>
#include <vector>

#include "dominoArrangements.hpp"

using namespace dominoArrangements;
// using std::cout, std::endl;

TEST_CASE("add domino to grid", "[dominoArrangements]") {
    Grid grid(5);
    // cout << "===== basic cases =====" << endl;
    grid.addDominoList({
        {{0, 0}, Orientation::HORIZONTAL},
        {{0, 3}, Orientation::VERTICAL}
    });
    // cout << std::string(grid) << endl;
    // cout << "==========" << endl << endl;
}

struct NumberOfSolutionsTestCase {
    const Index size;
    const Index expected;
};

TEST_CASE("number of solutions", "[dominoArrangements]") {
    std::vector<NumberOfSolutionsTestCase> testCaseList = {
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 5},
        {5, 8},
        {6, 13}
    };
    for (const auto & testCase : testCaseList) {
        RecursiveAlgorithm solver(testCase.size);
        CHECK(solver.getNumberOfSolutions() == testCase.expected);
    }
}

// TEST_CASE("print solutions", "[dominoArrangements]") {
//     cout << "===== recursive solution =====" << endl;
//     RecursiveAlgorithm solver(4);
//     cout << std::string(solver);
//     cout << "==========" << endl << endl;
// }
