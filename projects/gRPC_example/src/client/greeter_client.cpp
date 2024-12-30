#include "client/greeter_client.hpp"
#include "hello.grpc.pb.h"

using hello::Greeter;

GreeterClient::GreeterClient(const std::shared_ptr<grpc::Channel> &channel) : stub_(Greeter::NewStub(channel)) {}

std::expected<std::string, grpc::Status> GreeterClient::SayHello(const std::string &user) const noexcept {
    hello::HelloRequest request;
    request.set_name(user);

    hello::HelloResponse reply;
    grpc::ClientContext context;

    grpc::Status status = stub_->SayHello(&context, request, &reply);

    if (status.ok()) {
        return reply.message();
    }

    return std::unexpected(status);
}

void foo(int x) {
    int buf[10];
    if (x > 100) {
        buf[x] = 0; // <- ERROR shut get by checkcpp(C/C++ Advanced Lint)
    }
}

std::string_view dangling_pointer() {
    std::string s{"hello world"};
    // 👇 Dangling Pointer
    return std::string_view{s}; // <- ERROR shut get by checkcpp(C/C++ Advanced Lint)
}
