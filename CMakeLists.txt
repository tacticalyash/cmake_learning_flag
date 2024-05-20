# Specify the minimum version of CMake to use.
# CMake can have different behaviors (policies) based on its version used.
cmake_minimum_required(VERSION 3.14)


# Name the project, its version, and languages used in it.
set(PROJECT_NAME cmake_learning_gist)
project(${PROJECT_NAME}
        VERSION 0.1.0
        LANGUAGES C CXX
    )


# Fix language standards, and set hard requirements for such.
# All targets defined from this point onward will pick up these requirements.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The language standard can still be set to some platform-specific standard of the same version, e.g.
# instead of `-std=c++11`, `-std=gnu++11` might be used in the compilation. The `CMAKE_CXX_EXTENSIONS`
# flag governs whether this can be done, and the default behavior is for C++ extensions to be enabled.
# For broader compatibility across compilers and OS, projects should prefer to explicitly disable them.
set(CMAKE_CXX_EXTENSIONS OFF)


# Bundle the warning flags that we want to pass on to the compiler.
# Reference: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
set(WARNING_FLAGS -Wall -Wextra)

# Suppress some unwanted warning flags from passing on to the compiler.
set(SUPPRESS_WARNING_FLAGS -Wno-unknown-pragmas)

# Bundle the extra optimization flags (not associated with the `-O` levels)
# that we want to pass on to the compiler.
# Reference: https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
set(OPTIMIZE_FLAGS -funroll-loops)

# Bundle debugging information flags that we want to conditionally
# pass on to the compiler.
set(DEBUG_FLAGS -ggdb)


# Add required preprocessor definitions (`#define`s) to pass on.
# E.g. to pass a ``boolean''-type definition `FLAG`, use e.g. `cmake -DFLAG=ON ..`.
# `ON` is a placeholder here—anything will do.
if(FLAG)
    add_compile_definitions(FLAG)
endif()

# To pass on preprocessor definitions with values, use e.g. `cmake -DMAX_N=19 ..`.
if(MAX_N)
    add_compile_definitions(MAX_N=${MAX_N})
endif()


# Search the file system for the appropriate threads package for this platform.
find_package(Threads REQUIRED)



# Just printing out the project root directory (a sanity check may be?).
message("Project root: " ${CMAKE_SOURCE_DIR})


# The `Debug` configuration optimizes the program for debugging and enables full debug information.
# The `Release` configuration enables most compiler optimizations for speed and defines `NDEBUG`
# (No Debug) which will remove all traces of the standard library assert calls.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()


# Add subdirectory `src` to the build; CMake will open `src/CMakeLists.txt` for such.
add_subdirectory(src)
