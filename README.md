# mINI-lib ![build-passing](https://github.com/TheRealLorenz/mINI-lib/actions/workflows/cmake-multi-platform.yml/badge.svg)

mINI-lib is a dead simple library for INI file handling in C++.

## Glossary

- A `ini::Section` is a `std::unordered_map<std::string, std::string>`, where each key-value pair represents a parameter with its value.
- A `ini::Config` is  a `std::unordered_map<std::string, ini::Section>`, where each key-value pair repesents a section name and its corresponding values.

This types are simple `typdef`s which reduce code verbosity.

## Usage

There are two main functions:

- `void ini::serialize(std::string fileName, const ini::Config& config)`: serializes a Config objet to `fileName`.
- `ini::Config ini::deserialize(std::string fileName)`: deserializes a Config object from `fileName`.

## Exceptions

TODO: now the code just prints to stderr

## Building from source

```bash
git clone https://github.com/TheRealLorenz/mINI-lib.git
cd mINI-lib/
mkdir build
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
cmake --build build
```

The `build` folder will then contain a **static** and **shared** version of the library.

## Testing

Tests are built with the `runAllTests` target, the [googletest](https://github.com/google/googletest) library is fetched automatically at configure-time by the [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) directives.

### Running the tests

- **Directly**: run the `runAllTests` target, located in ./<build-folder>/test/ .

- **Using ctest**: from the root directory.
```bash
ctest --test-dir <build-folder>
```
