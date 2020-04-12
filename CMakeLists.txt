cmake_minimum_required(VERSION 3.14)

# set the project name
project(Chat VERSION 0.1)

# configure a header file to pass the version number to the source code
configure_file(ChatConfig.h.in ChatConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(Chat src/Chat.cpp)

# An important detail is to  place target_link_libraries after the
# add_executable and find_package lines, so all linked components are known.
target_include_directories(Chat PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            )

