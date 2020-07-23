struct SAT {
    ll n;
    SCC scc;
    vector<bool> result;

    SAT(ll n) : n(n), scc(2 * n), result(2 * n) {}
    ll inverse(ll x) { return x >= n ? x - n : x + n; }
    void addliteral(ll a, ll b, bool a_inv = false, bool b_inv = false) {
        if (a_inv) a = inverse(a);
        if (b_inv) b = inverse(b);
        scc.add_edge(inverse(a), b);
        scc.add_edge(inverse(b), a);
    }
    bool calc() {
        scc.scc();
        for (ll i = 0; i < n; i++) {
            if (scc.tp_index[i] > scc.tp_index[n + i]) {
                result[i] = true;
                result[n + i] = false;
            } else if (scc.tp_index[i] == scc.tp_index[n + i]) {
                return false;
            } else {
                result[n + i] = true;
                result[i] = false;
            }
        }
        return true;
    }
    bool val(ll x) { return result[x]; }
};