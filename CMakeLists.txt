cmake_minimum_required(VERSION 3.24)
project(polymorphic_arrays_12_2022)

set(CMAKE_CXX_STANDARD 23)

add_executable(polymorphic_arrays_12_2022 main.cpp)
# target_compile_options(polymorphic_arrays_12_2022 PRIVATE -fsanitize=address -static-libasan -Wall -Wextra)
# target_link_libraries(polymorphic_arrays_12_2022 PRIVATE -fsanitize=address -static-libasan)

add_executable(correct correct.cpp)
