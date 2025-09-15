cmake_minimum_required(VERSION 3.14)
project(ClosestPairProject)

# Настройка стандарта C++ и флагов отладки
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")  # Добавляем отладочную информацию и отключаем оптимизацию

# Добавляем основную библиотеку
add_library(closest_pair_lib
    src/closest_pair_tonum.cpp
)

# Включаем директории
target_include_directories(closest_pair_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Настройка Google Test через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Создаем исполняемый файл для тестов
add_executable(test_closest_pair
    test/test_closest_pair.cpp
    test/main.cpp
)

# Подключаем основную библиотеку и gtest
target_link_libraries(test_closest_pair
    PRIVATE
    closest_pair_lib
    GTest::gtest_main
)

# Включаем директории для тестов
target_include_directories(test_closest_pair
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(GoogleTest)
gtest_discover_tests(test_closest_pair)