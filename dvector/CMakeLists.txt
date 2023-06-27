include_directories(${ADMB_DIR}/build/admb/include)

add_executable(dvector dvector.cxx)
target_compile_features(dvector PRIVATE cxx_std_17)
target_link_libraries(dvector ${ADMB_LIBRARY})
