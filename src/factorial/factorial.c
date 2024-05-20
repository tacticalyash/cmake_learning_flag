#include "factorial/factorial.h"

#include <stdio.h>


uint64_t factorial(int num)
{
#ifdef MAX_N
    if(num > MAX_N)
    {
        printf("Provided value cannot be larger than %d (fixed at compile-time).\n");
        return 0;
    }
#endif

    if(num < 0)
        return 0;

    if(num == 0)
        return 1;

    int f = num;    // While building the project, check how the `make` or the `make install` produces a warning
                    // for this line, as the warning flags are enabled in the CMake options.

    return num * factorial(num - 1);
}
