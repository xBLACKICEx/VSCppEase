#include "server/greeter_service.hpp"
#include <gtest/gtest.h>

using grpc::ServerContext;
using hello::HelloRequest;
using hello::HelloResponse;

class GreeterServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new GreeterServiceImpl();
        context = new ServerContext();
    }

    void TearDown() override {
        delete service;
        delete context;
    }

    GreeterServiceImpl *service;
    ServerContext *context;
};

TEST_F(GreeterServiceTest, SayHelloNormalCase) {
    HelloRequest request;
    HelloResponse response;
    request.set_name("World");

    grpc::Status status = service->SayHello(context, &request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(response.message(), "Hello World");
}
