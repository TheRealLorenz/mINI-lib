cmake_minimum_required(VERSION 3.16)
project(utilstr)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Required to generate .lib file
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include_directories(include)
add_library(utilstr STATIC src/trim.cpp src/split.cpp)
