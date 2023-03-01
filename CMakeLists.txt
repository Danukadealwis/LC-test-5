cmake_minimum_required(VERSION 3.23)
project(rocket_lab_tech_test)

set(CMAKE_CXX_STANDARD 20)

add_executable(rocket_lab_tech_test main.cpp large-numbers/large-numbers.cpp large-numbers/large-numbers.hpp large-numbers/main.cpp)
