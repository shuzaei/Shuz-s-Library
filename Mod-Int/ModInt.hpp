#include "Shuzaei.hpp"

template <ull mod = MOD> struct mi {
    inline constexpr ll modulo(const ll n, const ll m) const noexcept {
        ll k = n % m;
        return k + m * (k < 0);
    }

    ll num;
    inline constexpr mi() noexcept : num() { num = 0; }
    inline constexpr mi(const int n) noexcept : num() { num = modulo(n, mod); }
    inline constexpr mi(const ll n) noexcept : num() { num = modulo(n, mod); }

    inline constexpr mi<mod> inv() const noexcept {
        ll a = num, b = mod, x = 1, y = 0;
        while (b) {
            ll t = a / b;
            a -= t * b;
            swap(a, b);
            x -= t * y;
            swap(x, y);
        }
        return mi<mod>(x);
    }
    inline constexpr mi<mod> inv(ll n) const noexcept {
        ll a = n, b = mod, x = 1, y = 0;
        while (b) {
            ll t = a / b;
            a -= t * b;
            swap(a, b);
            x -= t * y;
            swap(x, y);
        }
        return mi<mod>(x);
    }
    inline constexpr mi<mod> inv(const mi<mod> m) const noexcept {
        return inv(m.num);
    }

    inline constexpr mi<mod> operator+() const noexcept { return mi(num); }
    inline constexpr mi<mod> operator+(const int n) const noexcept {
        return mi<mod>(num + n);
    }
    inline constexpr mi<mod> operator+(const ll n) const noexcept {
        return mi<mod>(num + n);
    }
    inline constexpr mi<mod> operator+(const mi<mod> m) const noexcept {
        return mi<mod>(num + m.num);
    }
    inline constexpr mi<mod> operator-() const noexcept { return -num; }
    inline constexpr mi<mod> operator-(const int n) const noexcept {
        return mi<mod>(num - n);
    }
    inline constexpr mi<mod> operator-(const ll n) const noexcept {
        return mi<mod>(num - n);
    }
    inline constexpr mi<mod> operator-(const mi<mod> m) const noexcept {
        return mi<mod>(num - m.num);
    }
    inline constexpr mi<mod> operator*(const int n) const noexcept {
        return mi<mod>(num * n);
    }
    inline constexpr mi<mod> operator*(const ll n) const noexcept {
        return mi<mod>(num * n);
    }
    inline constexpr mi<mod> operator*(const mi<mod> m) const noexcept {
        return mi<mod>(num * m);
    }
    inline constexpr mi<mod> operator/(const int n) const noexcept {
        return mi<mod>(num * (ll) inv(n));
    }
    inline constexpr mi<mod> operator/(const ll n) const noexcept {
        return mi<mod>(num * (ll) inv(n));
    }
    inline constexpr mi<mod> operator/(const mi<mod> m) const noexcept {
        return mi<mod>(num * (ll) inv(m));
    }
    inline constexpr mi<mod> &operator=(const int n) noexcept {
        num = modulo(n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator=(const ll n) noexcept {
        num = modulo(n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator=(const mi<mod> m) noexcept {
        num = m.num;
        return *this;
    }
    inline constexpr mi<mod> &operator+=(const int n) noexcept {
        num = modulo(num + n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator+=(const ll n) noexcept {
        num = modulo(num + n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator+=(const mi<mod> m) noexcept {
        num = modulo(num + m.num, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator++() noexcept {
        num = modulo(num + 1, mod);
        return *this;
    }
    inline constexpr mi<mod> operator++(int) noexcept {
        mi &pre = *this;
        num = modulo(num + 1, mod);
        return pre;
    }
    inline constexpr mi<mod> &operator-=(const int n) noexcept {
        num = modulo(num - n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator-=(const ll n) noexcept {
        num = modulo(num - n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator-=(const mi<mod> m) noexcept {
        num = modulo(num - m.num, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator--() noexcept {
        num = modulo(num - 1, mod);
        return *this;
    }
    inline constexpr mi<mod> operator--(int) noexcept {
        mi &pre = *this;
        num = modulo(num - 1, mod);
        return pre;
    }
    inline constexpr mi<mod> &operator*=(const int n) noexcept {
        num = modulo(num * n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator*=(const ll n) noexcept {
        num = modulo(num * n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator*=(const mi<mod> m) noexcept {
        num = modulo(num * m.num, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator/=(const int n) noexcept {
        num = modulo(num * (ll) inv(n), mod);
        return *this;
    }
    inline constexpr mi<mod> &operator/=(const ll n) noexcept {
        num = modulo(num * (ll) inv(n), mod);
        return *this;
    }
    inline constexpr mi<mod> &operator/=(const mi<mod> m) noexcept {
        num = modulo(num * (ll) inv(m), mod);
        return *this;
    }
    inline constexpr mi<mod> operator==(const int n) const noexcept {
        return num == modulo(n, mod);
    }
    inline constexpr mi<mod> operator==(const ll n) const noexcept {
        return num == modulo(n, mod);
    }
    inline constexpr mi<mod> operator==(const mi<mod> m) const noexcept {
        return num == m.num;
    }
    inline constexpr mi<mod> operator!=(const int n) const noexcept {
        return num != modulo(n, mod);
    }
    inline constexpr mi<mod> operator!=(const ll n) const noexcept {
        return num != modulo(n, mod);
    }
    inline constexpr mi<mod> operator!=(const mi<mod> m) const noexcept {
        return num != m.num;
    }
    constexpr operator int() const noexcept { return num; }
    constexpr operator ll() const noexcept { return num; }
    friend std::istream &operator>>(std::istream &, const mi<> &);
    friend std::ostream &operator<<(std::ostream &, const mi<> &);
};

template <ull mod = MOD>
inline constexpr mi<mod> operator+(const int n, const mi<mod> m) noexcept {
    return mi<mod>(n + m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator+(const ll n, const mi<mod> m) noexcept {
    return mi<mod>(n + m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator-(const int n, const mi<mod> m) noexcept {
    return mi<mod>(n - m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator-(const ll n, const mi<mod> m) noexcept {
    return mi<mod>(n - m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator*(const int n, const mi<mod> m) noexcept {
    return mi<mod>(n * m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator*(const ll n, const mi<mod> m) noexcept {
    return mi<mod>(n * m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator/(const int n, const mi<mod> m) noexcept {
    return mi<mod>(n * (ll) m.inv());
}
template <ull mod = MOD>
inline constexpr mi<mod> operator/(const ll n, const mi<mod> m) noexcept {
    return mi<mod>(n * (ll) m.inv());
}
inline constexpr mi<MOD> operator""_m(ull n) { return mi<MOD>((ll) n); }

template <ull mod = MOD>
inline constexpr mi<mod> pow(mi<mod> m, ll n) noexcept {
    mi<mod> r = mi<mod>(1);
    rep(i, 64) {
        if (n & (1LL << i)) r *= m;
        m *= m;
    }
    return r;
}
template <ull mod> istream &operator>>(istream &is, mi<mod> &m) {
    is >> m.num;
    return is;
}
template <ull mod> ostream &operator<<(ostream &is, mi<mod> &m) {
    is << (ll) m;
    return is;
}
