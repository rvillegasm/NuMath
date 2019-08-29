cmake_minimum_required(VERSION 3.9.1)

project(NuMath C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable(NuMath main.c)
