#pragma once

#include "calculator.grpc.pb.h"
#include <expected>
#include <grpcpp/grpcpp.h>
#include <memory>

/**
 * @class CalculatorClient
 * @brief A client for performing remote calculator operations using gRPC.
 */
class CalculatorClient {
public:
    /**
     * @brief Constructs a new CalculatorClient with the specified gRPC channel.
     * @param channel The gRPC channel to use for communication.
     */
    explicit CalculatorClient(const std::shared_ptr<grpc::Channel> &channel);
    /**
     * @brief Adds two integers.
     * @param num1 The first integer.
     * @param num2 The second integer.
     * @return A std::expected containing the result of the addition or an error message.
     */
    [[nodiscard]] auto Add(int num1, int num2) const noexcept -> std::expected<int, std::string>;
    /**
     * @brief Subtracts the second integer from the first integer.
     * @param num1 The first integer.
     * @param num2 The second integer.
     * @return A std::expected containing the result of the subtraction or an error message.
     */
    [[nodiscard]] auto Subtract(int num1, int num2) const noexcept -> std::expected<int, std::string>;


private:
    std::unique_ptr<calculator::Calculator::Stub> stub_;
};
