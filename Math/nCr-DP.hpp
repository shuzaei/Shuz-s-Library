#include "Shuzaei.hpp"

struct ncr {
    ll dp[1000][1000];
    ll nCr(ll n, ll r) {
        if (n < 0 or r < 0 or n < r) return 0;
        if (n == r) return dp[n][r] = 1;
        if (r == 0) return dp[n][r] = 1;
        if (r == 1) return dp[n][r] = n;
        if (dp[n][r]) return dp[n][r];
        return dp[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
    }
};
