cmake_minimum_required(VERSION 3.14)

# set the project name
project(Chat VERSION 0.1)

# configure a header file to pass the version number to the source code
configure_file(ChatConfig.h.in src/ChatConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# out the binary to bin folder of source path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
# set env of PKG_CONFIG_PATH of linux path of gtest
set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/usr/local/lib64/pkgconfig")
# set env of PKG_CONFIG_PATH of mac path of gtest
set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/usr/local/Cellar/openssl@1.1/1.1.1g/lib/pkgconfig")

include(FindPkgConfig)

if (EXISTS /usr/include/boost169)
    set(BOOST_INCLUDEDIR /usr/include/boost169)
    set(BOOST_LIBRARYDIR /usr/lib64/boost169)
elseif (EXISTS /usr/local/Cellar/boost/1.72.0_2)
    set(BOOST_INCLUDEDIR /usr/local/Cellar/boost/1.72.0_2/include)
    set(BOOST_LIBRARYDIR /usr/local/Cellar/boost/1.72.0_2/lib)
endif ()

set(Boost_COMPONENTS date_time regex system thread)
find_package(Boost REQUIRED ${Boost_COMPONENTS})
find_package(PythonInterp REQUIRED)
find_package(GTest REQUIRED)

find_package(OpenSSL REQUIRED)

find_package(spdlog REQUIRED)

add_subdirectory(src)

include(CTest)

if(BUILD_TESTING)
    pkg_check_modules(GTEST REQUIRED gtest_main)
    enable_testing()
    add_subdirectory(test)
endif()
