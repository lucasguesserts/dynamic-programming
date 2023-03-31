#ifndef BURGLARS_NIGHT_OUT_HPP_
#define BURGLARS_NIGHT_OUT_HPP_

#include <cstddef>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>

namespace BurglarsNightOut {

    using Size = std::size_t;
    using BinarySequence = std::vector<bool>;
    using Cost = double;
    using RealSequence = std::vector<Cost>;

    bool isTrueAlternateSequence(const BinarySequence &b);
    Cost costOfSequence(const BinarySequence &b, const RealSequence &r);

    class NaiveAlgorithm {
        public:
            static BinarySequence solve(const RealSequence & costs);
        private:
            static std::vector<BinarySequence> generateAllBinarySequences(const Size n);
            static std::vector<BinarySequence> filterTrueAlternateSequences(const std::vector<BinarySequence> & binarySequences);
            static BinarySequence selectMostExpensiveSequence(const std::vector<BinarySequence> & binarySequences, const RealSequence & costs);
    };

    class DynamicProgrammingAlgorithm {
        public:
            static BinarySequence solve(const RealSequence & costs);
    };

}

#endif
