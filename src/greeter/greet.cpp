#include "greeter/greet.hpp"

#include <iostream>


void greet_user(const char *name)
{
    // printf("Hello %s!\n", name);
#ifdef FLAG
    std::cout << "Hello foobar!\n";
    std::cerr << "(Source has been compiled with `FLAG` passed—user name is fixed)\n";
#else
    std::cout << "Hello " << name << "!\n";
#endif
}