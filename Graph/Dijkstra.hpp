#include "Shuzaei.hpp"

template <typename T = ll> struct Dijkstra {
    ll V;
    using P = pair<ll, T>;
    using P2 = pair<T, ll>;
    vector<vector<P>> G;
    vector<T> dist;
    vector<bool> used;
    Dijkstra(ll v) : V(v), G(v), dist(v), used(v) {}
    void setDist(ll a, ll b, ll d) { G[a].push_back(P(b, d)); }
    void calc(ll s = 0) {
        priority_queue<P2, vector<P2>, greater<P2>> Q;
        Q.push(P2(0, s));
        fill_n(dist.begin(), V, INF);
        fill_n(used.begin(), V, false);
        while (!Q.empty()) {
            T d;
            ll t;
            tie(d, t) = Q.top(), Q.pop();
            if (used[t]) continue;
            used[t] = true, dist[t] = d;
            for (P e : G[t]) {
                if (dist[e.first] <= d + e.second) continue;
                Q.push(P(d + e.second, e.first));
            }
        }
    }
};
