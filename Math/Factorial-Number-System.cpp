struct factorial_number_system {
    vector<ll> permutation(vector<ll> &n) {
        vector<ll> p;
        BIT bit(n.size());
        for (ll i = 0; i < n.size(); i++) bit.add(i, 1);
        for (auto i : n) {
            p.push_back(bit.lower_bound(i) + 1), bit.add(bit.lower_bound(i), -1);
            rep(i, n.size()) debug(bit.sum(i, i + 1));
        }
        return p;
    }
    vector<ll> numbers(vector<ll> &p) {
        vector<ll> n;
        BIT bit(p.size());
        for (ll i = 0; i < p.size(); i++) bit.add(i, 1);
        for (auto i : p) {
            debug(i);
            n.push_back(bit.sum(i)), bit.add(i - 1, -1);
            rep(i, p.size()) debug(bit.sum(i, i + 1));
        }
        return n;
    }
};
using FNS = factorial_number_system;