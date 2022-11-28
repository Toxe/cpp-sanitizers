set(USE_SANITIZER "" CACHE STRING "Enable sanitizer(s). Options are: address, leak, memory, thread, undefined, ASAN, LSAN, MSAN, TSAN, UBSAN. Case insensitive; multiple options delimited by comma or space possible.")

string(TOLOWER "${USE_SANITIZER}" USE_SANITIZER)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC"))
    # MSVC and Clang-cl
    if (USE_SANITIZER MATCHES "address" OR USE_SANITIZER MATCHES "asan")
        list(APPEND SANITIZER_FLAGS /fsanitize=address)
    endif ()
else ()
    # GCC and Clang
    if (USE_SANITIZER MATCHES "address" OR USE_SANITIZER MATCHES "asan")
        list(APPEND SANITIZER_FLAGS -fsanitize=address -fno-omit-frame-pointer)
    endif ()

    if (USE_SANITIZER MATCHES "leak" OR USE_SANITIZER MATCHES "lsan")
        list(APPEND SANITIZER_FLAGS -fsanitize=leak -fno-omit-frame-pointer)
    endif ()

    if (USE_SANITIZER MATCHES "memory" OR USE_SANITIZER MATCHES "msan")
        list(APPEND SANITIZER_FLAGS -fsanitize=memory -fsanitize-memory-track-origins -fno-omit-frame-pointer -fPIE -pie)
    endif ()

    if (USE_SANITIZER MATCHES "thread" OR USE_SANITIZER MATCHES "tsan")
        list(APPEND SANITIZER_FLAGS -fsanitize=thread -fno-omit-frame-pointer)
    endif ()

    if (USE_SANITIZER MATCHES "undefined" OR USE_SANITIZER MATCHES "ubsan")
        list(APPEND SANITIZER_FLAGS -fsanitize=undefined -fno-omit-frame-pointer)
    endif ()
endif ()

list(REMOVE_DUPLICATES SANITIZER_FLAGS)

if (SANITIZER_FLAGS)
    message(STATUS "Using sanitizer: " ${USE_SANITIZER})
endif ()
