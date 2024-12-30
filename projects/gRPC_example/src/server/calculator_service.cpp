#include "server/calculator_service.hpp"

using calculator::AddRequest;
using calculator::AddResponse;
using calculator::SubtractRequest;
using calculator::SubtractResponse;
using grpc::ServerContext;
using grpc::Status;
using grpc::StatusCode;

Status CalculatorServiceImpl::Add(ServerContext *context, const AddRequest *request, AddResponse *response) {
    if (!request || !response) {
        return {StatusCode::INVALID_ARGUMENT, "Null request or response"};
    }

    // Overflow check
    if (request->a() > INT_MAX - request->b()) {
        return {StatusCode::OUT_OF_RANGE, "Result overflow"};
    }

    response->set_result(request->a() + request->b());

    return grpc::Status::OK;
}

Status CalculatorServiceImpl::Subtract(ServerContext *context, const SubtractRequest *request,
                                       SubtractResponse *response) {
    if (!request || !response) {
        return {StatusCode::INVALID_ARGUMENT, "Null request or response"};
    }

    // Underflow check
    if (request->a() < INT_MIN + request->b()) {
        return {StatusCode::OUT_OF_RANGE, "Result underflow"};
    }

    response->set_result(request->a() - request->b());

    return {}; // OK status
}
