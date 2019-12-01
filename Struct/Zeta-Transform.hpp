#include "Shuzaei.hpp"

struct Zeta {
    ll N;
    vector<ll> A, S;
    Zeta(vector<ll> v) : A(v), S(1) { each(k, v) S.push_back(k + S.back()); }
    ll sum(ll l, ll r) { return S[r] - S[l]; }
    ll operator()(ll r) { return S[r]; }
};
