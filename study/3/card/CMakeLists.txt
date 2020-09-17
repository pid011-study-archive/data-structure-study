cmake_minimum_required (VERSION 3.8)

set (PROJECT_NAME "card")
set (CMAKE_CXX_STANDARD 11)

project (${PROJECT_NAME})
add_executable (${PROJECT_NAME} "main.cpp" "card.hpp" "card.cpp")
