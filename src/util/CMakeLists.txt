file(GLOB_RECURSE CHAT_UTIL_FILES
    ./*.cpp
    ./*.hpp
)

add_library(${PROJECT_NAME}-util OBJECT
    ${CHAT_UTIL_FILES}
)

target_include_directories(${PROJECT_NAME}-util PUBLIC
                            ${OPENSSL_INCLUDE_DIR} #for boost 1.72 need this line, for 1.69 not needed.
                            # seems when downgrade the boost to 1.69 under mac also need this line.
                            ${Boost_INCLUDE_DIRS}
                            ${CMAKE_SOURCE_DIR}/src/3rdparty
                            )

target_compile_features(${PROJECT_NAME}-util PRIVATE cxx_std_17)
