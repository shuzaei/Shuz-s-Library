wstring lcs(wstring a, wstring b) {
    ll n = a.size(), m = b.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    rep(i, n) rep(j, m) {
        if (a[i] == b[j]) {
            dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
            dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    wstring ans;
    ll i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans.push_back(a[i - 1]);
            i--, j--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(all(ans));
    return ans;
}