add_subdirectory(common)
add_subdirectory(util)
add_subdirectory(3rdparty)
add_subdirectory(server)
add_subdirectory(client)

# add the executable
add_executable(ChatServer
    ChatServer.cpp
    $<TARGET_OBJECTS:${PROJECT_NAME}-server>
    $<TARGET_OBJECTS:${PROJECT_NAME}-util>
)

add_executable(ChatClient
    ChatClient.cpp
    $<TARGET_OBJECTS:${PROJECT_NAME}-client>
)

# An important detail is to  place target_link_libraries after the
# add_executable and find_package lines, so all linked components are known.
target_include_directories(ChatServer PUBLIC
                            $<INSTALL_INTERFACE:include>
                            $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
                            ${CMAKE_SOURCE_DIR}/src/3rdparty
                            )

target_include_directories(ChatClient PUBLIC
                            $<INSTALL_INTERFACE:include>
                            $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
                            ${CMAKE_SOURCE_DIR}/src/3rdparty
                            )

target_compile_options(ChatServer PRIVATE -Werror)

target_compile_options(ChatClient PRIVATE -Werror)

target_compile_features(ChatServer PRIVATE cxx_std_17)

target_compile_features(ChatClient PRIVATE cxx_std_17)

target_link_libraries(ChatServer
    PUBLIC
        Boost::thread
        OpenSSL::SSL
        OpenSSL::Crypto
)

target_link_libraries(ChatClient
    PUBLIC
        Boost::boost
)
