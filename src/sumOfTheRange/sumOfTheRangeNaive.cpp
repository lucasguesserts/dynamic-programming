#include "sumOfTheRange.hpp"

#include <vector>

Naive::Naive(const std::vector<double> & values)
    : values(values)
{}

std::vector<double> Naive::operator()(const std::vector<Query> & queries) const {
    std::vector<double> answers(queries.size());
    std::transform(
        queries.cbegin(),
        queries.cend(),
        answers.begin(),
        [&](const Query & q) {
            return this->computeAnswer(q.i(), q.j());
        }
    );
    return answers;
}


double Naive::computeAnswer(const unsigned i, const unsigned j) const {
    return std::accumulate(
        this->values.cbegin() + i,
        this->values.cbegin() + j + 1,
        0.0
    );
}
