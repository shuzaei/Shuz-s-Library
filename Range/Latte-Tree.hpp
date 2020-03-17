#include "Shuzaei.hpp"

struct LatteTree {
    using Type = ll;
    Type unit = 0;
    function<Type(Type, Type)> comb = [](Type left, Type right) {
        return left + right;
    };

    static const ll n = 1 << 20;
    vector<Type> node;

    LatteTree() : node(2 * n - 1, unit) {}
    inline void combine(ll a, ll b, Type x, ll i = 0, ll l = 0,
                        ll r = 1 << 20) {
        if (b <= l or r <= a) return;
        if (a <= l and r <= b) {
            node[i] = comb(node[i], x);
        } else {
            combine(a, b, x, i * 2 + 1, l, (l + r) / 2);
            combine(a, b, x, i * 2 + 2, (l + r) / 2, r);
        }
    }
    inline Type result(ll x) {
        Type res = unit;
        ll l = 0, r = n, i = 0;
        while (r - l > 1) {
            res = comb(res, node[i]);
            ll mid = (l + r) / 2;
            if (l <= x and x < mid) {
                r = mid;
                i = 2 * i + 1;
            } else {
                l = mid;
                i = 2 * i + 2;
            }
        }
        return comb(res, node[i]);
    }
};