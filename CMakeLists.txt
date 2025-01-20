cmake_minimum_required(VERSION 3.10)
project(Thermostat)

set(CMAKE_CXX_STANDARD 11)

# Add the source files
add_library(Thermostat src/Thermostat.cpp)
target_compile_options(Thermostat PUBLIC -g)

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

# Add the test executable
add_executable(test_Thermostat test/test_Thermostat.cpp)
target_link_libraries(test_Thermostat Thermostat ${GTEST_LIBRARIES} pthread)

include(GoogleTest)
gtest_discover_tests(test_Thermostat)