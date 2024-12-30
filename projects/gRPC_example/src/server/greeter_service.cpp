#include "server/greeter_service.hpp"

using grpc::ServerContext;
using grpc::Status;
using hello::HelloRequest;
using hello::HelloResponse;

Status GreeterServiceImpl::SayHello(ServerContext *context, const HelloRequest *request, HelloResponse *response) {
    std::string reply = "Hello " + request->name();

    response->set_message(reply);

    return {};
}