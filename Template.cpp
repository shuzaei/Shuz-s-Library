#include <bits/stdc++.h>
using namespace std;
//#pragma GCC target("arch=skylake-avx512")

#pragma region template

// Define
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <class T> using pvector = vector<pair<T, T>>;
template <class T> using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;
constexpr const ll dx[4] = {1, 0, -1, 0};
constexpr const ll dy[4] = {0, 1, 0, -1};
constexpr const ll MOD = 1e9 + 7;
constexpr const ll mod = 998244353;
constexpr const ll INF = 1LL << 60;
constexpr const ll inf = 1 << 30;
constexpr const char rt = '\n';
constexpr const char sp = ' ';
#define rt(i, n) (i == (ll)(n) -1 ? rt : sp)
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
#define uniq(x) (sort(all(x)), (x).erase(unique(all(x)), (x).end()))
#define bis(x, y) ((ll)(lower_bound(all(x), y) - (x).begin()))

using graph = vector<vector<ll>>;
template <class T> using wgraph = vector<vector<pair << ll, T>>> ;
bool __DIRECTED__ = true;
bool __ZERO_INDEXED__ = false;
istream &operator>>(istream &is, graph &g) {
    ll a, b;
    is >> a >> b;
    if (__ZERO_INDEXED__ == false) a--, b--;
    g[a].pb(b);
    if (__DIRECTED__ == false) g[b].pb(a);
    return is;
}
template <class T> istream &operator>>(istream &is, wgraph<T> &g) {
    ll a, b;
    T c;
    is >> a >> b >> c;
    if (__ZERO_INDEXED__ == false) a--, b--;
    g[a].pb({b, c});
    if (__DIRECTED__ == false) g[b].pb({a, c});
    return is;
}

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
#define debug(...)                                                                                 \
    {                                                                                              \
        cerr << __LINE__ << ": " << #__VA_ARGS__ << " = ";                                         \
        for (auto &&__i : {__VA_ARGS__}) cerr << "[" << __i << "] ";                               \
        cerr << rt;                                                                                \
    }

#define dump(a, h, w)                                                                              \
    {                                                                                              \
        cerr << __LINE__ << ": " << #a << " = [" << rt;                                            \
        rep(__i, h) {                                                                              \
            rep(__j, w) {                                                                          \
                if (abs(a[__i][__j]) >= INF / 2 and a[__i][__j] <= -INF / 2) cerr << '-';          \
                if (abs(a[__i][__j]) >= INF / 2) cerr << "∞" << sp;                                \
                else                                                                               \
                    cerr << a[__i][__j] << sp;                                                     \
            }                                                                                      \
            cerr << rt;                                                                            \
        }                                                                                          \
        cerr << "]" << rt;                                                                         \
    }

#define vdump(a, n)                                                                                \
    {                                                                                              \
        cerr << __LINE__ << ": " << #a << " = [";                                                  \
        rep(__i, n) {                                                                              \
            if (__i) cerr << sp;                                                                   \
            if (abs(a[__i]) >= INF / 2 and a[__i] <= -INF / 2) cerr << '-';                        \
            if (abs(a[__i]) >= INF / 2) cerr << "∞" << sp;                                         \
            else                                                                                   \
                cerr << a[__i];                                                                    \
        }                                                                                          \
        cerr << "]" << rt;                                                                         \
    }

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i <= _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i >= _##i; --i)
#define rep(i, n) for (ll i = 0, _##i = (n); i < _##i; ++i)
#define each(i, a) for (auto &&i : a)

// Stream
#define fout(n) cout << fixed << setprecision(n)
struct io {
    io() { cin.tie(nullptr), ios::sync_with_stdio(false); }
} io;

// Speed
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("Ofast,unroll-loops")

// Math
inline constexpr ll gcd(const ll a, const ll b) { return b ? gcd(b, a % b) : a; }
inline constexpr ll lcm(const ll a, const ll b) { return a / gcd(a, b) * b; }

inline constexpr ll modulo(const ll n, const ll m = MOD) {
    ll k = n % m;
    return k + m * (k < 0);
}
inline constexpr ll chmod(ll &n, const ll m = MOD) {
    n %= m;
    return n += m * (n < 0);
}
inline constexpr ll mpow(ll a, ll n, const ll m = MOD) {
    ll r = 1;
    rep(i, 64) {
        if (n & (1LL << i)) r *= a;
        chmod(r, m);
        a *= a;
        chmod(a, m);
    }
    return r;
}
inline ll inv(const ll n, const ll m = MOD) {
    ll a = n, b = m, x = 1, y = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        x -= t * y;
        swap(x, y);
    }
    return modulo(x, m);
}

#pragma endregion

signed main() {}