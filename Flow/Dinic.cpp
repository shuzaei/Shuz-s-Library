struct Dinic {
    struct edge {
        ll to, cap, rev;
        edge() {}
        edge(ll a, ll b, ll c) : to(a), cap(b), rev(c) {}
    };
    vector<vector<edge>> graph;
    vector<bool> used;
    Dinic(ll n) : graph(n), used(n) {}
    void add_edge(ll from, ll to, ll cap) {
        ll index = graph[to].size(), rindex = graph[from].size();
        graph[from].push_back(edge(to, cap, index));
        graph[to].push_back(edge(from, 0, rindex));
    }
    ll dfs(ll now, ll to, ll flow) {
        if (now == to) return flow;
        used[now] = true;
        rep(i, graph[now].size()) {
            ll next = graph[now][i].to, ri = graph[now][i].rev;
            if (!used[next] and graph[now][i].cap > 0) {
                ll drain = dfs(next, to, min(flow, graph[now][i].cap));
                if (drain > 0) {
                    graph[now][i].cap -= drain;
                    graph[next][ri].cap += drain;
                    return drain;
                }
            }
        }
        return 0;
    }
    ll max_flow(ll s, ll t) {
        ll flow = 0;
        while (true) {
            fill(all(used), 0);
            ll d = dfs(s, t, INF);
            if (d == 0) return flow;
            flow += d;
        }
    }
};