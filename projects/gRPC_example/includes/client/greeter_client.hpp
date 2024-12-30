#pragma once

#include "hello.grpc.pb.h"
#include <expected>
#include <grpcpp/grpcpp.h>
#include <memory>
#include <string>

/**
 * @class GreeterClient
 * @brief A client for sending greeting messages to a gRPC server.
 *
 * The GreeterClient class provides functionality to send a "Hello" message to a gRPC server
 * and receive a response. It uses a gRPC channel to communicate with the server.
 *
 * @note This class requires a valid gRPC channel to be provided during construction.
 */
class GreeterClient {
public:
    explicit GreeterClient(const std::shared_ptr<grpc::Channel> &channel);

    /**
     * @brief Sends a greeting to the specified user and returns the server's response.
     *
     * This function sends a "Hello" message to the server with the provided user name
     * and waits for the server's response. The response is returned as a std::expected
     * object, which contains either the server's response string or a grpc::Status
     * object indicating an error.
     *
     * @param user The name of the user to greet.
     * @return std::expected<std::string, grpc::Status> The server's response or an error status.
     */
    [[nodiscard]] std::expected<std::string, grpc::Status> SayHello(const std::string &user) const noexcept;

private:
    std::unique_ptr<hello::Greeter::Stub> stub_;
};

void foo(int x);
