cmake_minimum_required(VERSION 3.16)
project(mINI-lib-test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_GMOCK OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(runAllTests runAllTests.cpp testDeserialize.cpp)
target_link_libraries(runAllTests gtest_main mINI_static)
gtest_discover_tests(runAllTests)
