cmake_minimum_required(VERSION 3.24 FATAL_ERROR)
#
## OPTIONS FOR clangd & C/C++ LSP  to get the compile_commands.json
#
if(NOT "${CMAKE_GENERATOR}" MATCHES "Visual Studio") # only support Ninja and Makefile
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

    # Move the compile_commands.json to the root directory after generation
    add_custom_target(copy_compile_commands ALL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
        DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
    )
else()
    # Delete compile_commands.json in the root directory if it exists
    add_custom_target(delete_compile_commands ALL
        COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_SOURCE_DIR}/compile_commands.json
    )
endif()

#
## PROJECT
#
project("grpc_server" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
# if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
#     add_compile_options(-stdlib=libc++)
# endif()
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set (CMAKE_COLOR_DIAGNOSTICS ON)

#
## FIND PACKAGES
#
find_package(gRPC CONFIG REQUIRED)
find_package(Protobuf REQUIRED)

#
## BUILD PROTOS
#
add_subdirectory(protos)

#
## BUILD SERVER AND CLIENT
#
add_subdirectory(src)

#
## TESTS
#
option(BUILD_TESTING "Enable testing" ON)
if (BUILD_TESTING)
    message(STATUS "Building tests")
    enable_testing()
    add_subdirectory(tests)
endif()
