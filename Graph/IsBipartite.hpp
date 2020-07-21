#include "Struct/Unionfind.hpp"

using unionfind = UFS;
ll isBipartite(graph &G) {
    unionfind UF(len(G) * 2);
    rep(i, len(G)) each(j, G[i]) {
        UF.unite(i, len(G) + j);
        UF.unite(j, len(G) + i);
    }
    if (UF.same(0, len(G))) {
        return 0;
    } else {
        ll cnt = 0;
        rep(i, len(G)) if (UF.same(0, i)) cnt++;
        return cnt;
    }
}