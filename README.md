# mINI-lib ![build-passing](https://github.com/TheRealLorenz/mINI-lib/actions/workflows/cmake-multi-platform.yml/badge.svg)

mINI-lib is a dead simple library for INI format handling in C++.

## Glossary

- A `ini::Section` is a `std::unordered_map<std::string, std::string>`, where each key-value pair represents a parameter with its value.
- A `ini::Config` is  a `std::unordered_map<std::string, ini::Section>`, where each key-value pair repesents a section name and its corresponding values.

This types are simple `typdef`s which reduce code verbosity.

## Usage

There are two main functions:

- `void ini::serialize(std::basic_ostream<char>& output, const ini::Config& config)`: serializes a Config objet to the given output stream.
- `ini::Config ini::deserialize(std::basic_istream<char>& input)`: deserializes a Config object to the given input stream.

Using `std::basic_istream<char>` and `std::basic_ostream<char>` Gives more flexibility, as the (de)serialization may occur (from)to `std::fstream`s and `std::stringstream`s, for example.

## Exceptions

`ini::serialize` and `ini::deserialize` may throw `ini::Exception`, which is a subtype of [std::runtime_error](https://en.cppreference.com/w/cpp/error/runtime_error)

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

- **Directly**: run the `runAllTests` target, located in `./<build-folder>/test/` .

- **Using ctest**: from the root directory.
```bash
ctest --test-dir <build-folder>
```
