#include "Shuzaei.hpp"

struct MST {
    struct wedge_t {
        ll src, dst;
        ll weight;
    };

    struct graph {
        ll n;
        vector<wedge_t> edges;
        graph(ll n = 0) : n(n) { p.assign(n, -1); }
        void add_edge(ll src, ll dst, ll weight) {
            n = max(n, max(src, dst) + 1);
            edges.push_back({src, dst, weight});
        }
        vector<ll> p;
        ll root(ll i) { return p[i] < 0 ? i : p[i] = root(p[i]); }
        bool unite(ll i, ll j) {
            if ((i = root(i)) == (j = root(j))) return false;
            if (p[i] > p[j]) swap(i, j);
            p[i] += p[j];
            p[j] = i;
            return true;
        }
        ll kruskal() {
            all(sort, edges,
                [](wedge_t x, wedge_t y) { return x.weight < y.weight; });
            ll result = 0;
            for (auto e : edges)
                if (unite(e.src, e.dst)) result += e.weight;
            return result;
        }
    };
};
