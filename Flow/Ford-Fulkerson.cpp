struct Ford_Fulkerson {
    struct edge {
        ll to, cap, rev;
        edge() {}
        edge(ll a, ll b, ll c) : to(a), cap(b), rev(c) {}
    };
    vector<vector<edge>> graph;
    vector<bool> used;
    Ford_Fulkerson(ll n) : graph(n), used(n) {}
    void add_edge(ll from, ll to, ll cap) {
        ll index = graph[to].size(), rindex = graph[from].size();
        graph[from].push_back(edge(to, cap, index));
        graph[to].push_back(edge(from, 0, rindex));
    }
    ll dfs(ll now, ll to, ll flow) {
        if (now == to) return flow;
        used[now] = true;
        for (edge &e : graph[now]) {
            if (!used[e.to] and e.cap > 0) {
                ll drain = dfs(e.to, to, min(flow, e.cap));
                if (drain > 0) {
                    e.cap -= drain;
                    graph[e.to][e.rev].cap += drain;
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