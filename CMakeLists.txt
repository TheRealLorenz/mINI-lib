cmake_minimum_required(VERSION 3.16)
project(mINI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Required to generate .lib file
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(mINI SHARED src/serialize.cpp src/deserialize.cpp)

add_subdirectory(test)
