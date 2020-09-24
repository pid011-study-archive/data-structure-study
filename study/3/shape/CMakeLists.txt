cmake_minimum_required (VERSION 3.8)

set (PROJECT_NAME "shape")
set (CMAKE_CXX_STANDARD 11)

project (${PROJECT_NAME})
add_executable (${PROJECT_NAME} "main.cpp" "shape.hpp" "color.hpp" "triangle.hpp" "circle.hpp" "rectangle.hpp")
