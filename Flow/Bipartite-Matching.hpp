#ifndef def
#include "Shuzaei.hpp"
#endif

struct BipartiteGraph {
    ll V;
    vector<vector<ll>> G;
    vector<ll> match;
    vector<bool> used;
    BipartiteGraph(ll N) : V(N), G(N), match(N), used(N) {}
    void addEdge(ll i, ll j) {
        G[i].push_back(j);
        G[j].push_back(i);
    }
    bool dfs(ll now) {
        used[now] = true;
        rep(i, G[now].size()) {
            ll next = G[now][i], w = match[next];
            if (w == -1 || (!used[w] && dfs(w))) {
                match[now] = next, match[next] = now;
                return true;
            }
        }
        return false;
    }
    ll matching() {
        ll res = 0;
        fill(all(match), -1);
        rep(i, V) {
            if (match[i] == -1) {
                fill(all(used), false);
                if (dfs(i)) res++;
            }
        }
        return res;
    }
};