struct CoefficientTree {
    static const ll n = 1 << 20;
    using Group = ll;
    using Scalar = ll;
    Group unitG = 0;
    Scalar unitS = 1;
    function<Group(Group, Group)> add = [](Group left, Group right) { return left + right; };
    function<Group(Group)> inv = [](Group x) { return -x; };
    function<Group(Scalar, Group)> mul = [](Scalar left, Group right) { return left * right; };

    vector<Group> node;
    vector<Group> s;
    vector<Scalar> c;

    CoefficientTree() : node(2 * n - 1, unitG), s(n, unitG), c(n, unitS) {}

    inline void distribute(ll a, ll b, Group x, ll i = 0, ll l = 0, ll r = n) {
        if (b <= l or r <= a) return;
        if (a <= l and r <= b) {
            node[i] = add(node[i], x);
        } else {
            distribute(a, b, x, i * 2 + 1, l, (l + r) / 2);
            distribute(a, b, x, i * 2 + 2, (l + r) / 2, r);
        }
    }
    inline void update(ll a, Group x) { distribute(a, a + 1, add(inv(get(a)), x)); }
    inline Group get(ll a) {
        Group res = unitG;
        ll i = n - 1 + a;
        while (i != 0) {
            res = add(res, node[i]);
            i = (i - 1) / 2;
        }
        return add(s[a], mul(c[a], add(res, node[i])));
    }
    inline void change(ll a, Scalar x) {
        Group sum = get(a);
        c[a] = 1, update(a, unitG);
        c[a] = x, s[a] = add(s[a], mul(c[a], sum));
    }
};