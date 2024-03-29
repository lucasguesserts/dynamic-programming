#include <array>
#include <functional>
#include <vector>

class Query : public std::array<unsigned, 2> {
public:
    unsigned i(void) const noexcept {
        return (*this)[0];
    }
    unsigned j(void) const noexcept {
        return (*this)[1];
    }
};

using SumOfTheRangeAlgorithm = std::function<std::vector<double>(const std::vector<Query> & queries)>;

class Naive {
public:
    Naive(const std::vector<double> & values);
    std::vector<double> operator()(const std::vector<Query> & queries) const;

private:
    const std::vector<double> values;
    double computeAnswer(const unsigned i, const unsigned j) const;
};

class Opt {
public:
    Opt(const std::vector<double> & values);
    std::vector<double> operator()(const std::vector<Query> & queries) const;

private:
    std::vector<double> ds;
    double computeAnswer(const unsigned i, const unsigned j) const;
};
