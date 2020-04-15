file(GLOB_RECURSE CHAT_CLIENT_SOURCE_FILES
    ./*.cpp
    ./*.hpp
)

add_library(${PROJECT_NAME}-client OBJECT
    ${CHAT_CLIENT_SOURCE_FILES}
)
