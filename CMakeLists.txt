cmake_minimum_required(VERSION 3.14)

# set the project name
project(Chat VERSION 0.1)

# configure a header file to pass the version number to the source code
configure_file(ChatConfig.h.in src/ChatConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(BOOST_INCLUDEDIR /usr/include/boost169)
set(BOOST_LIBRARYDIR /usr/lib64/boost169)

set(Boost_COMPONENTS date_time regex system thread)
find_package(Boost REQUIRED ${Boost_COMPONENTS})

find_package(PythonInterp REQUIRED)

include_directories(
    ${Boost_INCLUDE_DIRS}
)

link_directories(
    ${Boost_LIBRARY_DIRS}
)

add_subdirectory(src)
add_subdirectory(test)
