#include "Shuzaei.hpp"

struct SCC {
    vector<vector<ll>> graph;
    vector<vector<ll>> rgraph;
    vector<vector<ll>> new_graph;
    vector<ll> used;
    vector<ll> in_count;
    vector<ll> new_in_count;
    vector<ll> tp_index;
    vector<ll> nodes;
    ll num, new_num;
    SCC(ll n)
        : num(n), graph(n), rgraph(n), in_count(n), tp_index(n), used(n) {}
    void add_edge(ll from, ll to) {
        graph[from].push_back(to);
        rgraph[to].push_back(from);
        in_count[to]++;
    }
    void new_add_edge(ll from, ll to) {
        ll f = tp_index[from], t = tp_index[to];
        if (f == t) return;
        new_graph[f].push_back(t);
        new_in_count[t]++;
    }
    void dfs(ll pos) {
        used[pos] = true;
        each(i, graph[pos]) if (!used[i]) dfs(i);
        nodes.push_back(pos);
    }
    void rdfs(ll pos, ll k) {
        used[pos] = true;
        tp_index[pos] = k;
        each(i, rgraph[pos]) if (!used[i]) rdfs(i, k);
    }
    ll scc() {
        fill(all(used), false);
        nodes.clear();
        rep(i, num) if (!used[i]) dfs(i);
        reverse(all(nodes));
        fill(all(used), false);
        ll k = 0;
        each(i, nodes) if (!used[i]) rdfs(i, k++);
        new_graph.resize(k), new_in_count.resize(k);
        build_new_graph();
        return new_num = k;
    }
    void build_new_graph() { rep(i, num) each(j, graph[i]) new_add_edge(i, j); }
};
