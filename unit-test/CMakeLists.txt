# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)

CPMAddPackage(
  NAME doctest
  GITHUB_REPOSITORY onqtam/doctest
  GIT_TAG v2.4.8
)

# ---- Create binary ----
file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
add_executable(test_large_numbers ${sources} ../../large-numbers/LargeNumbers.cpp ../../large-numbers/LargeNumbers.hpp source/test_large_numbers.cpp)
target_link_libraries(test_large_numbers doctest LargeNumbers)

if(MSVC)
  target_compile_definitions(test_large_numbers PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
endif()

enable_testing()
add_test(test test_large_numbers)

# Note: doctest and similar testing frameworks can automatically configure CMake tests For other
# testing frameworks add the tests target instead: ADD_TEST(test_commandstore test_commandstore)

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(test_large_numbers)

# ---- code coverage ----

if(ENABLE_TEST_COVERAGE)
  target_compile_options(LargeNumbers PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
  target_link_options(LargeNumbers PUBLIC -fprofile-arcs -ftest-coverage)
endif()
