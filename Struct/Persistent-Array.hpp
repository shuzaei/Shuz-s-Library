#include "Shuzaei.hpp"

template <class T> struct Array {
    struct node {
        ll childl, childr;
        T data;
        node(ll l, ll r, T t) : childl(l), childr(r), data(t) {}
    };
    ll n, depth;
    vector<ll> versions;
    vector<ll> prev_versions;
    vector<node> nodes;
    Array(ll n = 1 << 20, T val = T()) : n(n), depth(0) {
        while (n /= 2) depth++;
        init(val);
    }
    void init(T val) {
        versions.push_back(0);
        prev_versions.push_back(0);
        rep(i, 2 * n - 1) {
            if (i < n - 1) {
                nodes.push_back(node(2 * i + 1, 2 * i + 2, T()));
            } else {
                nodes.push_back(node(0, 0, val));
            }
        }
    }
    void set(ll index, ll val, ll version = -1) {
        ll id, par = nodes.size(), left = 0, right = n;
        if (version == -1) {
            id = versions.back();
            version = versions.size() - 1;
        } else {
            id = versions[version];
        }
        versions.push_back(par);
        prev_versions.push_back(version);
        if (right == -1) right = n;
        rep(i, depth) {
            ll mid = (left + right) / 2;
            if (index < mid) {
                nodes.push_back(node(par + i + 1, nodes[id].childr, T()));
                id = nodes[id].childl;
                right = mid;
            } else {
                nodes.push_back(node(nodes[id].childl, par + i + 1, T()));
                id = nodes[id].childr;
                left = mid;
            }
        }
        nodes.push_back(node(0, 0, val));
    }
    T get(ll index, ll version = -1) {
        ll id, left = 0, right = n;
        if (version == -1) {
            id = versions.back();
        } else {
            id = versions[version];
        }
        rep(i, depth) {
            ll mid = (left + right) / 2;
            if (index < mid) {
                id = nodes[id].childl;
                right = mid;
            } else {
                id = nodes[id].childr;
                left = mid;
            }
        }
        return nodes[id].data;
    }
};
