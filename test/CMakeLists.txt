project(test)

set(TEST_EXECUTABLE "run_tests")

include_directories(${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/)

set(
    TEST_CASE_SOURCE_LIST
    random.test.cpp
    factorial.test.cpp
    fibonacci.test.cpp
    stairwayToHeaven.test.cpp
    onTheWayHome.test.cpp
    rodCutter.test.cpp
    shareMarket.test.cpp
    sumOfTheRange.test.cpp
    longestIncreasingSubsequence.test.cpp
    dominoArrangements.test.cpp
    stairwayToHeaven2/Algorithm.test.cpp
    stairwayToHeaven2/NaiveAlgorithm.test.cpp
    stairwayToHeaven2/DynamicProgrammingAlgorithm.test.cpp
    burglarsNightOut.test.cpp
    numberSplitting.test.cpp
)

foreach(TEST_CASE_SOURCE IN ITEMS ${TEST_CASE_SOURCE_LIST})
    cmake_path(GET TEST_CASE_SOURCE STEM TEST_CASE_NAME)
    add_executable(${TEST_CASE_NAME} ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/${TEST_CASE_SOURCE})
    add_test(NAME ${TEST_CASE_NAME} COMMAND ${TEST_CASE_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
    target_link_libraries(${TEST_CASE_NAME} PRIVATE ${PROJECT_LIBRARY} PRIVATE Catch2::Catch2WithMain)
endforeach()
