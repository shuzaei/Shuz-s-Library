
struct Dinic {
    struct edge {
        ll to, cap, rev;
        edge(ll t = 0, ll c = 0, ll r = 0) : to(t), cap(c), rev(r) {}
    };
    ll n;
    vector<vector<edge>> graph;
    vector<ll> itr, level;

    Dinic(ll n) : n(n), graph(n) {}

    void add_edge(ll from, ll to, ll cap) {
        graph[from].push_back(edge(to, cap, graph[to].size()));
        graph[to].push_back(edge(from, 0, graph[from].size() - 1));
    }

    void bfs(ll s) {
        level.assign(n, -1);
        queue<ll> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            ll v = q.front();
            q.pop();
            for (auto &e : graph[v]) {
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    ll dfs(ll v, ll t, ll f) {
        if (v == t) return f;
        for (ll &i = itr[v]; i < (ll) graph[v].size(); ++i) {
            edge &e = graph[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                ll d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll max_flow(ll s, ll t) {
        ll ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(n, 0);
            while ((f = dfs(s, t, inf)) > 0) ret += f;
        }
        return ret;
    }
};