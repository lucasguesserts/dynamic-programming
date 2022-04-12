#ifndef FACTORIAL_HPP_
#define FACTORIAL_HPP_

#include <vector>

long unsigned factorial(const long unsigned n);
long unsigned factorial_memoization(const long unsigned n);
long unsigned factorial_naive(const long unsigned n);

class FactorialMemoization {
    public:
        FactorialMemoization();
        long unsigned operator() (const long unsigned n);
    private:
        std::vector<long unsigned> values;
};


#endif
