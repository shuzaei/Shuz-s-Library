#ifndef def
#include "Shuzaei.hpp"
#endif

struct starry_sky_tree {
    ll size;
    vector<ll> data;
    vector<ll> lazy;
    vector<ll> width;

    starry_sky_tree(ll n) {
        size = 1;
        while (size < n) size <<= 1;
        data.resize(size * 2, 0);
        lazy.resize(size * 2, 0);
        width.resize(size * 2, 1);
        for (ll i = size - 2; i >= 0; i--) {
            width[i] = width[i * 2 + 1] + width[i * 2 + 2];
        }
    }

    inline void eval(ll p) {
        data[p] += lazy[p];
        if (p < size - 1) {
            lazy[p * 2 + 1] += lazy[p];
            lazy[p * 2 + 2] += lazy[p];
        }
        lazy[p] = 0;
    }

    inline void add(ll a, ll b, ll x) { add(a, b, 0, size, 0, x); }
    inline void add(ll a, ll b, ll l, ll r, ll k, ll x) {
        if (b <= l || r <= a) {
            eval(k);
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] += x;
            eval(k);
            return;
        }
        eval(k);
        add(a, b, l, (l + r) / 2, k * 2 + 1, x);
        add(a, b, (l + r) / 2, r, k * 2 + 2, x);
        data[k] = max(data[k * 2 + 1], data[k * 2 + 2]);
    }

    inline ll getmax(ll a, ll b) { return getmax(a, b, 0, size, 0); }
    inline ll getmax(ll a, ll b, ll l, ll r, ll k) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) {
            eval(k);
            return data[k];
        }
        ll L = getmax(a, b, l, (l + r) / 2, k * 2 + 1);
        ll R = getmax(a, b, (l + r) / 2, r, k * 2 + 2);
        return max(L, R);
    }
};
