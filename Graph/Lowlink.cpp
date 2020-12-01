struct Lowlink {
    int t;
    vector<int> ord, low;
    graph g;
    Lowlink(int n) : ord(n, -1), low(n), g(n), t(0) {}
    void calc(int v = 0, int p = -1) {
        ord[v] = low[v] = t++;
        for (auto &u : g[v]) {
            if (ord[u] == -1) {
                calc(u, v);
                low[v] = min(low[u], low[v]);
            } else if (u != p) {
                low[v] = min(ord[u], low[v]);
            }
        }
    }
    bool is_bridge(int u, int v) { return ord[u] < low[v]; }
    bool is_articulation_point(int v) {
        if (v == 0) {
            return g[v].size() > 1;
        } else {
            for (auto &u : g[v])
                if (ord[v] <= low[u]) return true;
            return false;
        }
    }
}