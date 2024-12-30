/**
 * @file calculator_service.hpp
 * @author
 * @brief Defines the CalculatorServiceImpl class, which implements the Calculator service.
 * @version 0.1
 * @date 2024-11-18
 *
 */
#include "calculator.grpc.pb.h"
#include <grpcpp/grpcpp.h>

using calculator::AddRequest;
using calculator::AddResponse;
using calculator::Calculator;
using calculator::SubtractRequest;
using calculator::SubtractResponse;

/**
 * @class CalculatorServiceImpl
 * @brief Implementation of the Calculator service.
 *
 * This class provides the implementation for the Calculator service, which includes
 * methods for performing basic arithmetic operations such as addition and subtraction.
 *
 * @note This class is final and cannot be inherited from.
 */
class CalculatorServiceImpl final : public Calculator::Service {
public:
    /**
     * @brief Adds two numbers as specified in the request and sets the result in the response.
     *
     * @param context The server context for the RPC call.
     * @param request The request containing the two numbers to be added.
     * @param response The response containing the result of the addition.
     * @return grpc::Status indicating the success or failure of the operation.
     */
    grpc::Status Add(grpc::ServerContext *context, const AddRequest *request, AddResponse *response) override;
    /**
    * ## Method Subtract
    * Subtracts two numbers as specified in the request and sets the result in the response.
    * ### Parameters:
    * - `context`: The server context for the RPC call.
    * - `request`: The request containing the two numbers to be subtracted.
    * - `response`: The response containing the result of the subtraction.
    * ### Returns:
    * - **grpc::Status**: Indicating the success or failure of the operation.
    */
    grpc::Status Subtract(grpc::ServerContext *context, const SubtractRequest *request,
                          SubtractResponse *response) override;
};
