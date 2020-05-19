file(GLOB_RECURSE CHAT_SERVER_SOURCE_FILES
    ./*.cpp
)

add_library(${PROJECT_NAME}-server OBJECT
    ${CHAT_SERVER_SOURCE_FILES}
)

target_include_directories(${PROJECT_NAME}-server PUBLIC
                            ${OPENSSL_INCLUDE_DIR} #for boost 1.72 need this line, for 1.69 not needed.
                            # seems when downgrade the boost to 1.69 under mac also need this line.
                            ${Boost_INCLUDE_DIRS}
                            ${CMAKE_SOURCE_DIR}/src/3rdparty
                            ${CMAKE_SOURCE_DIR}/src
                            )

target_compile_features(${PROJECT_NAME}-server PRIVATE cxx_std_17)
