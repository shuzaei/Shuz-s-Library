struct LCA {
    int n, d = 0, inf = 1000000000;
    vector<int> dist;
    vector<vector<int>> root, graph;
    LCA(int n) : n(n), dist(n, inf), graph(n) {
        int k = n;
        while (k /= 2) d++;
        root = vector<vector<int>>(d, vector<int>(n, -1));
    }
    void add_edge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    void calc() {
        dist[0] = root[0][0] = 0, dfs(0);
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
            if ((1 << i) & diff) a = root[i][a];
        }
        for (int i = d - 1; i >= 0; i--) {
            if (root[i][a] != root[i][b]) { a = root[i][a], b = root[i][b]; }
        }
        if (a != b) a = root[0][a], b = root[0][b];
        return a;
    }
    int distance(int a, int b) {
        int par = lca(a, b);
        return dist[a] + dist[b] - 2 * dist[par];
    }
};
