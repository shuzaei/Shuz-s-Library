struct RASQ {
    static const ll n = 1LL << 20;
    vector<ll> node, lazy;
    RASQ() : node(n * 2 - 1), lazy(n * 2 - 1) {}
    inline void eval(ll i, ll l, ll r) {
        node[i] += lazy[i];
        if (r - l > 1) {
            lazy[i * 2 + 1] += lazy[i] / 2;
            lazy[i * 2 + 2] += lazy[i] / 2;
        }
        lazy[i] = 0;
    }
    inline void add(ll a, ll b, ll x, ll i = 0, ll l = 0, ll r = 1LL << 20) {
        eval(i, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[i] += (r - l) * x;
            eval(i, l, r);
        } else {
            add(a, b, x, i * 2 + 1, l, (l + r) / 2);
            add(a, b, x, i * 2 + 2, (l + r) / 2, r);
            node[i] = node[i * 2 + 1] + node[i * 2 + 2];
        }
    }
    inline ll sum(ll a, ll b, ll i = 0, ll l = 0, ll r = 1LL << 20) {
        if (b <= l || r <= a) return 0;
        eval(i, l, r);
        if (a <= l && r <= b) return node[i];
        return sum(a, b, i * 2 + 1, l, (l + r) / 2) +
               sum(a, b, i * 2 + 2, (l + r) / 2, r);
    }
};
