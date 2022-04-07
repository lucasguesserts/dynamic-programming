#ifndef ROD_CUTTER_HPP_
#define ROD_CUTTER_HPP_

#include <vector>

namespace RodCutter {

class Problem {
    public:
        Problem (const std::vector<double>& pricesOfRodPieces);
        unsigned getMaximumRodSize () const;
        double price (const unsigned& rodSize) const;
    private:
        std::vector<double> pricesOfRodPieces;
        void checkPrices (const std::vector<double>& prices);
};

class Solver {
    public:
        Solver (const Problem& problem);
        double operator() (const unsigned& rodSize);
    private:
        const Problem& problem;
        void checkProblemSize (const unsigned& rodSize);
};

}

#endif
