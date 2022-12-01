CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project(
    dynamic-programming
	VERSION 0.0.0
	HOMEPAGE_URL "https://github.com/lucasguesserts/dynamic-programming"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wpedantic -pedantic-errors -fmax-errors=1")

set(CMAKE_BUILD_TYPE Debug)

find_package(Catch2 3 REQUIRED)

set(PROJECT_LIBRARY ${PROJECT_NAME})
set(SRC src)

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
