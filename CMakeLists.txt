cmake_minimum_required(VERSION 3.16)
project(mINI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mINI-test src/serialize.cpp src/deserialize.cpp main.cpp)
