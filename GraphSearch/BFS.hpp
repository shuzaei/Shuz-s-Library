#include "Shuzaei.hpp"

struct bfs {
    typedef pair<ll, ll> P;
#define x first
#define y second
#define MAX_N 1000
#define MAX_M 1000
    string maze[MAX_N];
    P start, goal;
    ll N, M;
    ll D[MAX_N][MAX_M], FROM_X[MAX_N][MAX_M], FROM_Y[MAX_N][MAX_M];
    ll BFS() {
        queue<P> Q;
        rep(i, N) rep(j, M) D[i][j] = INF;
        Q.push(start);
        D[start.x][start.y] = 0;
        while (!Q.empty()) {
            P now = Q.front();
            Q.pop();
            if (now.x == goal.x && now.y == goal.y) break;
            rep(i, 4) {
                P next = make_pair(now.x + dx[i], now.y + dy[i]);
                if (0 <= next.x && next.x < N && 0 <= next.y && next.y < M)
                    if (maze[next.x][next.y] != '#' &&
                        D[next.x][next.y] == INF) {
                        Q.push(next);
                        D[next.x][next.y] = D[now.x][now.y] + 1;
                        FROM_X[next.x][next.y] = now.x;
                        FROM_Y[next.x][next.y] = now.y;
                    }
            }
        }
        return D[goal.x][goal.y];
    }
};
