# C++ Sanitizers and Static Analysis Examples

## How to build

Build with debug infos, either `-DCMAKE_BUILD_TYPE=RelWithDebInfo` or `-DCMAKE_BUILD_TYPE=Debug`.

### Linux & Mac

```
$ mkdir build
$ cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -B build
$ cmake --build build
```

### Windows

```
PS> mkdir build
PS> cmake -DCMAKE_BUILD_TYPE=Debug -B build
PS> cmake --build build --config Debug
```

## Static Analysis

### clang-tidy

To use `clang-tidy` pass `USE_CLANG_TIDY=ON` to CMake.

```
$ cmake -DUSE_CLANG_TIDY=ON [..]
$ cmake --build .
```

If `clang-tidy` is installed under a different name pass that name or the full path with the `CMAKE_CXX_CLANG_TIDY` option like:

```
$ cmake -DUSE_CLANG_TIDY=ON -DCMAKE_CXX_CLANG_TIDY=/opt/local/bin/clang-tidy-11 [..]
$ cmake --build .
```

## Sanitizers

To use sanitizers pass the `USE_SANITIZER=[..]` option to CMake with one or more of the following values (case insensitive; multiple options delimited by comma or space):

#### GCC and Clang (Linux/macOS)

- `address` or `ASAN`
- `leak` or `LSAN`
- `memory` or `MSAN`
- `thread` or `TSAN`
- `undefined` or `UBSAN`

Make sure to build with eiter either `-DCMAKE_BUILD_TYPE=RelWithDebInfo` or `-DCMAKE_BUILD_TYPE=Debug` or to set `-g` compiler flag manually.

#### MSVC

- `address` or `ASAN`

Make sure to build with eiter either `-DCMAKE_BUILD_TYPE=RelWithDebInfo` or `-DCMAKE_BUILD_TYPE=Debug` or to set `/Zi` compiler flag manually.

### AddressSanitizer (`USE_SANITIZER=` `address` or `ASAN`)

https://github.com/google/sanitizers/wiki/AddressSanitizer

Builds the project targets with `-fsanitize=address -fno-omit-frame-pointer` (GCC, Clang) or `/fsanitize=address` (MSVC).

This automatically enables LeakSanitizer on Linux. To enable it on macOS pass the `ASAN_OPTIONS=detect_leaks=1` flag when running a program.

```
$ cmake -DUSE_SANITIZER=address [..]
$ cmake --build .
```

Some checks are only activated after passing a [run-time flag](https://github.com/google/sanitizers/wiki/AddressSanitizerFlags#run-time-flags):

- **`asan_initialization-order-fiasco`**: Run with either:  
  `ASAN_OPTIONS=check_initialization_order=1`  
  `ASAN_OPTIONS=check_initialization_order=1:strict_init_order=1`
- **`asan_memory-leak_malloc`**  
  **`asan_memory-leak_new`**: Need to run with `ASAN_OPTIONS=detect_leaks=1` on macOS.
- **`asan_stack-use-after-return`**: Need to run with `ASAN_OPTIONS=detect_stack_use_after_return=1`.

### LeakSanitizer (`USE_SANITIZER=` `leak` or `LSAN`)

https://github.com/google/sanitizers/wiki/AddressSanitizerLeakSanitizer

Builds the project targets with `-fsanitize=leak`.

LeakSanitizer is automatically included in AddressSanitizer. This just uses the stand-alone version without the AddressSanitizer overhead.

To use it on macOS run the programs with the `ASAN_OPTIONS=detect_leaks=1` flag.

```
$ cmake -DUSE_SANITIZER=leak [..]
$ cmake --build .
```

### MemorySanitizer (`USE_SANITIZER=` `memory` or `MSAN`)

https://github.com/google/sanitizers/wiki/MemorySanitizer

Builds the project targets with `-fsanitize=memory -fsanitize-memory-track-origins -fno-omit-frame-pointer -fPIE -pie`.

```
$ cmake -DUSE_SANITIZER=memory [..]
$ cmake --build .
```

### ThreadSanitizer (`USE_SANITIZER=` `thread` or `TSAN`)

https://github.com/google/sanitizers/wiki/ThreadSanitizerCppManual

Builds the project targets with `-fsanitize=thread`.

```
$ cmake -DUSE_SANITIZER=thread [..]
$ cmake --build .
```

### UndefinedBehaviorSanitizer (`USE_SANITIZER=` `undefined` or `UBSAN`)

https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html

Builds the project targets with `-fsanitize=undefined -fno-omit-frame-pointer`.

Run the programs with the flag `UBSAN_OPTIONS=print_stacktrace=1` to generate stack traces.

```
$ cmake -DUSE_SANITIZER=undefined [..]
$ cmake --build .
```
