#include "client/calculator_client.hpp"

using calculator::AddRequest;
using calculator::AddResponse;
using calculator::Calculator;
using calculator::SubtractRequest;
using calculator::SubtractResponse;
using grpc::ClientContext;
using grpc::Status;

CalculatorClient::CalculatorClient(const std::shared_ptr<grpc::Channel> &channel) :
    stub_(calculator::Calculator::NewStub(channel)) {}

auto CalculatorClient::Add(int num1, int num2) const noexcept -> std::expected<int, std::string> {
    AddRequest request;
    request.set_a(num1);
    request.set_b(num2);

    AddResponse reply;
    grpc::ClientContext context;
    grpc::Status status = stub_->Add(&context, request, &reply);

    if (status.ok()) {
        return reply.result();
    }

    return std::unexpected<std::string>(status.error_message());
}

auto CalculatorClient::Subtract(int num1, int num2) const noexcept -> std::expected<int, std::string> {
    SubtractRequest request;
    request.set_a(num1);
    request.set_b(num2);

    SubtractResponse reply;
    ClientContext context;
    Status status = stub_->Subtract(&context, request, &reply);

    if (status.ok()) {
        return reply.result();
    }

    return std::unexpected<std::string>(status.error_message());
}