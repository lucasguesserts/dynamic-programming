#include "stairwayToHeaven.hpp"
#include "factorial.hpp"

#include <vector>

constexpr auto initialValues = { 1lu, 1lu, 2lu };

long unsigned stairwayToHeaven (const long unsigned n) {
    static std::vector<long unsigned> values = initialValues;
    if (n < values.size()) {
        return values[n];
    } else {
        const long unsigned result = stairwayToHeaven(n - 1) + stairwayToHeaven(n - 2);
        values.push_back(result);
        return result;
    }
}
