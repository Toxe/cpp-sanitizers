# C++ Sanitizers and Static Analysis Examples

## Dependencies

- Clang
- CMake

## How to build

```
$ mkdir build
$ cd build
$ cmake -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_CXX_COMPILER=clang++ ..
$ ninja
```

### Static Analysis

#### clang-tidy

To use `clang-tidy` pass `USE_CLANG_TIDY=ON` to CMake.

```
$ cmake -DUSE_CLANG_TIDY=ON [..]
$ ninja
```

### Sanitizers

To use sanitizers pass the `USE_SANITIZER=[..]` option to CMake. Possible values:

- `address`
- `OFF` (default)

Make sure to set `-DCMAKE_BUILD_TYPE=` to either `Debug` or `RelWithDebInfo` to include debug symbols or set `-g` compiler flag manually.

#### Address Sanitizer (`USE_SANITIZER=address`)

Builds the project targets with `-fsanitize=address -fno-omit-frame-pointer`.

```
$ cmake -DUSE_SANITIZER=address [..]
$ ninja
```
