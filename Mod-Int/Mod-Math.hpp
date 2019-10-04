#ifndef def
#include "Shuzaei.hpp"
#endif

template <ull mod = MOD> struct modmath {
    ll max;
    vector<mi<mod>> fac, inv;
    modmath() : max(1 << 20), fac(max + 1), inv(max + 1) {
        fac[0] = mi<mod>(1);
        rep(i, max) fac[i + 1] = fac[i] * (i + 1);
        inv[max] = fac[max].inv();
        dec(i, max - 1, 0) inv[i] = inv[i + 1] * (i + 1);
    }
    modmath(ll n) : max(n), fac(n + 1), inv(n + 1) {
        fac[0] = 1;
        rep(i, n) fac[i + 1] = fac[i] * (i + 1);
        inv[n] = 1 / fac[n];
        dec(i, n - 1, 0) inv[i] = inv[i + 1] * (i + 1);
    }

    inline mi<mod> fact(ll n) {
        if (n < 0) return mi<mod>(0);
        return fac[n];
    }
    inline mi<mod> perm(ll n, ll r) {
        if (r < 0 || n < r) return mi<mod>(0);
        return fac[n] * inv[n - r];
    }
    inline mi<mod> comb(ll n, ll r) {
        if (r < 0 || n < r) return mi<mod>(0);
        return fac[n] * inv[r] * inv[n - r];
    }
    inline mi<mod> nHr(ll n, ll r) { return comb(n + r - 1, n - 1); }
};