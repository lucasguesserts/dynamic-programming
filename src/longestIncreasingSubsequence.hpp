#ifndef LONGEST_INCREASING_SUBSEQUENCE_HPP_
#define LONGEST_INCREASING_SUBSEQUENCE_HPP_

#include <vector>
#include <set>
#include <cstddef>

namespace LongestIncreasingSubsequence {

    using Index = std::size_t;
    using Element = double;
    using Sequence = std::vector<Element>;
    using SequenceIt = Sequence::const_iterator;
    using SequenceList = std::vector<Sequence>;
    using SequenceSet = std::set<Sequence>;

    class SubsequenceGenerator {
        public:
            SubsequenceGenerator(const Sequence & sequence);
            SequenceSet getSubsequences() const noexcept;
        private:
            const Sequence sequence;
            SequenceSet subsequences;

            SequenceList recursiveGenerator(
                const SequenceIt begin,
                const SequenceIt end
            );
            static bool doesListHasOneElement(
                const SequenceIt begin,
                const SequenceIt end
            ) noexcept;
            static SequenceList generateFromListOfOneElement(const SequenceIt begin) noexcept;
            static SequenceList appendElementToSubsequences(const Element element, const SequenceList & subsequences);
            static void expandSubsequenceList(SequenceList & toExpand, const SequenceList & expansion);
    };

    class NaiveAlgorithm {
        public:
            NaiveAlgorithm(const Sequence & sequence);
            Index getOptimalLength() const noexcept;
            SequenceSet getOptimalSubsequences() const noexcept;
        private:
            const Sequence sequence;
            SequenceSet increasingSubsequences;
            SequenceSet optimalSubsequences;
            Index optimalLength;

            static bool isSequenceIncreasing(const Sequence & sequence);
            void selectIncreasingSubsequences();
            void selectLongestSubsequences();
    };

    class RecursiveAlgorithm {
        public:
            RecursiveAlgorithm(const Sequence & sequence);
            Index getOptimalLength() const noexcept;
            SequenceSet getOptimalSubsequences() const noexcept;
        private:
            const Sequence sequence;
            std::vector<std::set<Index>> B;
            SequenceList solutions;
            SequenceSet optimalSubsequences;
            Index optimalLength;

            void makeB() noexcept;
            void makeSolutions();
            void selectLongestSubsequences();
            Sequence makeSubproblemSolution(const Index i);
            static Sequence findLongest(const SequenceList & subsequences);
    };

    class DynamicProgrammingAlgorithm {
        public:
            DynamicProgrammingAlgorithm(const Sequence & sequence);
            Index getOptimalLength() const noexcept;
            SequenceSet getOptimalSubsequences() const noexcept;
        private:
            const Sequence sequence;
            std::vector<std::set<Index>> B;
            SequenceList solutions;
            SequenceSet optimalSubsequences;
            Index optimalLength;

            void makeB() noexcept;
            void makeSolutions();
            void selectLongestSubsequences();
            Sequence makeSubproblemSolution(const Index i);
            static Sequence findLongest(const std::vector<Sequence> & subsequences);
    };

}

#endif
