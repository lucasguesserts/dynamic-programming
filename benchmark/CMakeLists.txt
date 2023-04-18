project(benchmark)

set(TEST_EXECUTABLE "run_benchmark")

find_package(benchmark REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/)

set(
    BENCHMARK_CASE_SOURCE_LIST
    BM_factorial.cpp
    BM_burglarsNightOut.cpp
    BM_longestIncreasingSubsequence.cpp
    BM_numberSplitting.cpp
    BM_onTheWayHome.cpp
    BM_rodCutter.cpp
    BM_shareMarket.cpp
    BM_stairwayToHeaven.cpp
    BM_stairwayToHeaven2.cpp
    BM_sumOfTheRange.cpp
)

foreach(BENCKMARK_CASE_SOURCE IN ITEMS ${BENCHMARK_CASE_SOURCE_LIST})
    cmake_path(GET BENCKMARK_CASE_SOURCE STEM TEST_CASE_NAME)
    add_executable(${TEST_CASE_NAME} ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/${BENCKMARK_CASE_SOURCE})
    add_test(NAME ${TEST_CASE_NAME} COMMAND ${TEST_CASE_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
    target_link_libraries(${TEST_CASE_NAME} PRIVATE ${PROJECT_LIBRARY} PRIVATE Catch2::Catch2WithMain)
endforeach()


