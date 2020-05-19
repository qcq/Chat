set(SUT ${PROJECT_NAME}-server-UT)

add_library(${SUT}_lib OBJECT
        ServerTest.cpp
        )

add_executable(${SUT} EXCLUDE_FROM_ALL
        $<TARGET_OBJECTS:${SUT}_lib>
        $<TARGET_OBJECTS:${PROJECT_NAME}-testMain>
        $<TARGET_OBJECTS:${PROJECT_NAME}-server>
        $<TARGET_OBJECTS:${PROJECT_NAME}-util>)

target_include_directories(${SUT}_lib PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/server
        ${PROJECT_SOURCE_DIR}/src/3rdparty
)

target_link_libraries(${SUT}
        ${GTEST_LIBRARIES}
        Boost::thread
        OpenSSL::SSL
        OpenSSL::Crypto
)

add_test(
        NAME ${SUT}
        COMMAND ${SUT} --gtest_output=xml:${GTEST_OUTPUT_XML} --gtest_filter=${GTEST_FILTER}
)

set_tests_properties(${SUT} PROPERTIES LABELS UT)

add_dependencies(ut ${SUT})
