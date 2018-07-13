cmake_minimum_required(VERSION 3.10)
project(modelPoint)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(modelPoint main.cpp)