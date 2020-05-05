#include "Shuzaei.hpp"

struct UshiTree {
    using Type = ll;
    Type unit = 0;
    function<Type(Type, Type)> comb = [](Type left, Type right) {
        return left + right;
    };

    static const ll n = 1 << 20;
    vector<Type> node;

    UshiTree() : node(2 * n - 1, unit) {}
    inline void combine(ll a, Type x) {
        ll l = 0, r = n, i = 0;
        while (r - l > 1) {
            node[i] = comb(node[i], x);
            ll mid = (l + r) / 2;
            if (l <= a and a < mid) {
                r = mid;
                i = 2 * i + 1;
            } else {
                l = mid;
                i = 2 * i + 2;
            }
        }
        node[i] = comb(node[i], x);
    }
    inline Type result(ll a, ll b, ll i = 0, ll l = 0, ll r = 1 << 20) {
        Type res = unit;
        if (b <= l or r <= a) return res;
        if (a <= l and r <= b) {
            return comb(node[i], res);
        } else {
            return comb(result(a, b, i * 2 + 1, l, (l + r) / 2),
                        result(a, b, i * 2 + 2, (l + r) / 2, r));
        }
    }
};