#include "Shuzaei.hpp"

struct UFW {
    vector<ll> par, dist;
    UFW(ll N) : par(N, -1), dist(N) {}
    ll root(ll x) {
        if (par[x] < 0) {
            return x;
        } else {
            ll rx = root(par[x]);
            dist[x] += dist[par[x]];
            return par[x] = rx;
        }
    }
    bool unite(ll x, ll y, ll w) {
        ll rx = root(x), ry = root(y);
        if (rx != ry) {
            if (par[rx] > par[ry]) swap(rx, ry);
            par[rx] += par[ry];
            par[ry] = rx;
            dist[ry] = w + dist[x] - dist[y];
            return true;
        }
        return false;
    }
    ll weight(ll x) {
        root(x);
        return dist[x];
    }
    ll diff(ll x, ll y) { return weight(y) - weight(x); }
    bool same(ll x, ll y) { return root(x) == root(y); }
    ll size(ll x) { return -par[root(x)]; }
    ll size() {
        ll cnt = 0;
        rep(i, data.size()) if (i == root(i)) cnt++;
        return cnt;
    }
};

struct UFS {
    vector<ll> data;
    UFS(ll N) : data(N, -1) {}
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
    bool isroot(ll x) { return x == root(x); }
    ll size(ll x) { return -data[root(x)]; }
    ll size() {
        ll cnt = 0;
        rep(i, data.size()) if (isroot(i)) cnt++;
        return cnt;
    }
};

struct UFR {
    vector<ll> data;
    UFR(ll N) : data(N, -1) {}
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
