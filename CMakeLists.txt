cmake_minimum_required(VERSION 3.16)
project(mINI-lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mINI-test src/INIFile.cpp main.cpp)
