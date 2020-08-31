struct SCC {
    ll num, new_num;
    vector<vector<ll>> graph;
    vector<vector<ll>> rgraph;
    vector<vector<ll>> new_graph;
    vector<ll> tp_index;
    vector<ll> nodes;
    vector<bool> used;

    SCC(ll n) : num(n), graph(n), rgraph(n), tp_index(n), used(n) {}
    void add_edge(ll from, ll to) {
        graph[from].push_back(to);
        rgraph[to].push_back(from);
    }
    void dfs(ll pos) {
        used[pos] = true;
        for (ll i : graph[pos])
            if (not used[i]) dfs(i);
        nodes.push_back(pos);
    }
    void rdfs(ll pos, ll k) {
        used[pos] = true, tp_index[pos] = k;
        for (ll i : rgraph[pos])
            if (not used[i]) rdfs(i, k);
    }

    ll scc() {
        fill(used.begin(), used.end(), false);
        nodes.clear();
        for (ll i = 0; i < num; i++)
            if (not used[i]) dfs(i);
        reverse(nodes.begin(), nodes.end());
        fill(used.begin(), used.end(), false);
        ll k = 0;
        for (ll i : nodes)
            if (not used[i]) rdfs(i, k++);
        return new_num = k;
    }

    void new_add_edge(ll from, ll to) {
        ll f = tp_index[from], t = tp_index[to];
        if (f == t) return;
        new_graph[f].push_back(t);
    }
    void build_new_graph() {
        new_graph.resize(new_num);
        for (ll i = 0; i < num; i++)
            for (ll j : graph[i]) new_add_edge(i, j);
        for (vector<ll> &g : new_graph) {
            sort(g.begin(), g.end());
            g.erase(unique(g.begin(), g.end()), g.end());
        }
    }
};