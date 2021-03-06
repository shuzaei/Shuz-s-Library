struct BIT {
    vector<ll> data;

    BIT() {}
    BIT(ll n) : data(n + 1) {
        fill(data.begin(), data.end(), 0);
        data[0] = n;
    }

    void add(ll pos, ll val) {
        pos++;
        while (pos <= data[0]) {
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    ll sum(ll pos) {
        if (pos <= 0) return 0;
        ll res = 0;
        while (pos > 0) {
            res += data[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    ll sum(ll l, ll r) { return sum(r) - sum(l); }

    ll lower_bound(ll val) {
        if (val <= 0) return 0;
        ll index = 0;
        for (ll d = 1 << ll(log2(data[0])); d > 0; d /= 2) {
            if (index + d <= data[0] && data[index + d] < val) {
                val -= data[index + d];
                index += d;
            }
        }
        return index;
    }
};
