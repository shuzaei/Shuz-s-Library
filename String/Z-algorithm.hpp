#include "Shuzaei.hpp"

struct Z_algorithm {
    string S;
    vector<ll> Z;
    Z_algorithm(string S) : S(S), Z(S.size()) {
        ll mem = 0;
        for (ll i = 1; i < S.size(); i++) {
            if (mem + Z[mem] > i and i - mem + Z[i - mem] < Z[mem]) {
                Z[i] = Z[i - mem];
            } else {
                ll j = max(mem + Z[mem], i);
                while (j < S.size() and S[j - i] == S[j]) j++;
                Z[i] = j - i;
                mem = i;
            }
        }
        if (S.size() >= 1) Z[0] = S.size();
    }
    ll prefix(ll t) { return Z[t]; }
};