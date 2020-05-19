set(SUT ${PROJECT_NAME}-util-UT)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/util
)

add_library(${SUT}_lib OBJECT
        StringUtilsTest.cpp
        )

add_executable(${SUT} EXCLUDE_FROM_ALL
        $<TARGET_OBJECTS:${SUT}_lib>
        $<TARGET_OBJECTS:${PROJECT_NAME}-testMain>
        $<TARGET_OBJECTS:${PROJECT_NAME}-util>)

target_link_libraries(${SUT}
        ${GTEST_LIBRARIES}
)

add_test(
        NAME ${SUT}
        COMMAND ${SUT} --gtest_output=xml:${GTEST_OUTPUT_XML} --gtest_filter=${GTEST_FILTER}
)

set_tests_properties(${SUT} PROPERTIES LABELS UT)

add_dependencies(ut ${SUT})
