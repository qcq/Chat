add_subdirectory(common)
add_subdirectory(util)
add_subdirectory(3rdparty)
add_subdirectory(server)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

# add the executable
add_executable(Chat
    Chat.cpp
    $<TARGET_OBJECTS:${PROJECT_NAME}-server>
)

# An important detail is to  place target_link_libraries after the
# add_executable and find_package lines, so all linked components are known.
target_include_directories(Chat PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            )