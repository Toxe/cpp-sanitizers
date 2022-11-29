set(ALL_TARGETS
    asan_global-buffer-overflow
    asan_heap-buffer-overflow
    asan_heap-use-after-free
    asan_stack-buffer-overflow
    asan_stack-use-after-return
    asan_stack-use-after-scope
    asan_memory-leak_malloc
    asan_memory-leak_new
    asan_initialization-order-fiasco
    lsan_memory-leak_malloc
    lsan_memory-leak_new
    tsan_data-race
    ubsan_bool
    ubsan_bounds
    msan_use-of-uninitialized-value
)

add_executable(asan_global-buffer-overflow asan_global-buffer-overflow.cpp)
add_executable(asan_heap-buffer-overflow asan_heap-buffer-overflow.cpp)
add_executable(asan_heap-use-after-free asan_heap-use-after-free.cpp)
add_executable(asan_stack-buffer-overflow asan_stack-buffer-overflow.cpp)
add_executable(asan_stack-use-after-return asan_stack-use-after-return.cpp)
add_executable(asan_stack-use-after-scope asan_stack-use-after-scope.cpp)
add_executable(asan_memory-leak_malloc asan_memory-leak_malloc.cpp)
add_executable(asan_memory-leak_new asan_memory-leak_new.cpp)
add_executable(asan_initialization-order-fiasco asan_initialization-order-fiasco.cpp
                                                asan_initialization-order-fiasco_helper.cpp)
add_executable(lsan_memory-leak_malloc lsan_memory-leak_malloc.cpp)
add_executable(lsan_memory-leak_new lsan_memory-leak_new.cpp)
add_executable(tsan_data-race tsan_data-race.cpp)
add_executable(ubsan_bool ubsan_bool.cpp)
add_executable(ubsan_bounds ubsan_bounds.cpp)
add_executable(msan_use-of-uninitialized-value msan_use-of-uninitialized-value.cpp)

foreach(target ${ALL_TARGETS})
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(${target} PUBLIC cxx_std_20)
    target_compile_options(${target} PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(${target} PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(${target} PRIVATE ${SANITIZER_LINK_LIBRARIES})

    # disable some (useful) warnings that, in this case, are a bit annoying for example programs
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(${target} PRIVATE -Wno-unused-parameter -Wno-unused-variable -Wno-array-bounds -Wno-uninitialized -Wno-return-stack-address)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        target_compile_options(${target} PRIVATE -Wno-unused-parameter -Wno-unused-variable -Wno-array-bounds -Wno-uninitialized -Wno-unused-but-set-variable -Wno-return-local-addr)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        target_compile_options(${target} PRIVATE /wd4100)
    endif()
endforeach()

target_link_libraries(tsan_data-race PRIVATE Threads::Threads)
