#include "shareMarket.hpp"

#include <array>
#include <vector>

using Price = double;
using Prices = std::vector<Price>;

using Index = unsigned int;
struct Operation {
    const Index buy;
    Index sell;
    Operation(const Index & buy, const Index & sell)
        : buy(buy)
        , sell(sell) {}
};
using Solution = std::vector<Operation>;

Price computePrice(const Prices & prices, const Solution & solution) {
    Price acc = 0;
    for (auto & operation : solution) {
        acc += prices[operation.sell] - prices[operation.buy];
    }
    return acc;
}

Solution initializeSolution(const Prices & prices) {
    Solution solution;
    // initialization: find the first pair
    for (Index index = 0; index < prices.size() - 1; ++index) {
        const auto nextIndex = index + 1;
        const auto priceDiff = prices[nextIndex] - prices[index];
        if (priceDiff > 0.0) {
            auto initialOperation = Operation(index, nextIndex);
            solution.emplace_back(initialOperation);
            break;
        }
    }
    return solution;
}

Price shareMarket(const Prices & prices) {
    // initialization
    Solution solution = initializeSolution(prices);
    // boundary condition
    if (solution.empty()) {
        return 0.0;
    }
    // search
    for (Index currentIndex = solution.back().sell + 1; currentIndex < prices.size(); ++currentIndex) {
        const Index & lastSellIndex = solution.back().sell;
        const Price & lastSellPrice = prices[lastSellIndex];
        const Price & previousSellPrice = prices[currentIndex - 1];
        const Price & currentSellPrice = prices[currentIndex];
        if ((lastSellIndex == (currentIndex - 1)) && (currentSellPrice >= lastSellPrice)) {
            solution.back().sell = currentIndex;
        } else if (currentSellPrice > previousSellPrice) {
            solution.emplace_back(Operation(currentIndex - 1, currentIndex));
        }
    }
    // compute price
    const auto price = computePrice(prices, solution);
    return price;
}
