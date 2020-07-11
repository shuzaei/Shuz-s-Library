#include <bits/stdc++.h>
using namespace std;

// Define
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <class T> using pvector = vector<pair<T, T>>;
template <class T>
using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;
constexpr const ll dx[4] = {1, 0, -1, 0};
constexpr const ll dy[4] = {0, 1, 0, -1};
constexpr const ll MOD = 1e9 + 7;
constexpr const ll mod = 998244353;
constexpr const ll INF = 1LL << 60;
constexpr const ll inf = 1 << 30;
constexpr const char rt = '\n';
constexpr const char sp = ' ';
#define rt(i, n) (i == n - 1 ? rt : sp)
#define len(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ifn(x) if (not(x))
#define elif else if
#define elifn else ifn
#define fi first
#define se second

template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
// Debug
#define debug(...)                                                             \
    {                                                                          \
        cerr << __LINE__ << ": " << #__VA_ARGS__ << " = ";                     \
        for (auto &&X : {__VA_ARGS__}) cerr << "[" << X << "] ";               \
        cerr << rt;                                                            \
    }

#define dump(a, h, w)                                                          \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [" << rt;                        \
        rep(_i, h) {                                                           \
            rep(_j, w) {                                                       \
                if (abs(a[_i][_j]) >= INF / 2 and a[_i][_j] <= -INF / 2)       \
                    cerr << '-';                                               \
                if (abs(a[_i][_j]) >= INF / 2)                                 \
                    cerr << "∞" << sp;                                         \
                else                                                           \
                    cerr << a[_i][_j] << sp;                                   \
            }                                                                  \
            cerr << rt;                                                        \
        }                                                                      \
        cerr << "]" << rt;                                                     \
    }

#define vdump(a, n)                                                            \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [";                              \
        rep(_i, n) {                                                           \
            if (_i) cerr << sp;                                                \
            if (abs(a[_i]) >= INF / 2 and a[_i] <= -INF / 2) cerr << '-';      \
            if (abs(a[_i]) >= INF / 2)                                         \
                cerr << "∞" << sp;                                             \
            else                                                               \
                cerr << a[_i];                                                 \
        }                                                                      \
        cerr << "]" << rt;                                                     \
    }

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i <= _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i >= _##i; --i)
#define rep(i, n) for (ll i = 0, _##i = (n); i < _##i; ++i)
#define each(i, a) for (auto &&i : a)

// Stream
#define fout(n) cout << fixed << setprecision(n)
struct stream {
    stream() { cin.tie(nullptr), ios::sync_with_stdio(false); }
} stream;

// Speed
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

// Math
//#define gcd __gcd
inline constexpr ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline constexpr ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
