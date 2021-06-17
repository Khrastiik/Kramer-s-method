cmake_minimum_required(VERSION 3.19)

project(matrix)

file(GLOB matrix_SRC
     "*.hpp"
     "*.cpp"
)

add_executable(matrix ${matrix_SRC})

source_group(src FILES ${matrix_SRC})

set_target_properties(
    matrix PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
