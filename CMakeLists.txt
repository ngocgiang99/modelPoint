cmake_minimum_required(VERSION 3.10)
project(modelPoint)

set(CMAKE_CXX_STANDARD 11)

find_package(glfw3 REQUIRED)

add_library(modelPointCaculator modelPointCaculator.cpp)

add_executable(main main.cpp)
target_link_libraries(main modelPointCaculator)