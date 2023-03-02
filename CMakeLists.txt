cmake_minimum_required(VERSION 3.23)
project(rocket_lab_tech_test)

include(CTest)
include(cmake/CPM.cmake)

set(CMAKE_CXX_STANDARD 20)

# ---- Include guards ----

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
            FATAL_ERROR
            "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
    )
endif()

add_executable(large_numbers large-numbers/main.cpp large-numbers/LargeNumbers.hpp large-numbers/LargeNumbers.cpp)
add_executable(simulated_sensors simulated-sensors/SimulatedSensors.cpp simulated-sensors/SimulatedSensors.hpp simulated-sensors/main.cpp)
add_library(SimulatedSensors simulated-sensors/SimulatedSensors.cpp simulated-sensors/SimulatedSensors.hpp simulated-sensors/main.cpp)
add_library(LargeNumbers large-numbers/LargeNumbers.cpp large-numbers/LargeNumbers.hpp large-numbers/main.cpp)

# enable compiler warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(LargeNumbers PUBLIC -pthread -Wall -pedantic -Wextra -Werror )
    target_compile_options(SimulatedSensors PUBLIC -pthread -Wall -pedantic -Wextra -Werror )
elseif(MSVC)
    target_compile_options(LargeNumbers PUBLIC /W4 /WX)
endif()

add_subdirectory(unit-test)