project(benchmark)

set(TEST_EXECUTABLE "run_benchmark")

include_directories(${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/)

set(
    BENCHMARK_CASE_SOURCE_LIST
    bm_fibonacci.cpp
    bm_factorial.cpp
    bm_burglars_night_out.cpp
    BM_longestIncreasingSubsequence.cpp
    BM_numberSplitting.cpp
    BM_onTheWayHome.cpp
    BM_rodCutter.cpp
    BM_shareMarket.cpp
    BM_stairwayToHeaven.cpp
    BM_stairwayToHeaven2.cpp
    BM_sumOfTheRange.cpp
    bm_knapsack.cpp
)

foreach(BENCKMARK_CASE_SOURCE IN ITEMS ${BENCHMARK_CASE_SOURCE_LIST})
    cmake_path(GET BENCKMARK_CASE_SOURCE STEM TEST_CASE_NAME)
    add_executable(${TEST_CASE_NAME} ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/${BENCKMARK_CASE_SOURCE})
    target_link_libraries(${TEST_CASE_NAME} PRIVATE ${PROJECT_LIBRARY} PRIVATE Catch2::Catch2WithMain)
endforeach()


