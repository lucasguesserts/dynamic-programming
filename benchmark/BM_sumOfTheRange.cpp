#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include <random>
#include <vector>

#define MAX(i, j) i > j ? i : j
#define MIN(i, j) i > j ? j : i

#include "sumOfTheRange.hpp"

class SumOfTheRangeFixture {
public:
    std::vector<double> values;
    std::vector<Query> queries;

    SumOfTheRangeFixture()
        : gen(rd())
        , realDis(MINIMUM_VALUE, MAXIMUM_VALUE)
        , intDis(0, NUMBER_OF_VALUES - 1) {
        for (unsigned k = 0; k < NUMBER_OF_VALUES; ++k) {
            this->values.push_back(getRealRandomNumber());
        }
        for (unsigned k = 0; k < NUMBER_OF_QUERIES; ++k) {
            const auto i = getUnsignedRandomNumber();
            const auto j = getUnsignedRandomNumber();
            const Query query{MIN(i, j), MAX(i, j)};
            this->queries.push_back(query);
        }
        return;
    }

private:
    static constexpr double MINIMUM_VALUE = 0.0;
    static constexpr double MAXIMUM_VALUE = 10.0;
    static constexpr unsigned NUMBER_OF_VALUES = 5000;
    static constexpr unsigned NUMBER_OF_QUERIES = 1000;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<double> realDis;
    std::uniform_int_distribution<unsigned> intDis;

    double getRealRandomNumber(void) {
        return realDis(gen);
    }

    unsigned getUnsignedRandomNumber(void) {
        return intDis(gen);
    }
};

TEST_CASE("sumOfTheRange Benchmark", "[benchmark][sumOfTheRange]") {

    BENCHMARK_ADVANCED("sumOfTheRangeNaive")
    (Catch::Benchmark::Chronometer meter) {
        const SumOfTheRangeFixture fixture;
        meter.measure([&fixture] {
            const Naive solver(fixture.values);
            const auto answers = solver(fixture.queries);
        });
    };

    BENCHMARK_ADVANCED("sumOfTheRangeOpt")
    (Catch::Benchmark::Chronometer meter) {
        const SumOfTheRangeFixture fixture;
        meter.measure([&fixture] {
            const Opt solver(fixture.values);
            const auto answers = solver(fixture.queries);
        });
    };
}
