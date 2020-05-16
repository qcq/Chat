include_directories(
    ${GTEST_INCLUDE_DIRS}
)

link_directories(
    ${GTEST_LIBRARY_DIRS}
)

add_definitions(
    ${GTEST_CFLAGS_OTHER}
)

# Default tests filter
if (NOT GTEST_FILTER)
    set(GTEST_FILTER "*")
endif (NOT GTEST_FILTER)

# Setting up ctest
include(CTest)

add_subdirectory(ut)
