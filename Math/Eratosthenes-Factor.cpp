struct fact {
    ll N;
    vector<ll> A, B, C;
    fact(ll n = 1 << 20) : N(n), A(n + 1, 1), B(n + 1), C(n + 1, 1) {
        A[0] = A[1] = C[0] = C[1] = 0;
        inc(i, 2, N) {
            if (A[i] == 1) {
                for (ll k = 2 * i; k <= N; k += i) {
                    A[k] = 0;
                    B[k] = i;
                }
            } else {
                C[i] = C[i / B[i]] + 1;
            }
        }
    }
    bool p(ll n) { return A[n]; }
    ll mf(ll n) { return B[n]; }
    ll sf(ll n) { return C[n]; }
};