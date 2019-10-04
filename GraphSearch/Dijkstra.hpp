#ifndef def
#include "Shuzaei.hpp"
#endif

template <typename T = ll> struct Dijkstra {
    ll V;
    using P = pair<ll, ll>;
    vector<vector<P>> G;
    vector<T> dist;
    vector<bool> used;
    Dijkstra(ll v) : V(v), G(v), dist(v), used(v) {}
    void setDist(ll a, ll b, ll d) { G[a].push_back(P(d, b)); }
    void culc(ll s = 0) {
        priority_queue<P, vector<P>, greater<P>> Q;
        Q.push(P(0, s));
        fill_n(dist.begin(), V, INF);
        fill_n(used.begin(), V, false);
        while (!Q.empty()) {
            T d;
            ll t;
            tie(d, t) = Q.top(), Q.pop();
            if (used[t]) continue;
            used[t] = true, dist[t] = d;
            for (P e : G[t]) {
                if (dist[e.second] <= d + e.first) continue;
                Q.push(P(d + e.first, e.second));
            }
        }
    }
};
