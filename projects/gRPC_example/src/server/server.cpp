#include "server/server.hpp"
#include <print>

void start_server() {

    std::string server_address("[::1]:50051");
    CalculatorServiceImpl calcul_service;
    GreeterServiceImpl greeter_service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&calcul_service);
    builder.RegisterService(&greeter_service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::println("Server started, listening on address: {}", server_address);

    server->Wait();
}
