#include <functional>
#include <vector>
#include <numeric>
#include <algorithm>

// using SumOfTheRange = std::function<double (const unsigned, const unsigned)>;
// using Query = std::array<unsigned, 2>;

class Query: public std::array<double, 2> {
    public:
        unsigned i(void) const noexcept {
            return (*this)[0];
        }
        unsigned j(void) const noexcept {
            return (*this)[1];
        }
};

class Naive {
    public:
        Naive(const std::vector<double> & values);
        std::vector<double> operator()(const std::vector<Query> & queries) const;
    private:
        const std::vector<double> values;
        double computeAnswer(const unsigned i, const unsigned j) const;
};
