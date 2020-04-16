file(GLOB_RECURSE CHAT_SERVER_SOURCE_FILES
    ./*.cpp
    ./*.hpp
)

add_library(${PROJECT_NAME}-server OBJECT
    ${CHAT_SERVER_SOURCE_FILES}
)

target_include_directories(${PROJECT_NAME}-server PUBLIC
                            #${OPENSSL_INCLUDE_DIR} #for boost 1.72 need this line, for 1.69 not needed.
                            ${Boost_INCLUDE_DIRS}
                            ${CMAKE_SOURCE_DIR}/src/3rdparty
                            )
