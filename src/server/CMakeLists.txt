file(GLOB_RECURSE CHAT_SERVER_SOURCE_FILES
    ./*.cpp
    ./*.hpp
)

add_library(${PROJECT_NAME}-server OBJECT
    ${CHAT_SERVER_SOURCE_FILES}
)
