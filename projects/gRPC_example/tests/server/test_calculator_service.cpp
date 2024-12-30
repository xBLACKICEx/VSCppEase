#include "server/calculator_service.hpp"
#include <gtest/gtest.h>

using grpc::ServerContext;
using calculator::AddRequest;
using calculator::AddResponse;
using calculator::SubtractRequest;
using calculator::SubtractResponse;

class CalculatorServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new CalculatorServiceImpl();
        context = new ServerContext();
    }

    void TearDown() override {
        delete service;
        delete context;
    }

    CalculatorServiceImpl* service;
    ServerContext* context;
};

TEST_F(CalculatorServiceTest, AddNormalCase) {
    AddRequest request;
    AddResponse response;
    request.set_a(10);
    request.set_b(20);

    grpc::Status status = service->Add(context, &request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(response.result(), 30);
}

TEST_F(CalculatorServiceTest, AddOverflow) {
    AddRequest request;
    AddResponse response;
    request.set_a(INT_MAX);
    request.set_b(1);

    grpc::Status status = service->Add(context, &request, &response);

    EXPECT_EQ(status.error_code(), grpc::OUT_OF_RANGE);
    EXPECT_EQ(status.error_message(), "Result overflow");
}

TEST_F(CalculatorServiceTest, SubtractNormalCase) {
    SubtractRequest request;
    SubtractResponse response;
    request.set_a(20);
    request.set_b(10);

    grpc::Status status = service->Subtract(context, &request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(response.result(), 10);
}

TEST_F(CalculatorServiceTest, SubtractUnderflow) {
    SubtractRequest request;
    SubtractResponse response;
    request.set_a(INT_MIN);
    request.set_b(1);

    grpc::Status status = service->Subtract(context, &request, &response);

    EXPECT_EQ(status.error_code(), grpc::OUT_OF_RANGE);
    EXPECT_EQ(status.error_message(), "Result underflow");
}
