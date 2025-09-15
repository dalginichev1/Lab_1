cmake_minimum_required(VERSION 3.14)
project(ClosestPairProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0") 

add_library(closest_pair_lib
    src/closest_pair_tonum.cpp
)

target_include_directories(closest_pair_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(closest_pair_tonum
    src/main.cpp
)

target_link_libraries(closest_pair_tonum
    PRIVATE
    closest_pair_lib
)

target_include_directories(closest_pair_tonum
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(test_closest_pair
    test/test_closest_pair.cpp
    test/main.cpp
)

target_link_libraries(test_closest_pair
    PRIVATE
    closest_pair_lib
    GTest::gtest_main
)

target_include_directories(test_closest_pair
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(GoogleTest)
gtest_discover_tests(test_closest_pair)