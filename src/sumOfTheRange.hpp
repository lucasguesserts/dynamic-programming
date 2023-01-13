#include <array>
#include <vector>
#include <functional>

class Query: public std::array<double, 2> {
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
