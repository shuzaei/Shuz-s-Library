struct DAG {
    ll N;
    vector<list<ll>> graph;
    vector<ll> num, in_count, sorted_nodes;
    DAG(ll n) : N(n), graph(n), num(n, -1), in_count(n) {}
    void setedge(ll from, ll to) { graph[from].push_back(to), in_count[to]++; }
    bool topological_sort() {
        ll pos, nodes = 0;
        vector<list<ll>> g = graph;
        deque<ll> origin;
        rep(i, N) if (!in_count[i]) origin.push_back(i);
        while (origin.size()) {
            pos = origin.front(), origin.pop_front();
            num[pos] = nodes;
            sorted_nodes.push_back(pos);
            auto iter = g[pos].begin();
            rep(i, g[pos].size()) {
                ll to = *iter;
                iter = g[pos].erase(iter);
                in_count[to]--;
                if (in_count[to] == 0) origin.push_back(to);
            }
            nodes++;
        }
        rep(i, N) if (g[i].size()) return false;
        return true;
    }
    ll getnum(ll at) { return num[at]; }
    vector<ll> sorted() { return sorted_nodes; }
    bool tp_unique() {
        ll count = 0;
        rep(i, N) {
            if (num[i] != N - 1) {
                each(j, graph[i]) {
                    if (num[j] == num[i] + 1) count++;
                }
            }
        }
        return count == N - 1;
    }
};
