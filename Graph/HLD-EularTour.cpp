struct HLD {
    int t;
    vector<int> sz, par, in, out, nxt;
    graph g;
    HLD(int n) : sz(n, 1), par(n), in(n), out(n), nxt(n), g(n) {}
    void erase_par(int v = 0, int p = -1) {
        for (auto &u : g[v]) {
            if (v != 0 and u == g[v].back()) break;
            if (u == p) swap(u, g[v].back());
            par[u] = v, erase_par(u, v);
        }
        if (v != 0) g[v].pop_back();
    }
    void dfs_sz(int v = 0) {
        for (auto &u : g[v]) {
            dfs_sz(u), sz[v] += sz[u];
            if (sz[u] > sz[g[v][0]]) swap(u, g[v][0]);
        }
    }
    void dfs_hld(int v = 0) {
        in[v] = t++;
        for (auto u : g[v]) nxt[u] = (u == g[v][0] ? nxt[v] : u), dfs_hld(u);
        out[v] = t;
    }
    int lca(int u, int v) {
        while (true) {
            if (in[u] > in[v]) swap(u, v);
            if (nxt[u] == nxt[v]) return u;
            v = par[nxt[v]];
        }
    }
    void calc() { erase_par(), dfs_sz(), t = 0, dfs_hld(); }
    void path_query(int u, int v) {
        while (nxt[u] != nxt[v]) {
            if (in[u] > in[v]) swap(u, v);
            // query for [max(in[nxt[v]], in[u]), in[v]]
            if (nxt[u] == nxt[v]) return;
            v = par[nxt[v]];
        }
    }
    void subtree_query(int v) {
        // query for [in[v], out[v])
    }
};

struct Eular_Tour {
    int t;
    vector<int> ls, rs, ds, us;
    graph g;
    Eular_Tour(int n) : ls(n), rs(n), ds(n), us(n), g(n), t(0) {}
    void dfs_subtree(int v = 0, int p = -1) {
        ls[v] = t++;
        for (int u : g[v]) {
            if (u != p) dfs_subtree(u, v);
        }
        rs[v] = t;
    }
    void dfs_path(int v = 0, int p = -1) {
        ds[v] = t++;
        for (int u : g[v]) {
            if (u == p) continue;
            dfs_path(u, v);
        }
        us[v] = t++;
    }
};