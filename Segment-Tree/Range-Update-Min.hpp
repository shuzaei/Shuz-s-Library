#ifndef def
#include "Shuzaei.hpp"
#endif

struct RUMQ {
    static const ll n = 1LL << 20;
    vector<ll> node, lazy, flag;
    RUMQ() : node(n * 2 - 1), lazy(n * 2 - 1), flag(n * 2 - 1) {}
    inline void eval(ll i, ll l, ll r) {
        if (flag[i]) {
            node[i] = lazy[i];
            if (r - l > 1) {
                lazy[i * 2 + 1] = lazy[i * 2 + 2] = lazy[i];
                flag[i * 2 + 1] = flag[i * 2 + 2] = true;
            }
            lazy[i] = 0;
            flag[i] = false;
        }
    }
    inline void update(ll a, ll b, ll x, ll i = 0, ll l = 0, ll r = 1LL << 20) {
        eval(i, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[i] = x;
            flag[i] = true;
            eval(i, l, r);
        } else {
            update(a, b, x, i * 2 + 1, l, (l + r) / 2);
            update(a, b, x, i * 2 + 2, (l + r) / 2, r);
            node[i] = std::min(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }
    inline ll min(ll a, ll b, ll i = 0, ll l = 0, ll r = 1LL << 20) {
        if (b <= l || r <= a) return INF;
        eval(i, l, r);
        if (a <= l && r <= b) return node[i];
        return std::min(min(a, b, i * 2 + 1, l, (l + r) / 2),
                        min(a, b, i * 2 + 2, (l + r) / 2, r));
    }
};
