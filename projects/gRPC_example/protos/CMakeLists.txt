set(PROTO_FILES
    calculator.proto
    hello.proto
)

# Define the target before generating protobuf files
add_library(proto_OBJ STATIC ${PROTO_FILES})

set_target_properties(proto_OBJ PROPERTIES POSITION_INDEPENDENT_CODE ON)


target_link_libraries(proto_OBJ PUBLIC protobuf::libprotobuf gRPC::grpc++)

# Generate gRPC and Protobuf source files
set(PROTO_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated")
set(PROTO_IMPORT_DIRS "${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(proto_OBJ PUBLIC "$<BUILD_INTERFACE:${PROTO_BINARY_DIR}>")

protobuf_generate(
    TARGET proto_OBJ
    IMPORT_DIRS ${PROTO_IMPORT_DIRS}
    PROTOC_OUT_DIR "${PROTO_BINARY_DIR}"
    PROTOS ${PROTO_FILES}
)

protobuf_generate(
    TARGET proto_OBJ
    LANGUAGE grpc
    GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
    PLUGIN "protoc-gen-grpc=\$<TARGET_FILE:gRPC::grpc_cpp_plugin>"
    IMPORT_DIRS ${PROTO_IMPORT_DIRS}
    PROTOC_OUT_DIR "${PROTO_BINARY_DIR}"
    PROTOS ${PROTO_FILES}
)

# Make the target available to parent scope
set(PROTO_TARGET proto_OBJ PARENT_SCOPE)
