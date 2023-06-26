cmake_minimum_required (VERSION 3.2)

# want compiler to detect which loops are not vectorized

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	add_compile_options(-O3 -ffast-math -Rpass-analysis=loop-vectorize -Rpass=loop-vectorize -Rpass-missed=loop-vectorize)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
	add_compile_options(-O3 -ffast-math -qopt-report=3)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	add_compile_options(-O3 -ffast-math -ftree-vectorizer-verbose=2)
endif()

add_subdirectory(c_array)
add_subdirectory(vector)
