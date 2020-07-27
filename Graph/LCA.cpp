struct LCA {
    ll N = 100000;
    ll root[30][100000], dist[100000];
    vector<ll> G[100000];
    LCA() {}
    void addEdge(ll A, ll B) {
        G[A].push_back(B);
        G[B].push_back(A);
    }
    void calc() {
        rep(i, 30) rep(j, N) root[i][j] = -1;
        rep(i, N) dist[i] = INF;
        dist[0] = 0, dfs(0);
        rep(i, 29) rep(j, N) {
            if (root[i][j] == -1) continue;
            root[i + 1][j] = root[i][root[i][j]];
        }
    }
    void dfs(ll t) {
        each(i, G[t]) {
            if (dist[i] != INF) continue;
            root[0][i] = t;
            dist[i] = dist[t] + 1;
            dfs(i);
        }
    }
    ll lca(ll A, ll B) {
        if (dist[A] < dist[B]) swap(A, B);
        ll diff = dist[A] - dist[B];
        rep(i, 30) if ((1 << i) & diff) A = root[i][A];
        dec(i, 29, 0) {
            if (root[i][A] != root[i][B]) {
                A = root[i][A], B = root[i][B];
            }
        }
        if (A != B) A = root[0][A], B = root[0][B];
        return A;
    }
    ll rootDist(ll node, ll root) { return dist[node] - dist[root]; }
};

#include <bits/stdc++.h>
using namespace std;

struct LCA {
    int n, d, inf = 1000000000;
    vector<int> dist;
    vector<vector<int>> root, graph;
    LCA(vector<vector<int>> g) : n(g.size()), dist(n, inf), graph(g) {
        int k = 2 * n;
        while (k) d++, k /= 2;
        root = vector<vector<int>>(d, vector<int>(n, -1));

        dist[0] = 0, dfs(0);
        for (int i = 0; i < d - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (root[i][j] == -1) continue;
                root[i + 1][j] = root[i][root[i][j]];
            }
        }
    }
    void dfs(int t) {
        for (int i : graph[t]) {
            if (dist[i] != inf) continue;
            root[0][i] = t;
            dist[i] = dist[t] + 1;
            dfs(i);
        }
    }
    int lca(int a, int b) {
        if (dist[a] < dist[b]) swap(a, b);
        int diff = dist[a] - dist[b];
        for (int i = 0; i < d; i++) {
            if ((1 << i) & diff) a = root[i][b];
        }
        for (int i = d - 1; i >= 0; i++) {
            if (root[i][a] != root[i][b]) {
                a = root[i][a], b = root[i][b];
            }
        }
        if (a != b) a = root[0][a], b = root[0][b];
        return a;
    }
    int distance(int a, int b) {
        int par = lca(a, b);
        return dist[a] + dist[b] - 2 * dist[par];
    }
};