struct LCA {
    ll n, d = 0, inf = 1000000000;
    vector<ll> dist;
    vector<vector<ll>> root, graph;
    LCA(ll n) : n(n), dist(n, inf), graph(n) {
        ll k = 2 * n;
        while (k /= 2) d++;
        root = vector<vector<ll>>(d, vector<ll>(n, -1));
    }
    void add_edge(ll a, ll b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    void calc() {
        dist[0] = root[0][0] = 0, dfs(0);
        for (ll i = 0; i < d - 1; i++) {
            for (ll j = 0; j < n; j++) {
                if (root[i][j] == -1) continue;
                root[i + 1][j] = root[i][root[i][j]];
            }
        }
    }
    void dfs(ll t) {
        for (ll i : graph[t]) {
            if (dist[i] != inf) continue;
            root[0][i] = t;
            dist[i] = dist[t] + 1;
            dfs(i);
        }
    }
    ll lca(ll a, ll b) {
        if (dist[a] < dist[b]) swap(a, b);
        ll diff = dist[a] - dist[b];
        for (ll i = 0; i < d; i++) {
            if ((1 << i) & diff) a = root[i][a];
        }
        for (ll i = d - 1; i >= 0; i--) {
            if (root[i][a] != root[i][b]) a = root[i][a], b = root[i][b];
        }
        if (a != b) a = root[0][a], b = root[0][b];
        return a;
    }
    ll distance(ll a, ll b) {
        ll par = lca(a, b);
        return dist[a] + dist[b] - 2 * dist[par];
    }
};