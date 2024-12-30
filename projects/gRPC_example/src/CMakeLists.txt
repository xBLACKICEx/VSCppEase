# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#
# # BUILD SERVER
#
add_library(libserver STATIC
    server/greeter_service.cpp
    server/calculator_service.cpp
    server/server.cpp
)
target_include_directories(libserver PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_link_libraries(libserver PUBLIC
    proto_OBJ
    gRPC::grpc++
)

add_executable(server server/main.cpp)
target_link_libraries(server PRIVATE libserver)

#
# # BUILD CLIENT
#
add_library(libclient STATIC
    client/greeter_client.cpp
    client/calculator_client.cpp
)
target_include_directories(libclient PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_link_libraries(libclient PUBLIC
    proto_OBJ
    gRPC::grpc++
)

# client executable
add_executable(client client/main.cpp)
target_link_libraries(client PRIVATE libclient)
