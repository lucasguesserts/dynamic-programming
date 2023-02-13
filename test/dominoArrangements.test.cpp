#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>

#include "dominoArrangements.hpp"

using namespace dominoArrangements;
using std::cout, std::endl;

TEST_CASE("basic cases", "[dominoArrangements]") {
    Grid grid(5);
    grid.addDomino({
        {0, 0}, Orientation::HORIZONTAL
    });
    grid.addDomino(
        {{0, 0}, Orientation::VERTICAL}
    );
    cout << std::string(grid) << endl;
}
