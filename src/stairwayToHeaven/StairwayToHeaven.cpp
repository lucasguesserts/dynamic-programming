#include "stairwayToHeaven.hpp"
#include "factorial.hpp"

#include <vector>

constexpr auto initialValues = { 1lu, 1lu, 2lu };

StairwayToHeaven::StairwayToHeaven() {
    this->values = initialValues;
}

long unsigned StairwayToHeaven::operator()(const long unsigned n) {
    static std::vector<long unsigned> values = initialValues;
    if (n < values.size()) {
        return values[n];
    } else {
        const long unsigned result = this->operator()(n - 1) + this->operator()(n - 2);
        values.push_back(result);
        return result;
    }
}
