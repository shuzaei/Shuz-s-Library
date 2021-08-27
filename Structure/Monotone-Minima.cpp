void monotone_minima(int l, int r, int d, int u, int i) {
    if (u < d) return;
    int row = (d + u) / 2;
    long long min_val = inf;
    int min_idx = -1;
    for (int j = l; j <= r; j++) {
        long long val = dp[i][j] + cost[j][row];
        if (val < min_val) {
            min_val = val;
            min_idx = j;
        }
    }
    dp[i + 1][row] = min_val, from[i + 1][row] = min_idx;
    monotone_minima(l, min_idx, d, row - 1, i);
    monotone_minima(min_idx, r, row + 1, u, i);
}