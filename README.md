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
- `leak`
- `thread`
- `undefined`
- `memory`
- `OFF` (default)

Make sure to set `-DCMAKE_BUILD_TYPE=` to either `Debug` or `RelWithDebInfo` to include debug symbols or set `-g` compiler flag manually.

#### Address Sanitizer (`USE_SANITIZER=address`)

Builds the project targets with `-fsanitize=address -fno-omit-frame-pointer`.

```
$ cmake -DUSE_SANITIZER=address [..]
$ ninja
```

#### Leak Sanitizer (`USE_SANITIZER=leak`)

Builds the project targets with `-fsanitize=leak`.

```
$ cmake -DUSE_SANITIZER=leak [..]
$ ninja
```

#### Thread Sanitizer (`USE_SANITIZER=thread`)

Builds the project targets with `-fsanitize=thread`.

```
$ cmake -DUSE_SANITIZER=thread [..]
$ ninja
```

#### Undefined Behavior Sanitizer (`USE_SANITIZER=undefined`)

Builds the project targets with `-fsanitize=undefined`.

```
$ cmake -DUSE_SANITIZER=undefined [..]
$ ninja
```

#### Memory Sanitizer (`USE_SANITIZER=memory`)

Builds the project targets with `-fsanitize=memory -fsanitize-memory-track-origins -fno-omit-frame-pointer -fPIE -pie`.

```
$ cmake -DUSE_SANITIZER=memory [..]
$ ninja
```
