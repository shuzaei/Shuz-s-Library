#include "Shuzaei.hpp"

struct Miller {
    const vector<ll> v = {2, 7, 61}; // < 4,759,123,141
    // x^k (mod m)
    ll modpow(ll x, ll k, ll m) {
        ll res = 1;
        while (k) {
            if (k & 1) {
                res = res * x % m;
            }
            k /= 2;
            x = x * x % m;
        }
        return res;
    }
    // check if n is prime
    bool check(ll n) {
        if (n < 2) {
            return false;
        }
        ll d = n - 1;
        ll s = 0;
        while (d % 2 == 0) {
            d /= 2;
            s++;
        }
        for (ll a : v) {
            if (a == n) {
                return true;
            }
            if (modpow(a, d, n) != 1) {
                bool ok = true;
                for (ll r = 0; r < s; r++) {
                    if (modpow(a, d * (1LL << r), n) == n - 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    return false;
                }
            }
        }
        return true;
    }
};

struct Rho {
    mt19937 mt;
    Miller miller;
    ll c;
    Rho() { mt.seed(clock()); }
    inline ll f(ll x, ll n) { return (x * x + c) % n; }
    ll check(ll n) {
        if (n == 4) {
            return 2;
        }
        c = mt() % n;
        ll x = mt() % n;
        ll y = x;
        ll d = 1;
        while (d == 1) {
            x = f(x, n);
            y = f(f(y, n), n);
            d = __gcd(abs(x - y), n);
        }
        if (d == n) {
            return -1;
        }
        return d;
    }
    vector<ll> factor(ll n) {
        if (n <= 1) {
            return {};
        }
        if (miller.check(n)) {
            return {n};
        }
        ll res = -1;
        while (res == -1) {
            res = check(n);
        }
        vector<ll> fa = factor(res);
        vector<ll> fb = factor(n / res);
        fa.insert(fa.end(), fb.begin(), fb.end());
        return fa;
    }
};
