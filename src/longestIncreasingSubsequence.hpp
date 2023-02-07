#ifndef LONGEST_INCREASING_SUBSEQUENCE_HPP_
#define LONGEST_INCREASING_SUBSEQUENCE_HPP_

#include <vector>
#include <set>

namespace LongestIncreasingSubsequence {

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
            unsigned getOptimalLength() const noexcept;
            SequenceList getOptimalSubsequences() const noexcept;
        private:
            const Sequence sequence;
            const SequenceList subsequenceList;
            const SequenceList optimalSubsequences;
    };

}

#endif
