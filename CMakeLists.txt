cmake_minimum_required (VERSION 3.2)

# want compiler to detect which loops are not vectorized

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	add_compile_options(-O3 -ffast-math -Rpass-analysis=loop-vectorize -Rpass=loop-vectorize -Rpass-missed=loop-vectorize)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
	add_compile_options(-O3 -ffast-math -qopt-report=3)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	add_compile_options(-03 -ffast-math -ftree-vectorizer-verbose=2 -ftree-vectorize)
endif()

find_package(OpenMP)

add_subdirectory(c_array)
add_subdirectory(vector)

# expect the user to set
message(STATUS "ADMB_DIR: ${ADMB_DIR}")
option(ADMB_DIR "Top ADMB directory" "")
file(GLOB ADMB_LIBRARY_LIST ${ADMB_DIR}/build/admb/lib/libadmb-*.a)
message(STATUS "list of admb libraries: ${ADMB_LIBRARY_LIST}")
list(GET ADMB_LIBRARY_LIST 0 ADMB_LIBRARY)
add_subdirectory(dvector)
