struct UFP {
    using P = pair<ll, ll>;
    vector<ll> par, time;
    vector<vector<P>> __size;
    UFP(ll n) : par(n, -1), time(n, INF), __size(n, {{-1, -1}}) {}
    ll root(ll x, ll t) {
        if (time[x] > t) {
            return x;
        } else {
            return root(par[x], t);
        }
    }
    bool unite(ll x, ll y, ll t) {
        ll rx = root(x, t), ry = root(y, t);
        if (rx != ry) {
            if (par[rx] > par[ry]) swap(rx, ry);
            par[rx] += par[ry];
            par[ry] = rx;
            time[ry] = t;
            __size[rx].push_back({t, -par[rx]});
            return true;
        }
        return false;
    }
    bool same(ll x, ll y, ll t) { return root(x, t) == root(y, t); }
    ll size(ll x, ll t, bool rooted = true) {
        if (rooted) x = root(x, t);
        return (--lower_bound(__size[x].begin(), __size[x].end(), P(t, 0)))->second;
    }
};

struct UFA {
    Array<ll> data;
    vector<ll> versions;
    UFA() : data(1 << 18, -1) { versions.push_back(0); }
    ll root(ll x, ll ver) {
        if (data.get(x, versions[ver]) < 0) return x;
        else {
            data.set(x, root(data.get(x, versions[ver]), ver), versions[ver]);
            versions[ver] = data.versions.size() - 1;
            return data.get(x, versions[ver]);
        }
    }
    bool unite(ll x, ll y, ll ver) {
        ll root_x = root(x, ver), root_y = root(y, ver);
        if (root_x != root_y) {
            ll dx = data.get(root_x), dy = data.get(root_y);
            if (dx > dy) swap(root_x, root_y), swap(dx, dy);
            data.set(root_x, dx - (dx == dy));
            data.set(root_y, root_x);
            versions.push_back(data.versions.size() - 1);
            return true;
        } else {
            versions.push_back(data.versions.size() - 1);
            return false;
        }
    }
    bool same(ll x, ll y, ll ver) { return root(x, ver) == root(y, ver); }
};

struct UFW {
    vector<ll> par, dist;
    UFW(ll n) : par(n, -1), dist(n) {}
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
            if (par[rx] > par[ry]) swap(rx, ry), swap(x, y), w = -w;
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
        rep(i, par.size()) if (i == root(i)) cnt++;
        return cnt;
    }
};

struct UFS {
    vector<ll> data;
    UFS(ll n) : data(n, -1) {}
    ll root(ll x) {
        if (data[x] < 0) return x;
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
    UFR(ll n) : data(n, -1) {}
    ll root(ll x) {
        if (data[x] < 0) return x;
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
