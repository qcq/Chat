set(GTEST_OUTPUT_XML ut.xml)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/common
)
# dummy target to collect UT executables
add_custom_target(ut)

add_library(${PROJECT_NAME}-testMain OBJECT
    main.cpp)

set(test_cases
    server
    util
)

foreach(test_case IN LISTS test_cases)
    add_subdirectory(${test_case})
endforeach()

add_custom_target(ut-run
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure -L "UT"
    DEPENDS ut
)
