#include "Shuzaei.hpp"

struct modmath {
    ll max;
    vector<mint> fac, inv;

    modmath(ll n = 1 << 20) : max(n), fac(n + 1), inv(n + 1) {
        fac[0] = 1;
        rep(i, n) fac[i + 1] = fac[i] * (i + 1);
        inv[n] = 1 / fac[n];
        dec(i, n - 1, 0) inv[i] = inv[i + 1] * (i + 1);
    }

    mint fact(ll n) {
        if (n < 0) return 0;
        return fac[n];
    }
    mint perm(ll n, ll r) {
        if (r < 0 || n < r || n < 0) return 0;
        return fac[n] * inv[n - r];
    }
    mint comb(ll n, ll r) {
        if (r < 0 || n < r || n < 0) return 0;
        return fac[n] * inv[r] * inv[n - r];
    }
    mint cat(ll n) {
        if (n < 0) return 0;
        return fac[2 * n] * inv[n] * inv[n + 1];
    }
    mint nHr(ll n, ll r) { return comb(n + r - 1, n - 1); }
} math;
