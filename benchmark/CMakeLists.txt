project(benchmark)

set(TEST_EXECUTABLE "run_benchmark")

find_package(benchmark REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/)

set(
    TEST_CASE_SOURCE_LIST
    example.cpp
)

foreach(BENCKMARK_CASE_SOURCE IN ITEMS ${TEST_CASE_SOURCE_LIST})
    cmake_path(GET BENCKMARK_CASE_SOURCE STEM TEST_CASE_NAME)
    add_executable(${TEST_CASE_NAME} ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/${BENCKMARK_CASE_SOURCE})
    target_link_libraries(${TEST_CASE_NAME} PRIVATE ${PROJECT_LIBRARY} PRIVATE benchmark::benchmark)
endforeach()
