
namespace MST {
struct wedge_t {
    ll src, dst;
    ll weight;
};

struct graph {
    ll n;
    vector<wedge_t> edges;
    vector<ll> p;
    graph(ll n = 0) : n(n), p(n, -1) {}
    void add_edge(ll src, ll dst, ll weight) {
        edges.push_back({src, dst, weight});
    }
    ll root(ll i) { return p[i] < 0 ? i : p[i] = root(p[i]); }
    bool unite(ll i, ll j) {
        if ((i = root(i)) == (j = root(j))) return false;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j];
        p[j] = i;
        return true;
    }
    ll kruskal(ll k = -1) {
        if (k < 0) k = n - 1;
        sort(edges.begin(), edges.end(),
             [](wedge_t x, wedge_t y) { return x.weight < y.weight; });
        ll result = 0, set_size = n;
        for (auto e : edges) {
            if (unite(e.src, e.dst)) {
                result += e.weight;
                if (--set_size <= k) {
                    break;
                }
            }
        }
        return result;
    }
};
} // namespace MST