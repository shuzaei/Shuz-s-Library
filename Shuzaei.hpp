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
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define elif else if
#define all(a, v, ...)                                                         \
    ([&](decltype((v)) w) { return (a)(begin(w), end(w), ##__VA_ARGS__); })(v)
#define rall(a, v, ...)                                                        \
    ([&](decltype((v)) w) { return (a)(rbegin(w), rend(w), ##__VA_ARGS__); })(v)
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
            rep(_j, w) cerr << a[_i][_j] << sp;                                \
            cerr << rt;                                                        \
        }                                                                      \
        cerr << "]" << rt;                                                     \
    }

#define vdump(a, n)                                                            \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [";                              \
        rep(_i, n) if (_i) cerr << sp << a[_i];                                \
        else cerr << a[_i];                                                    \
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
