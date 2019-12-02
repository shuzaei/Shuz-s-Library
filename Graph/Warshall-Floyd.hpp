#include "Shuzaei.hpp"

class WarshallFloyd {
    private:
    const int n;
    vector<vector<ll>> d;

    public:
    WarshallFloyd(int _n) : n(_n), d(_n, vector<ll>(_n)) {
        rep(i, n) rep(j, n) { d[i][j] = (i == j ? 0 : INF); }
    }
    // directed
    void setDist(int i, int j, int c) { d[i][j] = c; }
    int getDist(int i, int j) { return d[i][j]; }
    void calc() {
        rep(k, n) rep(i, n) rep(j, n) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
};
