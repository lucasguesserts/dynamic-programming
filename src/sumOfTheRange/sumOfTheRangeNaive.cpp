#include "sumOfTheRange.hpp"

#include <vector>
#include <algorithm>
#include <numeric>

Naive::Naive(const std::vector<double> & values)
    : values(values)
{}

double Naive::computeAnswer(const unsigned i, const unsigned j) const {
    return std::accumulate(
        this->values.cbegin() + i,
        this->values.cbegin() + j + 1,
        0.0
    );
}

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

Opt::Opt(const std::vector<double> & values)
    : ds(values.size() + 1, 0)
{
    for (unsigned i = 0; i < values.size(); ++i) {
        this->ds[i+1] = this->ds[i] + values[i];
    }
    return;
}

double Opt::computeAnswer(const unsigned i, const unsigned j) const {
    return this->ds[j+1] - this->ds[i];
}

std::vector<double> Opt::operator()(const std::vector<Query> & queries) const {
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
