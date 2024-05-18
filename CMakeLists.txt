cmake_minimum_required(VERSION 3.16)
project(mINI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(mINI SHARED src/serialize.cpp src/deserialize.cpp)

add_executable(mINI-test main.cpp)
target_link_libraries(mINI-test mINI)
