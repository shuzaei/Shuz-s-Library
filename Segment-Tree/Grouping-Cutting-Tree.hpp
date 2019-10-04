#ifndef def
#include "Shuzaei.hpp"
#endif

struct BIT {
    vector<ll> data;

    BIT() {}
    BIT(ll N) : data(N + 1) {
        fill(data.begin(), data.end(), 0);
        data[0] = N;
    }

    void add(ll pos, ll val) {
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

struct GCT {
    ll size;
    BIT bit;

    GCT(ll N) : bit(N), size(N) {
        for (ll i = 1; i <= bit.data[0]; i++) {
            bit.data[i] = i & -i;
        }
    }

    ll group_index(ll index) { return bit.sum(index + 1) - 1; }
    ll dist(ll x, ll y) { return abs(group_index(x) - group_index(y)); }

    ll begin(ll group_index) { return bit.lower_bound(group_index + 1); }
    ll end(ll group_index) { return bit.lower_bound(group_index + 2); }
    ll group_size(ll group_index) {
        return end(group_index) - begin(group_index);
    }

    void group(ll index) {
        ll s = -(bit.sum(index + 2) - bit.sum(index + 1));
        bit.add(index + 2, s);
        size += s;
    }
    void cut(ll index) {
        ll s = !(bit.sum(index + 2) - bit.sum(index + 1));
        bit.add(index + 2, s);
        size += s;
    }
};
