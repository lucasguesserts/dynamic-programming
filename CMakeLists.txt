CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project(
    dynamic-programming
    VERSION 0.0.0
    HOMEPAGE_URL "https://github.com/lucasguesserts/dynamic-programming"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -pedantic-errors -fmax-errors=1 --coverage -Wno-error=ignored-qualifiers")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -pedantic-errors -ferror-limit=1 --coverage")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

find_package(Catch2 3 REQUIRED)

set(PROJECT_LIBRARY ${PROJECT_NAME})
set(SRC ${CMAKE_SOURCE_DIR}/src)

set(
    PROJECT_SOURCE_FILES
    ${SRC}/random/random.cpp
    ${SRC}/factorial/factorial.cpp
    ${SRC}/factorial/FactorialMemoization.cpp
    ${SRC}/factorial/factorial_memoization.cpp
    ${SRC}/factorial/factorial_naive.cpp
    ${SRC}/stairwayToHeaven/stairwayToHeaven.cpp
    ${SRC}/stairwayToHeaven/StairwayToHeaven.cpp
    ${SRC}/stairwayToHeaven/stairwayToHeaven_recursive.cpp
    ${SRC}/stairwayToHeaven/stairwayToHeaven_sum.cpp
    ${SRC}/fibonacci/fibonacci.cpp
    ${SRC}/onTheWayHome/onTheWayHome_class.cpp
    ${SRC}/onTheWayHome/onTheWayHome_memoization.cpp
    ${SRC}/onTheWayHome/onTheWayHome_naive.cpp
    ${SRC}/onTheWayHome/onTheWayHome_details.cpp
    ${SRC}/rodCutter/rodCutter.cpp
    ${SRC}/shareMarket/shareMarket.cpp
    ${SRC}/shareMarket/shareMarketSimple.cpp
    ${SRC}/sumOfTheRange/sumOfTheRangeNaive.cpp
    ${SRC}/longestIncreasingSubsequence/SubsequenceGenerator.cpp
    ${SRC}/longestIncreasingSubsequence/Algorithm.cpp
    ${SRC}/longestIncreasingSubsequence/NaiveAlgorithm.cpp
    ${SRC}/longestIncreasingSubsequence/RecursiveAlgorithm.cpp
    ${SRC}/longestIncreasingSubsequence/DynamicProgrammingAlgorithm.cpp
    ${SRC}/longestIncreasingSubsequence/OptimalAlgorithm.cpp
    ${SRC}/dominoArrangements/Position.cpp
    ${SRC}/dominoArrangements/Orientation.cpp
    ${SRC}/dominoArrangements/Domino.cpp
    ${SRC}/dominoArrangements/Grid.cpp
    ${SRC}/dominoArrangements/RecursiveAlgorithm.cpp
    ${SRC}/dominoArrangements/DominoArrangementError.cpp
    ${SRC}/stairwayToHeaven2/Algorithm.cpp
    ${SRC}/stairwayToHeaven2/NaiveAlgorithm.cpp
    ${SRC}/stairwayToHeaven2/DynamicProgrammingAlgorithm.cpp
    ${SRC}/burglars_night_out/Algorithm.cpp
    ${SRC}/burglars_night_out/NaiveAlgorithm.cpp
    ${SRC}/burglars_night_out/DynamicProgrammingAlgorithm.cpp
    ${SRC}/numberSplitting/NaiveAlgorithm.cpp
    ${SRC}/numberSplitting/DynamicProgrammingAlgorithm.cpp
    ${SRC}/knapsack/Instance.cpp
    ${SRC}/knapsack/Algorithm.cpp
    ${SRC}/knapsack/Naive.cpp
    ${SRC}/knapsack/Recursion.cpp
    ${SRC}/knapsack/DynamicProgramming.cpp
)

add_library(${PROJECT_LIBRARY} SHARED ${PROJECT_SOURCE_FILES})

include_directories(${SRC})

enable_testing()
add_subdirectory(test)
add_subdirectory(benchmark)

message("\n")
message("---- Project ${PROJECT_NAME} ----")
message("Version               = ${PROJECT_VERSION}")
message("Description           = ${PROJECT_DESCRIPTION}")
message("Homepage              = ${PROJECT_HOMEPAGE_URL}")
message("C++ compiler	       = ${CMAKE_CXX_COMPILER}")
message("Compiler flags	       = ${CMAKE_CXX_FLAGS}")
message("Compiler version      = ${CMAKE_CXX_COMPILER_VERSION}")
message("\n")
