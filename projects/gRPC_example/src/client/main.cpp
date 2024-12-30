#include "client/calculator_client.hpp"
#include "client/greeter_client.hpp"
#include <print>

using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;

int main() {

    // Create a client object
    CalculatorClient client(CreateChannel("localhost:50051", InsecureChannelCredentials()));

    // Call the Add method and get the result
    auto result = client.Add(5, 3);

    if (result) {
        std::println("5 + 3 = {}\n", result.value());
    } else {
        std::println("Failed to get the result\nerror: {}", result.error());
    }

    // Call the Subtract method
    auto subtract_result = client.Subtract(10, 4);
    if (subtract_result) {
        std::println("10 - 4 = {}\n", subtract_result.value());
    } else {
        std::println("Failed to get the subtract result\nerror: {}", subtract_result.error());
    }

    // Create a GreeterClient object
    GreeterClient greeter_client(CreateChannel("[::1]:50051", InsecureChannelCredentials()));

    // Call the SayHello method
    auto reply = greeter_client.SayHello("gRPC C++");

    if (reply) {
        std::println("Greeter service replied: {}", reply.value());
    } else {
        std::println("Failed to get the reply from the Greeter service\nerror: {}", reply.error().error_message());
    }

    return 0;
}
