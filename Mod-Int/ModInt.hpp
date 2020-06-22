#include "Shuzaei.hpp"

const ll mo = 1e9 + 7;
struct mint {
    ll x;
    mint(ll x = 0) : x((x % mo + mo) % mo) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint &a) {
        if ((x += a.x) >= mo) x -= mo;
        return *this;
    }
    mint &operator-=(const mint &a) {
        if ((x += mo - a.x) >= mo) x -= mo;
        return *this;
    }
    mint &operator*=(const mint &a) {
        (x *= a.x) %= mo;
        return *this;
    }
    mint operator+(const mint &a) const { return mint(*this) += a; }
    mint operator-(const mint &a) const { return mint(*this) -= a; }
    mint operator*(const mint &a) const { return mint(*this) *= a; }
    bool operator==(const mint &a) const { return x == a.x; }
    bool operator!=(const mint &a) const { return x != a.x; }
    bool operator<=(mint a, ll x) { return a.x <= x; }
    bool operator<(mint a, ll x) { return a.x < x; }
    friend ll abs(mint a) { return a.x; }

    friend mint pow(const mint &a, ll n) {
        if (!n) return 1;
        mint b = pow(a, n >> 1);
        b *= b;
        if (n & 1) b *= a;
        return b;
    }

    mint inv() const { return pow(*this, mo - 2); }
    mint &operator/=(mint &a) { return (*this) *= a.inv(); }
    mint operator/(mint a) const { return mint(*this) /= a; }

    friend istream &operator>>(istream &is, mint &a) {
        ll t;
        is >> t;
        a = mint(t);
        return is;
    }
    friend ostream &operator<<(ostream &os, mint a) {
        os << a.x;
        return os;
    }
};
mint operator"" M(const ull n) { return mint(n); }