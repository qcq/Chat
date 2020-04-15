file(GLOB_RECURSE CHAT_CLIENT_SOURCE_FILES
    ./*.cpp
    ./*.hpp
)

add_library(${PROJECT_NAME}-client OBJECT
    ${CHAT_CLIENT_SOURCE_FILES}
)

target_include_directories(${PROJECT_NAME}-client PUBLIC
                            ${Boost_INCLUDE_DIRS}
                            ${CMAKE_SOURCE_DIR}/src/3rdparty
                            )
