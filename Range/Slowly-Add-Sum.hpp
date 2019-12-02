#include "Shuzaei.hpp"

struct segtree {
    static const ll n = 1 << 20;

    ll all[2 * n - 1], part[2 * n - 1];

    inline void add(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = n) {
        if (a <= l && r <= b) {
            all[k] += x;
        } else if (l < b && a < r) {
            part[k] += (min(b, r) - max(a, l)) * x;
            add(a, b, x, k * 2 + 1, l, (l + r) / 2);
            add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        }
    }

    inline ll sum(ll a, ll b, ll k = 0, ll l = 0, ll r = n) {
        if (b <= l || r <= a) {
            return (0);
        } else if (a <= l && r <= b) {
            return (all[k] * (r - l) + part[k]);
        } else {
            ll res;
            res = (min(b, r) - max(a, l)) * all[k];
            res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
            res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
            return (res);
        }
    }
};
