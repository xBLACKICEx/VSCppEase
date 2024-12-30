/**
 * @file server.hpp
 * @brief Header file for the gRPC server sartup.
 *
 * This file contains the declarations for starting the gRPC server and includes
 * the necessary service headers required for the server to function.
 *
 *
 */
#pragma once
#include "calculator_service.hpp"
#include "greeter_service.hpp"

/**
 * @brief Starts the gRPC server.
 *
 * This function initializes and starts the gRPC server, making it ready to accept incoming requests.
 * It sets up the necessary configurations and begins listening on the specified port.
 *
 * @note Ensure that all necessary server configurations are set before calling this function.
 */
void start_server();
