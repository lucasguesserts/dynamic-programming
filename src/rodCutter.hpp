#ifndef ROD_CUTTER_HPP_
#define ROD_CUTTER_HPP_

#include <vector>

namespace RodCutter {

class Problem {
    friend class ProblemBuilder;
    public:
    private:
        unsigned _rodSize;
        std::vector<unsigned> _pricesOfRodPieces;
};

class ProblemBuilder {
    public:
        ProblemBuilder () {};
        ProblemBuilder& rodSize ([[maybe_unused]] const unsigned) { return *this; };
        ProblemBuilder& prices ([[maybe_unused]] const std::vector<unsigned>& pricesOfRodPieces) { return *this; };
        Problem build () { return Problem(); };
};

class Solver {
    public:
        Solver ([[maybe_unused]] const Problem& problem) {};
        unsigned operator() ([[maybe_unused]] const unsigned& rodSize) { return 0lu; };
};
}

#endif
