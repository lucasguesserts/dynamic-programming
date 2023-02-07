#ifndef LONGEST_INCREASING_SUBSEQUENCE_HPP_
#define LONGEST_INCREASING_SUBSEQUENCE_HPP_

#include <vector>

namespace LongestIncreasingSubsequence {

    class SubsequenceGenerator {
        public:
            SubsequenceGenerator(const std::vector<double> & sequence);
            std::vector<std::vector<double>> getSubsequences() const noexcept;
        private:
            std::vector<double> sequence;
            std::vector<std::vector<double>> subsequences;

            std::vector<std::vector<double>> recursiveGenerator(
                std::vector<double>::iterator begin,
                std::vector<double>::iterator end
            );
            static bool doesListHasOneElement(
                std::vector<double>::iterator begin,
                std::vector<double>::iterator end
            );
            static std::vector<std::vector<double>> generateFromListOfOneElement(std::vector<double>::iterator begin);
            static std::vector<std::vector<double>> appendElementToSubsequences(double element, std::vector<std::vector<double>> & subsequences);
            static void expandSubsequenceList(std::vector<std::vector<double>> & toExpand, std::vector<std::vector<double>> & expansion);
    };

    class NaiveAlgorithm {
        public:
            NaiveAlgorithm(const std::vector<double> & sequence);
            unsigned getOptimalLength() const noexcept;
            std::vector<std::vector<double>> getOptimalSublists() const noexcept;
        private:
            const std::vector<double> sequence;
            const std::vector<std::vector<double>> subsequenceList;
            const std::vector<std::vector<double>> optimalSubsequences;
    };

}

#endif
