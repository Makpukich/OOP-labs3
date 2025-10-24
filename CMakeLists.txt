cmake_minimum_required(VERSION 3.10)
project(Lab03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

include_directories(include)

add_executable(lab03
    src/main.cpp
    src/Figure.cpp
    src/Octagon.cpp
    src/Triangle.cpp
    src/Square.cpp
)

# Тесты
add_executable(test_figures
    tests/test_figures.cpp
    src/Figure.cpp
    src/Octagon.cpp
    src/Triangle.cpp
    src/Square.cpp
)

target_link_libraries(test_figures GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME FigureTests COMMAND test_figures)