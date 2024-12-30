#include "client/calculator_client.hpp"
#include <gmock/gmock.h>
#include <grpcpp/grpcpp.h>
#include <gtest/gtest.h>

using ::testing::DoAll;
using ::testing::Return;

class CalculatorClientRealTest : public ::testing::Test {
protected:
    void SetUp() override {
        auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
        client_ = std::make_unique<CalculatorClient>(channel);
    }

    std::unique_ptr<CalculatorClient> client_;
};

TEST_F(CalculatorClientRealTest, AddSuccess) {
    auto result = client_->Add(2, 3);
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), 5);
}

TEST_F(CalculatorClientRealTest, SubtractSuccess) {
    auto result = client_->Subtract(5, 3);
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), 2);
}

TEST_F(CalculatorClientRealTest, AddOverflow) {
    auto result = client_->Add(INT_MAX, 1);
    ASSERT_FALSE(result.has_value());

    EXPECT_EQ(result.error(), "Result overflow");
}

TEST_F(CalculatorClientRealTest, SubtractUnderflow) {
    auto result = client_->Subtract(INT_MIN, 1);
    ASSERT_FALSE(result.has_value());
    EXPECT_EQ(result.error(), "Result underflow");
}
