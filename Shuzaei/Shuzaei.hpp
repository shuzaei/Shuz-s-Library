#include <bits/stdc++.h>
using namespace std;

// Define
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll inf = 1 << 30;
const ll LINF = LONG_MAX;
const ll INF = 1LL << 60;
const ull MAX = ULONG_MAX;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplase_back
#define elif else if
#define endl '\n'
#define space ' '
#define def inline auto
#define func inline constexpr ll
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define whole(a, v, ...)                                                       \
    ([&](decltype((v)) w) { return (a)(begin(w), end(w), ##__VA_ARGS__); })(v)
#define rwhole(a, v, ...)                                                      \
    ([&](decltype((v)) w) { return (a)(rbegin(w), rend(w), ##__VA_ARGS__); })(v)
#define input(a) scanf("%lld", &(a))
#define print(a) printf("%lld\n", (a))
#define fi first
#define se second
#define ok(a, b) (0 <= (a) && (a) < (b))
template <class T> using vvector = vector<vector<T>>;
template <class T> using pvector = vector<pair<T, T>>;
template <class T>
using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;

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
        cerr << endl;                                                          \
    }

#define dump(a, h, w)                                                          \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [" << endl;                      \
        rep(__i, h) {                                                          \
            rep(__j, w) cerr << a[__i][__j] << space;                          \
            cerr << endl;                                                      \
        }                                                                      \
        cerr << "]" << endl;                                                   \
    }

#define vdump(a, n)                                                            \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [";                              \
        rep(__i, n) if (__i) cerr << space << a[__i];                          \
        else cerr << a[__i];                                                   \
        cerr << "]" << endl;                                                   \
    }

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i <= _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i >= _##i; --i)
#define rep(i, n) for (ll i = 0, _##i = (n); i < _##i; ++i)
#define each(i, a) for (auto &&i : a)
#define loop() for (;;)

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
func gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
func lcm(ll a, ll b) { return a * b / gcd(a, b); }
func sign(ll a) { return a ? abs(a) / a : 0; }
