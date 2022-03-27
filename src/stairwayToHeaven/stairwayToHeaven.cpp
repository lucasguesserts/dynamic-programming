#include "stairwayToHeaven.hpp"

long int stairwayToHeaven (const long int n) {
    if (n == 0) return 0lu;
    else if (n == 1) return 1lu;
    else if (n == 2) return 2lu;
    else return stairwayToHeaven(n - 1) + stairwayToHeaven(n - 2);
}
