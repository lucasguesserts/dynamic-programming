#ifndef LONGEST_INCREASING_SUBSEQUENCE_HPP_
#define LONGEST_INCREASING_SUBSEQUENCE_HPP_

#include <cstddef>
#include <list>
#include <set>
#include <vector>

namespace LongestIncreasingSubsequence {

using Index = std::size_t;
using Element = double;
using Sequence = std::vector<Element>;
using SequenceIt = Sequence::const_iterator;
using SequenceVector = std::vector<Sequence>;
using SequenceSet = std::set<Sequence>;
using SequenceList = std::list<Sequence>;

class SubsequenceGenerator {
public:
    SubsequenceGenerator(const Sequence & sequence);
    SequenceSet getSubsequences() const noexcept;

private:
    const Sequence sequence;
    SequenceSet subsequences;

    SequenceVector recursiveGenerator(
        const SequenceIt begin,
        const SequenceIt end);
    static bool doesListHasOneElement(
        const SequenceIt begin,
        const SequenceIt end) noexcept;
    static SequenceVector generateFromListOfOneElement(const SequenceIt begin) noexcept;
    static SequenceVector appendElementToSubsequences(const Element element, const SequenceVector & subsequences);
    static void expandSubsequenceList(SequenceVector & toExpand, const SequenceVector & expansion);
};

class Algorithm {
public:
    Algorithm(const Sequence & sequence);
    Index getOptimalLength() const noexcept;
    SequenceSet getOptimalSubsequences() const noexcept;

protected:
    const Sequence sequence;
    Index optimalLength;
    SequenceSet optimalSubsequences;

    virtual ~Algorithm() {};
};

class NaiveAlgorithm : public Algorithm {
public:
    NaiveAlgorithm(const Sequence & sequence);

private:
    SequenceSet increasingSubsequences;

    static bool isSequenceIncreasing(const Sequence & sequence);
    void selectIncreasingSubsequences();
    void selectLongestSubsequences();
};

class RecursiveAlgorithm : public Algorithm {
public:
    RecursiveAlgorithm(const Sequence & sequence);

protected:
    std::vector<std::set<Index>> B;
    SequenceVector solutions;

    void makeB() noexcept;
    void makeSolutions();
    void selectLongestSubsequences();
    Sequence makeSubproblemSolution(const Index i);
    static Sequence findLongest(const SequenceVector & subsequences);
};

class DynamicProgrammingAlgorithm : public RecursiveAlgorithm {
public:
    DynamicProgrammingAlgorithm(const Sequence & sequence);

protected:
    Sequence makeSubproblemSolution(const Index i);
};

class OptimalAlgorithm : public Algorithm {
public:
    OptimalAlgorithm(const Sequence & sequence);

private:
    SequenceList activeLists;

    void expand(const Element & element);
};

} // namespace LongestIncreasingSubsequence

#endif
