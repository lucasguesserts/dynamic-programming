#ifndef STAIRWAY_TO_HEAVEN_HPP_
#define STAIRWAY_TO_HEAVEN_HPP_

#include <vector>

long unsigned stairwayToHeaven(const long unsigned n);
long unsigned stairwayToHeaven_recursive(const long unsigned n);
long unsigned stairwayToHeaven_sum(const long unsigned n);

class StairwayToHeaven {
public:
    StairwayToHeaven();
    long unsigned operator()(const long unsigned n);

private:
    std::vector<long unsigned> values;
};

#endif
