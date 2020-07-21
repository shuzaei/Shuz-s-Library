using graph = vector<vector<ll>>;
template <class T> using wgraph = vector<vector<ll, T>>;
bool __DIRECTED__ = 1;

istream &operator>>(istream &is, graph &g) {
    ll a, b;
    is >> a >> b;
    g[a - 1].pb(b - 1);
    if (__DIRECTED__ == false) g[b - 1].pb(a - 1);
    return is;
}

template <class T> istream &operator>>(istream &is, wgraph<T> &g) {
    ll a, b;
    T c;
    is >> a >> b >> c;
    g[a - 1].pb({b - 1, c});
    if (__DIRECTED__ == false) g[b - 1].pb({a - 1, c});
    return is;
}
