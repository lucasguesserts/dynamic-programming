#ifndef LONGEST_INCREASING_SUBSEQUENCE_HPP_
#define LONGEST_INCREASING_SUBSEQUENCE_HPP_

#include <vector>

namespace LongestIncreasingSubsequence {

    using Element = double;
    using Sequence = std::vector<Element>;
    using SequenceIt = Sequence::iterator;
    using SequenceList = std::vector<Sequence>;

    class SubsequenceGenerator {
        public:
            SubsequenceGenerator(const Sequence & sequence);
            SequenceList getSubsequences() const noexcept;
        private:
            Sequence sequence;
            SequenceList subsequences;

            SequenceList recursiveGenerator(
                SequenceIt begin,
                SequenceIt end
            );
            static bool doesListHasOneElement(
                SequenceIt begin,
                SequenceIt end
            );
            static SequenceList generateFromListOfOneElement(SequenceIt begin);
            static SequenceList appendElementToSubsequences(Element element, SequenceList & subsequences);
            static void expandSubsequenceList(SequenceList & toExpand, SequenceList & expansion);
    };

    class NaiveAlgorithm {
        public:
            NaiveAlgorithm(const Sequence & sequence);
            unsigned getOptimalLength() const noexcept;
            SequenceList getOptimalSublists() const noexcept;
        private:
            const Sequence sequence;
            const SequenceList subsequenceList;
            const SequenceList optimalSubsequences;
    };

}

#endif
