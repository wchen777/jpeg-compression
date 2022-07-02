cmake_minimum_required(VERSION 3.21)
project(jpeg_compression)

set(CMAKE_CXX_STANDARD 14)

# Add sources
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/*.cpp")

# Specify include directory
include_directories("${PROJECT_SOURCE_DIR}/include/")

add_executable(jpeg_compression main.cpp include/utility.hpp include/transform.hpp include/types.hpp src/transform.cpp)
