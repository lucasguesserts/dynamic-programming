project(benchmark)

set(TEST_EXECUTABLE "run_benchmark")

find_package(benchmark REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/)

set(
    BENCHMARK_CASE_SOURCE_LIST
    BM_stairwayToHeaven.cpp
    BM_factorial.cpp
    BM_onTheWayHome.cpp
    BM_rodCutter.cpp
    BM_shareMarket.cpp
    BM_sumOfTheRange.cpp
)

foreach(BENCKMARK_CASE_SOURCE IN ITEMS ${BENCHMARK_CASE_SOURCE_LIST})
    cmake_path(GET BENCKMARK_CASE_SOURCE STEM TEST_CASE_NAME)
    add_executable(${TEST_CASE_NAME} ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/${BENCKMARK_CASE_SOURCE})
    target_link_libraries(${TEST_CASE_NAME} PRIVATE ${PROJECT_LIBRARY} PRIVATE benchmark::benchmark)
endforeach()
