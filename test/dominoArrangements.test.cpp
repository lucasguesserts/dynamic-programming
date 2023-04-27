#include <catch2/catch_test_macros.hpp>

// #define ENABLE_PRINT_TESTS

#include <vector>

#include "dominoArrangements.hpp"
using namespace dominoArrangements;

#ifdef ENABLE_PRINT_TESTS
#include <iostream>
#include <string>
using std::cout, std::endl;
#endif

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
        {6, 13}};
    for (const auto & testCase : testCaseList) {
        RecursiveAlgorithm solver(testCase.size);
        CHECK(solver.getNumberOfSolutions() == testCase.expected);
    }
}

#ifdef ENABLE_PRINT_TESTS
TEST_CASE("print grid", "[dominoArrangements]") {
    Grid grid(5);
    cout << "===== basic cases =====" << endl;
    grid.addDominoList({{{0, 0}, Orientation::HORIZONTAL},
        {{0, 3}, Orientation::VERTICAL}});
    cout << grid.to_string() << endl;
    cout << "==========" << endl
         << endl;
}

TEST_CASE("print solutions of algorithm", "[dominoArrangements]") {
    cout << "===== recursive solution =====" << endl;
    RecursiveAlgorithm solver(4);
    cout << solver.to_string();
    cout << "==========" << endl
         << endl;
}
#endif
