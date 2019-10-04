#ifndef def
#include "Shuzaei.hpp"
#endif

#define RAND(a)                                                                \
    {                                                                          \
        random_device rnd;                                                     \
        mt19937_64 a(rnd());                                                   \
    }

uint32_t rgen(void) {
    static uint64_t x = 88172645463325252ULL;
    x = x ^ (x << 13);
    x = x ^ (x >> 7);
    return x = x ^ (x << 17);
}
