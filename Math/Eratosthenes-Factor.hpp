#ifndef def
#include "Shuzaei.hpp"
#endif

struct fact {
    ll N, A[100000], B[100000], C[100000];
    void factorization() {
        A[0] = 1;
        rep(i, N) {
            if (A[i] == 0) {
                for (ll k = 2 * (i + 1); k < N; k += i + 1) {
                    A[k] = 1;
                    B[k] = i;
                }
            }
        }
        rep(i, N) {
            if (i && A[i] == 1) C[i] = (i + 1) / B[i] + 1;
        }
    }
};
