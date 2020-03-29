option(USE_SANITIZER "Enable sanitizer. Options are: OFF, address, leak" OFF)

string(TOLOWER ${USE_SANITIZER} USE_SANITIZER)

if(USE_SANITIZER STREQUAL "address")
    set(SANITIZER_FLAGS -fsanitize=address -fno-omit-frame-pointer)
elseif(USE_SANITIZER STREQUAL "leak")
    set(SANITIZER_FLAGS -fsanitize=leak)
endif()

if(SANITIZER_FLAGS)
    message(STATUS "Using sanitizer: " ${USE_SANITIZER})
endif()
