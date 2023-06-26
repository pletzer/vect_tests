cmake_minimum_required (VERSION 3.2)

# want compiler to detect which loops are not vectorized

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	add_compile_options(-O3 -ffast-math -Rpass-analysis=loop-vectorize -Rpass=loop-vectorize -Rpass-missed=loop-vectorize)
endif()

message(STATUS "C++ compiler flags: ${CMAKE_CXX_COMPILER_FLAGS}")

add_subdirectory(c_array)
