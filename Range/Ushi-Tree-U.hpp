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
    inline void update(ll a, Type x) {
        ll i = n - 1 + a;
        node[i] = x;
        while (i != 0) {
            i = (i - 1) / 2;
            node[i] = comb(node[i * 2 + 1], node[i * 2 + 2]);
        }
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