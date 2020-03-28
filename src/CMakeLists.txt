set(ALL_TARGETS
    asan_global-buffer-overflow
    asan_heap-buffer-overflow
    asan_heap-use-after-free
    asan_stack-buffer-overflow
    asan_stack-use-after-return
)

foreach(target ${ALL_TARGETS})
    add_executable(${target} ${target}.cpp)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(${target} PUBLIC cxx_std_17)
    target_compile_options(${target} PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_link_libraries(${target} PRIVATE ${SANITIZER_FLAGS})

    # disable some (useful) warnings that, in this case, are a bit annoying for example programs
    target_compile_options(${target} PRIVATE -Wno-unused-parameter)
endforeach()
