#include "Shuzaei.hpp"

struct modmath {
    vector<mint> fac, inv;

    modmath(ll n = 1 << 20) : fac(n + 1), inv(n + 1) {
        fac[0] = 1;
        rep(i, n) fac[i + 1] = fac[i] * (i + 1);
        inv[n] = fac[n].inv();
        dec(i, n - 1, 0) inv[i] = inv[i + 1] * (i + 1);
    }

    mint F(ll n) {
        if (n < 0) return 0;
        return fac[n];
    }
    mint P(ll n, ll r) {
        if (r < 0 || n < r || n < 0) return 0;
        return fac[n] * inv[n - r];
    }
    mint C(ll n, ll r) {
        if (r < 0 || n < r || n < 0) return 0;
        return fac[n] * inv[r] * inv[n - r];
    }
    mint c(ll n) {
        if (n < 0) return 0;
        return fac[2 * n] * inv[n] * inv[n + 1];
    }
    mint H(ll n, ll r) { return C(n + r - 1, n - 1); }
} math;