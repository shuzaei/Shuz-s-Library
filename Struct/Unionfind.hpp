#include "Shuzaei.hpp"

struct UFS {
    vector<ll> data;
    UFS(ll N) : data(N) { rep(i, N) data[i] = -1; }
    ll root(ll x) {
        if (data[x] < 0)
            return x;
        else
            return data[x] = root(data[x]);
    }
    bool unite(ll x, ll y) {
        ll root_x = root(x), root_y = root(y);
        if (root_x != root_y) {
            if (data[root_x] > data[root_y]) swap(root_x, root_y);
            data[root_x] += data[root_y];
            data[root_y] = root_x;
            return true;
        }
        return false;
    }
    bool same(ll x, ll y) { return root(x) == root(y); }
    ll size(ll x) { return -data[root(x)]; }
};

struct UFR {
    vector<ll> data;
    UFR(ll N) : data(N) { rep(i, N) data[i] = -1; }
    ll root(ll x) {
        if (data[x] < 0)
            return x;
        else
            return data[x] = root(data[x]);
    }
    bool unite(ll x, ll y) {
        ll root_x = root(x), root_y = root(y);
        if (root_x != root_y) {
            if (data[root_x] > data[root_y]) swap(root_x, root_y);
            data[root_x] -= data[root_x] == data[root_y];
            data[root_y] = root_x;
            return true;
        }
        return false;
    }
    bool same(ll x, ll y) { return root(x) == root(y); }
};
