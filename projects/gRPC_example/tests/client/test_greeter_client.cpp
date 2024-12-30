#include "client/greeter_client.hpp"
#include <gmock/gmock.h>
#include <grpcpp/grpcpp.h>
#include <gtest/gtest.h>

using ::testing::Return;

// 真实测试
class GreeterClientRealTest : public ::testing::Test {
protected:
    void SetUp() override {
        auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
        client_ = std::make_unique<GreeterClient>(channel);
    }

    std::unique_ptr<GreeterClient> client_;
};

TEST_F(GreeterClientRealTest, SayHelloSuccess) {
    auto result = client_->SayHello("World");
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), "Hello World");
}
