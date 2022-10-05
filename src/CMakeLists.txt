cmake_minimum_required(VERSION 3.16)
project(s21_matrix)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Google_test/lib)
set (LIBRARIES gtest pthread)

add_executable(final s21_matrix_tests.cc S21Matrix.cc)
target_link_libraries(final ${LIBRARIES})