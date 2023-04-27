#include "rodCutter.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <vector>

using namespace RodCutter;

Problem::Problem(
    const std::vector<double> & pricesOfRodPieces) {
    this->checkPrices(pricesOfRodPieces);
    this->pricesOfRodPieces = pricesOfRodPieces;
    this->pricesOfRodPieces.insert(this->pricesOfRodPieces.begin(), 0.0); // value at zero
}

void Problem::checkPrices(const std::vector<double> & prices) {
    for (const auto & price : prices) {
        if (price <= 0.0) throw std::runtime_error("The price of the pieces of rod must be positive, but a non-positive value has been provided");
    }
}

unsigned Problem::getMaximumRodSize() const {
    return this->pricesOfRodPieces.size();
}

double Problem::price(const unsigned & rodSize) const {
    return this->pricesOfRodPieces[rodSize];
}

Solver::Solver(const Problem & problem)
    : problem(problem) {}

double Solver::operator()(const unsigned & rodSize) {
    this->checkProblemSize(rodSize);
    const unsigned halfSize = rodSize / 2u; // floor(rodSize / 2)
    const unsigned solutionsToCompute = halfSize + 1u;
    std::vector<double> bestPrices(solutionsToCompute, 0.0);
    bestPrices[0] = this->problem.price(rodSize);
    for (unsigned i = 1; i < solutionsToCompute; ++i) {
        bestPrices[i] = this->problem.price(i) + this->problem.price(rodSize - i);
    }
    const double max = *std::max_element(bestPrices.cbegin(), bestPrices.cend());
    return max;
}

void Solver::checkProblemSize(const unsigned & rodSize) {
    if (rodSize > this->problem.getMaximumRodSize())
        throw std::runtime_error("problem size is larger than the maximum allowed");
}
