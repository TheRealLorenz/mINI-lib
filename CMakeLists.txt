cmake_minimum_required(VERSION 3.16)
project(mINI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Required to generate .lib file
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(objlib OBJECT src/serialize.cpp src/deserialize.cpp)
set_property(TARGET objlib PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(mINI_static STATIC $<TARGET_OBJECTS:objlib>)
add_library(mINI SHARED $<TARGET_OBJECTS:objlib>)

enable_testing()
add_subdirectory(test)
