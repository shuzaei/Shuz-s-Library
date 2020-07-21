#include "Shuzaei.hpp"

using graph = vector<vector<ll>>;
template <class T> using wgraph = vector<vector<ll, T>>;
istream &operator>>(istream &is, graph &g) {
    ll a, b;
    is >> a >> b;
    g[a - 1].pb(b - 1);
    g[b - 1].pb(a - 1);
    return is;
}

template <class T> istream &operator>>(istream &is, wgraph<T> &g) {
    ll a, b;
    T c;
    is >> a >> b >> c;
    g[a - 1].pb({b - 1, c});
    g[b - 1].pb({a - 1, c});
    return is;
}
