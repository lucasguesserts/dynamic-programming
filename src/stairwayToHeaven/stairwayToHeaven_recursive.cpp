#include "stairwayToHeaven.hpp"

long unsigned stairwayToHeaven_recursive(const long unsigned n) {
    if (n == 0) return 1lu;
    else if (n == 1) return 1lu;
    else if (n == 2) return 2lu;
    else return stairwayToHeaven_recursive(n - 1) + stairwayToHeaven_recursive(n - 2);
}
