struct BabyStep_GiantStep {
    map<ll, ll> baby;
    ll K(ll X, ll Y, ll M) {
        ll m = ceill(sqrtl(M)), x = X, invX = inv(X, M), r = 1, giant;
        for (ll i = 0; i < m; i++) {
            if (baby[x] == 0) baby[x] = i + 1;
            x = x * X % M, r = r * invX % M;
        }
        giant = 1;
        for (ll i = 0; i < M / m; i++) {
            if (baby[Y * giant % M]) return i * m + baby[Y * giant % M];
            giant = giant * r % M;
        }
        return -1;
    }
};