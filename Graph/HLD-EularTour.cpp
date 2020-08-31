struct HLD {
    int t;
    vector<int> sz, par, in, out, nxt;
    graph g;
    HLD(int n) : sz(n), par(n), in(n), out(n), nxt(n), g(n) {}
    void dfs_sz(int v = 0, int p = -1) {
        sz[v] = 1;
        for (auto &u : g[v]) {
            if (u == p) continue;
            par[u] = v;
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
    int lca(int u, int v) {
        while (true {
            if (in[u] > in[v]) swap(u, v);
            if (nxt[u] == nxt[v]) return u;
            v = par[nxt[v]];
        }
        return in[u] > in[v] ? v : u;
    }
    void calc() { dfs_sz(), dfs_hld(); }
    void path_query(int u, int v) {
        while (nxt[u] != nxt[v]) {
            if (in[u] > in[v]) swap(u, v);
            // query for [max(in[nxt[v]], in[u]), in[v]]
            v = par[nxt[v]];
        }
    }
    void subtree_query(int v) {
        // query for [in[v], out[v]]
    }
};

struct Eular_Tour {
    int t;
    vector<int> ls, rs, ds, us;
    graph g;
    Eular_Tour(int n) : ls(n), rs(n), ds(n), us(n), graph(n) {}
    void dfs_subtree(int v = 0, int p = -1) {
        ls[v] = t++;
        for (int u : G[v]) {
            if (u != p) dfs_subtree(u, v);
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