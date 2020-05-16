include_directories(
    ${GTEST_INCLUDE_DIRS}
)

link_directories(
    ${GTEST_LIBRARY_DIRS}
)

add_definitions(
    ${GTEST_CFLAGS_OTHER}
)

# Output files
set(GCOVR_XML_FILE coverage.xml)
set(GCOVR_HTML_FILE coverage.html)
set(VALGRIND_OUTPUT_XML valgrind.xml)

# Testing tools and flags
set(GCOVR_EXECUTABLE gcovr)
set(GCOV_EXECUTABLE gcov)
set(VALGRIND_EXECUTABLE valgrind)
set(JUNIT_MERGER ${CMAKE_SOURCE_DIR}/test/tools/merge_junit_results.py)
set(VALGRIND_MERGER ${CMAKE_SOURCE_DIR}/test/tools/merge_valgrind_results.py)
set(VALGRIND_FLAGS "--gen-suppressions=all --suppressions=/dev/null --num-callers=30 --xml=yes --xml-file=${VALGRIND_OUTPUT_XML}")

# Default tests filter
if (NOT GTEST_FILTER)
    set(GTEST_FILTER "*")
endif (NOT GTEST_FILTER)

# Sanitizers do not work with some tests
if (USE_SANITIZERS)
    set(GTEST_FILTER "${GTEST_FILTER}:-*DeathTest")
endif (USE_SANITIZERS)

# Setting up ctest
find_program(MEMORYCHECK_COMMAND ${VALGRIND_EXECUTABLE})
set(MEMORYCHECK_COMMAND_OPTIONS ${VALGRIND_FLAGS})
include(CTest)

include(CTest)

add_subdirectory(ut)