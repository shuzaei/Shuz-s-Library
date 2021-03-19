struct Graph_2D {
    using P = pair<ll, ll>;
#define x first
#define y second
    ll H, W;
    vector<string> S;
    vector<vector<ll>> dist;
    vector<vector<P>> from;
    Graph_2D(ll H, ll W, vector<string> S) :
        H(H), W(W), S(S), dist(H, vector<ll>(W)), from(H, vector<P>(W)) {}
    void bfs(vector<P> start) {
        queue<P> Q;
        rep(i, H) rep(j, W) dist[i][j] = INF;
        each(i, start) Q.push(i), dist[i.x][i.y] = 0;
        while (!Q.empty()) {
            P now = Q.front();
            Q.pop();
            rep(i, 4) {
                P next = make_pair(now.x + dx[i], now.y + dy[i]);
                if (not(0 <= next.x and next.x < H and 0 <= next.y and next.y < W)) continue;
                if (S[next.x][next.y] != '#' and dist[next.x][next.y] > dist[now.x][now.y] + 1) {
                    Q.push(next);
                    dist[next.x][next.y] = dist[now.x][now.y] + 1;
                    from[next.x][next.y] = now;
                }
            }
        }
    }
};

struct Graph_2D {
    using P = pair<ll, ll>;
#define x first
#define y second
    ll H, W;
    vector<string> S;
    vector<vector<ll>> dist;
    Graph_2D(ll H, ll W) : H(H), W(W), dist(H, vector<ll>(W)) {}
    void bfs(P s) {
        queue<P> Q;
        rep(i, H) rep(j, W) dist[i][j] = INF;
        Q.push(s), dist[s.x][s.y] = 0;
        while (!Q.empty()) {
            P now = Q.front();
            Q.pop();
            rep(i, 4) {
                P next = make_pair(now.x + dx[i], now.y + dy[i]);
                if (not(0 <= next.x and next.x < H and 0 <= next.y and next.y < W)) continue;
                if (S[next.x][next.y] != '#' and dist[next.x][next.y] > dist[now.x][now.y] + 1) {
                    Q.push(next);
                    dist[next.x][next.y] = dist[now.x][now.y] + 1;
                }
            }
        }
    }
};