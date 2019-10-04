#ifndef def
#include "Shuzaei.hpp"
#endif

struct Factor {
    inline vector<ll> factors(ll N) {
        vector<ll> A;
        ll i = 2;
        while (i * i <= N) {
            if (N % i == 0) {
                A.push_back(i);
                N /= i;
            } else {
                i++;
            }
        }
        if (N != 1) A.push_back(N);
        sort(all(A));
        return A;
    }
    inline vector<ll> divisor(ll N) {
        vector<ll> A;
        inc(i, 1, sqrt(N)) {
            if (N % i == 0) {
                A.push_back(i);
                if (i * i != N) A.push_back(N / i);
            }
        }
        sort(all(A));
        return A;
    }
};
