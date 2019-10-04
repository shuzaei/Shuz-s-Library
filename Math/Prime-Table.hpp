#ifndef def
#include "Shuzaei.hpp"
#endif

vector<ll> prime(ll n) {
    vector<ll> Prime(n + 1);
    rep(i, n + 1) Prime[i] = 1;
    Prime[0] = Prime[1] = 0;
    rep(i, n + 1) {
        if (Prime[i]) {
            rep(j, (n + 1) / i - 1) Prime[i * (j + 2)] = 0;
        }
    }
    return Prime;
}
