cmake_minimum_required(VERSION 3.10)
project(CheckoutProject)

set(CMAKE_CXX_STANDARD 17)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Main executable
add_executable(main main.cpp)

# Test executable
add_executable(test_payment_mode test_payment_mode.cpp)
target_link_libraries(test_payment_mode gtest_main)

enable_testing()
add_test(NAME test_payment_mode COMMAND test_payment_mode)