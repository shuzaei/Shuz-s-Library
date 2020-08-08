struct tree {
    void dfs_sz(int v = 0, int p = -1) {
        sz[v] = 1;
        for (auto &u : g[v]) {
            if (u == p) continue;
            dfs_sz(u, v);
            sz[v] += sz[u];
            if (sz[u] > sz[g[v][0]]) swap(u, g[v][0]);
        }
    }
    void dfs_hld(int v = 0, int p = -1) {
        in[v] = t++;
        for (auto u : g[v]) {
            if (u == p) continue;
            nxt[u] = (u == g[v][0] ? nxt[v] : u);
            dfs_hld(u, v);
        }
        out[v] = t;
    }
    void dfs_sub(int v = 0, int p = -1) {
        ls[v] = t++;
        for (int u : G[v]) {
            if (u != p) dfs_sub(u, v);
        }
        rs[v] = t;
    }
    void dfs_path(int v = 0, int p = -1) {
        ds[u] = t++;
        for (int u : G[v]) {
            if (u == p) continue;
            dfs_path(u, v);
        }
        us[u] = t++;
    }
};
