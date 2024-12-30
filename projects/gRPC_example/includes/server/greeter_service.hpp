/**
 * @file greeter_service.hpp
 * @brief Defines the GreeterServiceImpl class, which implements the Greeter service.
 */

#include "hello.grpc.pb.h"
#include <grpcpp/grpcpp.h>

/**
 * @class GreeterServiceImpl
 * @brief Implements hello::Greeter::Service to handle client requests.
 */
class GreeterServiceImpl final : public hello::Greeter::Service {
public:
    /**
     * @brief Handles the client's SayHello RPC call.
     *
     * @param context Server context.
     * @param request Client request, containing the name.
     * @param response Server response, containing the greeting message.
     * @return grpc::Status Returns the execution status of the RPC.
     */
    grpc::Status SayHello(grpc::ServerContext *context, const hello::HelloRequest *request,
                          hello::HelloResponse *response) override;
};
