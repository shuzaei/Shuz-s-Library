#include "Shuzaei.hpp"

struct random {
    random_device rd;
    mt19937_64(rd()) rand;
};

struct hash {
    static uint64_t xorshift(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t __RAND__ =
            chrono::steady_clock::now().time_since_epoch().count();
        return xorshift(x + __RAND__);
    }

    template <class T> using set<T> = unordered_set<T, hash>;
    template <class T> using map<T> = unordered_map<T, hash>;
};

uint32_t rgen() {
    static uint64_t x = 88172645463325252ULL;
    x = x ^ (x << 13);
    x = x ^ (x >> 7);
    return x = x ^ (x << 17);
}