# C++ Sanitizers and Static Analysis Examples

## How to build

Build with debug infos, either `-DCMAKE_BUILD_TYPE=RelWithDebInfo` or `-DCMAKE_BUILD_TYPE=Debug`.

```
$ mkdir build
$ cd build
$ cmake -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_CXX_COMPILER=clang++ ..
$ cmake --build .
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

To use sanitizers pass the `USE_SANITIZER=[..]` option to CMake. Possible values:

- `address`
- `leak`
- `thread`
- `undefined`
- `memory`
- `OFF` (default)

Make sure to build with eiter either `-DCMAKE_BUILD_TYPE=RelWithDebInfo` or `-DCMAKE_BUILD_TYPE=Debug` or to set `-g` compiler flag manually.

### AddressSanitizer (`USE_SANITIZER=address`)

https://github.com/google/sanitizers/wiki/AddressSanitizer

Builds the project targets with `-fsanitize=address -fno-omit-frame-pointer`.

This automatically enables LeakSanitizer on Linux. To enable it on macOS pass the `ASAN_OPTIONS=detect_leaks=true` flag when running a program.

```
$ cmake -DUSE_SANITIZER=address [..]
$ cmake --build .
```

Some checks are only activated after passing a [run-time flag](https://github.com/google/sanitizers/wiki/AddressSanitizerFlags#run-time-flags):

- **`asan_initialization-order-fiasco`**: Run with either:  
  `ASAN_OPTIONS=check_initialization_order=true`  
  `ASAN_OPTIONS=check_initialization_order=true:strict_init_order=true`
- **`asan_memory-leak_malloc`**  
  **`asan_memory-leak_new`**: Need to run with `ASAN_OPTIONS=detect_leaks=true` on macOS.
- **`asan_stack-use-after-return`**: Need to run with `ASAN_OPTIONS=detect_stack_use_after_return=true`.

### LeakSanitizer (`USE_SANITIZER=leak`)

https://github.com/google/sanitizers/wiki/AddressSanitizerLeakSanitizer

Builds the project targets with `-fsanitize=leak`.

LeakSanitizer is automatically included in AddressSanitizer. This just uses the stand-alone version without the AddressSanitizer overhead.

To use it on macOS run the programs with the `ASAN_OPTIONS=detect_leaks=true` flag.

```
$ cmake -DUSE_SANITIZER=leak [..]
$ cmake --build .
```

### ThreadSanitizer (`USE_SANITIZER=thread`)

https://github.com/google/sanitizers/wiki/ThreadSanitizerCppManual

Builds the project targets with `-fsanitize=thread`.

```
$ cmake -DUSE_SANITIZER=thread [..]
$ cmake --build .
```

### UndefinedBehaviorSanitizer  (`USE_SANITIZER=undefined`)

https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html

Builds the project targets with `-fsanitize=undefined -fno-omit-frame-pointer`.

Run the programs with the flag `UBSAN_OPTIONS=print_stacktrace=true` to generate stack traces.

```
$ cmake -DUSE_SANITIZER=undefined [..]
$ cmake --build .
```

### MemorySanitizer (`USE_SANITIZER=memory`)

https://github.com/google/sanitizers/wiki/MemorySanitizer

Builds the project targets with `-fsanitize=memory -fsanitize-memory-track-origins -fno-omit-frame-pointer -fPIE -pie`.

```
$ cmake -DUSE_SANITIZER=memory [..]
$ cmake --build .
```
