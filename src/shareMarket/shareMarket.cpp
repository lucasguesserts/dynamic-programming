#include "shareMarket.hpp"

#include <vector>
#include <array>


using Price = double;
using Prices = std::vector<Price>;

using Index = unsigned int;
struct Operation {
    const Index buy;
    Index sell;
    Operation(const Index & buy, const Index & sell)
        : buy(buy), sell(sell) {}

};
using Solution = std::vector<Operation>;

Price computePrice(const Prices & prices, const Solution & solution) {
    Price acc = 0;
    for (auto& operation : solution) {
        acc += prices[operation.sell] - prices[operation.buy];
    }
    return acc;
}

Price shareMarket(const Prices & prices) {
    Solution solution;
    // initialization: find the first pair
    for (Index i = 0; i < prices.size() - 1; ++i) {
        if (prices[i+1] - prices[i] > 0.0) {
            auto initialOperation = Operation(i, i+1);
            solution.emplace_back(initialOperation);
            break;
        }
    }
    // search
    if (solution.size() == 0) return 0.0;
    for (Index i = solution.back().sell + 1; i < prices.size(); ++i) {
        const Index lastSellIndex = solution.back().sell;
        const Price lastSellPrice = prices[lastSellIndex];
        const Price previousSellPrice = prices[i - 1];
        const Price currentSellPrice = prices[i];
        if (lastSellIndex == i - 1 && currentSellPrice >= lastSellPrice) {
            solution.back().sell = i;
        } else if (lastSellIndex == i - 1 && currentSellPrice < lastSellPrice) {
            continue;
        } else if (lastSellIndex < i - 1 && currentSellPrice <= previousSellPrice) {
            continue;
        } else if (lastSellIndex < i - 1 && currentSellPrice > previousSellPrice) {
            solution.emplace_back(Operation(i-1, i));
        }
    }
    // compute price
    const auto price = computePrice(prices, solution);
    return price;
}
