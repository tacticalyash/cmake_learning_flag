#ifndef FACTORIAL_H
#define FACTORIAL_H

// While including a C header that is not system provided, you should strongly consider adding
// `extern "C" {...}` logic inside the header to make it easier for C++ code to `#include` the
// header into the code. A C compiler does not understand the `extern "C"` construct, and hence
// the `extern "C" {` and `}` must be wrapped in an `#ifdef __cplusplus` construct, sandwiching
// the entire C header in between. Note that, `__cplusplus` is defined iff the compiler is a C++
// compiler. The `extern "C"` statement makes the wrapped block of code to have a C linkage to
// which the C definitions (from .c files) can link to. Briefly, as C++ supports function
// overloading, it augments the name of its functions with its parameters' information in the
// binary to assign unique ids to the functions. As C does not support overloading, it can use
// the functions' names directly as their ids. If the C++ compiler augments the C functions' names
// too (encountered in the header files), then it will modify the functions' names in the binary;
// but the functions' definitions (which reside in .c files) will be compiled by a C compiler.
// Then later the C linker will not be able to link the functions' invocations to their definitions
// using their names as the ids.
#ifdef __cplusplus
extern "C"
{
#endif


#include <stdint.h>


uint64_t factorial(int num);


#ifdef __cplusplus
}
#endif


#endif // FACTORIAL_H