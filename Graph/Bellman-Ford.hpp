#include "Shuzaei.hpp"

struct BellmanFord {
    struct edge {
        ll to, cost;
        edge(ll a, ll b) : to(a), cost(b) {}
    };
    using graph = vector<vector<edge>>;
    ll N;
    graph G;
    vector<ll> dist, from;
    vector<bool> error_loop;
    BellmanFord(ll n) : N(n), G(n), dist(n), from(n), error_loop(n) {}
    void setDist(ll from, ll to, ll cost) { G[from].push_back(edge(to, cost)); }
    void culc(ll start = 0) {
        fill(dist.begin(), dist.end(), INF);
        fill(from.begin(), from.end(), -1);
        fill(error_loop.begin(), error_loop.end(), false);
        dist[start] = 0;
        rep(i, N - 1) rep(j, N) rep(k, G[j].size()) {
            ll to = G[j][k].to;
            if (dist[j] == INF) continue;
            if (dist[to] > dist[j] + G[j][k].cost) {
                dist[to] = dist[j] + G[j][k].cost;
                from[to] = j;
            }
        }
        rep(i, N) rep(j, N) rep(k, G[j].size()) {
            ll to = G[j][k].to;
            if (dist[j] == INF) continue;
            if (dist[to] > dist[j] + G[j][k].cost) error_loop[to] = true;
            if (error_loop[j]) error_loop[to] = true;
        }
    }
};
