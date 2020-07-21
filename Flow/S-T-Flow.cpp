struct flow {
    struct edge {
        ll to, capasity, reverse;
        edge() {}
        edge(ll a, ll b, ll c) : to(a), capasity(b), reverse(c) {}
    };
    ll V;
    vector<vector<edge>> G;
    vector<bool> used;
    flow(ll N) : V(N), G(N), used(N) {}
    void addEdge(ll from, ll to, ll capasity) {
        ll index = G[to].size(), rindex = G[from].size();
        G[from].push_back(edge(to, capasity, index));
        G[to].push_back(edge(from, 0, rindex));
    }
    ll dfs(ll now, ll to, ll flow) {
        if (now == to) return flow;
        used[now] = true;
        rep(i, G[now].size()) {
            ll next = G[now][i].to, ri = G[now][i].reverse;
            if (!used[next] && G[now][i].capasity > 0) {
                ll drain = dfs(next, to, min(flow, G[now][i].capasity));
                if (drain > 0) {
                    G[now][i].capasity -= drain;
                    G[next][ri].capasity += drain;
                    return drain;
                }
            }
        }
        return 0;
    }
    ll maxFlow(ll s, ll t) {
        ll flow = 0;
        while (true) {
            fill(all(used), 0);
            ll d = dfs(s, t, INF);
            if (d == 0) return flow;
            flow += d;
        }
    }
};
