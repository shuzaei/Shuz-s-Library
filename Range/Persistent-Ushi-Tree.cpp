
struct UshiTreeP {
    using Type = ll;
    static const Type unit = 0;
    function<Type(Type, Type)> comb = [](Type left, Type right) {
        return left + right;
    };
    struct node {
        ll l, r;
        Type val;
        node(ll l = -1, ll r = -1, Type v = unit) : l(l), r(r), val(v) {}
    };

    static const ll n = 1 << 20;
    vector<node> nodes;
    vector<ll> roots;
    vector<ll> prev;

    UshiTreeP() {
        for (ll i = 0; i < 2 * n - 1; i++) {
            if (i < n) {
                nodes.push_back(node(i * 2 + 1, i * 2 + 2, unit));
            } else {
                nodes.push_back(node());
            }
        }
        roots.push_back(0);
        prev.push_back(0);
    }

    void update(ll a, Type x, ll pver = -1) {
        if (pver < 0) pver += roots.size();
        nodes.push_back(node());
        roots.push_back(nodes.size() - 1);
        prev.push_back(pver);
        update(a, x, roots.back(), roots[prev.back()], 0, n);
    }
    void update(ll a, Type x, ll id, ll pid, ll l, ll r) {
        if (a <= l and r <= a + 1) {
            nodes[id].val = x;
            return;
        }
        nodes.push_back(node());
        if (a >= (l + r) / 2) {
            nodes[id].l = nodes[pid].l;
            nodes[id].r = nodes.size() - 1;
            update(a, x, nodes[id].r, nodes[pid].r, (l + r) / 2, r);
        } else {
            nodes[id].l = nodes.size() - 1;
            nodes[id].r = nodes[pid].r;
            update(a, x, nodes[id].l, nodes[pid].l, l, (l + r) / 2);
        }
        nodes[id].val = comb(nodes[nodes[id].l].val, nodes[nodes[id].r].val);
    }

    Type result(ll a, ll b, ll ver = -1) {
        if (ver < 0) ver += roots.size();
        return result(a, b, roots[ver], 0, n);
    }
    Type result(ll a, ll b, ll id, ll l, ll r) {
        if (b <= l or r <= a) return unit;
        if (a <= l and r <= b) {
            return nodes[id].val;
        } else {
            return comb(result(a, b, nodes[id].l, l, (l + r) / 2),
                        result(a, b, nodes[id].r, (l + r) / 2, r));
        }
    }
};