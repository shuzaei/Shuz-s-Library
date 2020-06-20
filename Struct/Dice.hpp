#include "Shuzaei.hpp"

struct dice {
    vector<ll> n;
    dice(vector<ll> n = {1, 3, 2, 4, 5, 6}) : n(n) {}
    ll num() { return n[0]; }
    void rotate_left() { rotate(n.begin() + 1, n.begin() + 2, n.end() - 1); }
    void rotate_right() { rep(i, 3) rotate_left(); }
    void rotate_north() {
        ll mem = n[0];
        n[0] = n[2];
        n[2] = n[5];
        n[5] = n[4];
        n[4] = mem;
    }
    void rotate_east() {
        ll mem = n[0];
        n[0] = n[3];
        n[3] = n[5];
        n[5] = n[1];
        n[1] = mem;
    }
    void rotate_south() { rep(i, 3) rotate_north(); }
    void rotate_west() { rep(i, 3) rotate_east(); }
};