#ifndef def
#include "Shuzaei.hpp"
#endif

inline ll inv(const ll n, const ll m = MOD) {
    ll a = n, b = m, x = 1, y = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        x -= t * y;
        swap(x, y);
    }
    return modulo(x, m);
}

inline constexpr ll modulo(const ll n, const ll m = MOD) {
    ll k = n % m;
    return k + m * (k < 0);
}

inline constexpr ll chmod(ll &n, const ll m = MOD) {
    n %= m;
    return n += m * (n < 0);
}

inline constexpr ll roundup(const ll a, const ll b) {
    if (a % b == 0)
        return a;
    else
        return a + (b - a % b);
}

inline constexpr ll mpow(ll a, ll n, const ll m = MOD) {
    ll r = 1;
    while (n) {
        if (n & 1) r *= a;
        chmod(r, m);
        a *= a;
        chmod(a, m);
        n >>= 1;
    }
    return r;
}
