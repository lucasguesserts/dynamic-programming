#include "shareMarket.hpp"

#include <vector>
#include <algorithm>
#include <numeric>

double shareMarketSimple(const std::vector<double> & prices) {
    std::vector<double> priceDiffs(prices.size() - 1);
    for (size_t i = 0; i < prices.size() - 1; ++i) {
        priceDiffs[i] = prices[i+1] - prices[i];
    }
    auto last = std::remove_if(
        priceDiffs.begin(),
        priceDiffs.end(),
        [](const double & value){ return value < 0; }
    );
    const double price = std::accumulate(priceDiffs.begin(), last, 0.0);
    return price;
}
