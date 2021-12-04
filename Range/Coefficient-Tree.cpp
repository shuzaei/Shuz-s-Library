struct CoefficientTree {
    static const ll n = 1 << 20;
    using Type = ll;
    Type unit = 0;
    function<Type(Type, Type)> add = [](Type left, Type right) { return left + right; };
    function<Type(Type, Type)> mul = [](Type left, Type right) { return left * right; };
    function<Type(Type)> inv = [](Type x) { return -x; };

    struct LatteTree {
        vector<Type> node;

        LatteTree() : node(2 * n - 1, unit) {}
        inline void combine(ll a, ll b, Type x, ll i = 0, ll l = 0, ll r = n) {
            if (b <= l or r <= a) return;
            if (a <= l and r <= b) {
                node[i] = add(node[i], x);
            } else {
                combine(a, b, x, i * 2 + 1, l, (l + r) / 2);
                combine(a, b, x, i * 2 + 2, (l + r) / 2, r);
            }
        }
        inline Type result(ll x) {
            Type res = unit;
            ll i = n - 1 + x;
            while (i != 0) {
                res = add(res, node[i]);
                i = (i - 1) / 2;
            }
            return add(res, node[i]);
        }
    } tree;

    vector<Type> s, a;
    CoefficientTree() : s(n, unit), a(n, unit) {}
    inline void change(ll x, ll k) {
        Type sum = tree.result(x);
        s[x] = add(s[x], mul(a[x], sum));
        a[x] = k;
        tree.combine(x, x + 1, inv(sum));
    }
    inline void add(ll a, ll b, Type x) { tree.combine(a, b, x); }
    inline Type get(ll x) { return add(s[x], mul(a[x], tree.result(x))); }
};