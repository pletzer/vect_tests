include_directories(${ADMB_DIR}/build/admb/include)

add_executable(dvector dvector.cxx)
target_compile_features(dvector PRIVATE cxx_std_17)
target_link_libraries(dvector ${ADMB_LIBRARY})

add_executable(dvector2 dvector2.cxx)
target_compile_features(dvector2 PRIVATE cxx_std_17)
target_link_libraries(dvector2 ${ADMB_LIBRARY})
