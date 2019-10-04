#ifndef def
#include "Shuzaei.hpp"
#endif

struct csum {
    ll N;
    vector<ll> A, S;
    csum(vector<ll> v) : A(v), S(1) { each(k, v) S.push_back(k + S.back()); }
    ll sum(ll l, ll r) { return S[r] - S[l]; }
    ll lsum(ll r) { return S[r]; }
    ll rsum(ll l) { return S.back() - S[l]; }
};
