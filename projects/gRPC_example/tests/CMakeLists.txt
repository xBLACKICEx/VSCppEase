find_package(GTest REQUIRED)
#
## SERVER TESTS
#
add_executable(test_server
    server/test_calculator_service.cpp
    server/test_greeter_service.cpp
)
target_link_libraries(test_server
    libserver
    GTest::GTest
    GTest::Main
)

add_test(NAME test_server COMMAND test_server)
#
## CLIENT TESTS
#
add_executable(test_client
    client/test_calculator_client.cpp
    client/test_greeter_client.cpp
)
target_link_libraries(test_client
    libclient
    GTest::GTest
    GTest::Main
)

add_test(NAME test_client COMMAND test_client)
