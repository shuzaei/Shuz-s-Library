struct Yurisu {
    ll a, b;
    Yurisu(ll x = 0, ll y = 1) : a(x), b(y) {
        ll g = gcd(a, b);
        a /= g, b /= g;
    }
    Yurisu operator-() const { return Yurisu(-a, b); }
    Yurisu &operator+=(const Yurisu &c) { return *this = Yurisu(a * c.b + b * c.a, b * c.b); }
    Yurisu &operator-=(const Yurisu &c) { return *this = Yurisu(a * c.b - b * c.a, b * c.b); }
    Yurisu &operator*=(const Yurisu &c) { return *this = Yurisu(a * c.a, b * c.b); }
    Yurisu operator+(const Yurisu &c) const { return Yurisu(*this) += c; }
    Yurisu operator-(const Yurisu &c) const { return Yurisu(*this) -= c; }
    Yurisu operator*(const Yurisu &c) const { return Yurisu(*this) *= c; }
    bool operator==(const Yurisu &c) const { return a == c.a and b == c.b; }
    bool operator!=(const Yurisu &c) const { return a != c.a or b != c.b; }
    bool operator<=(const Yurisu &c) { return a * c.b <= b * c.a; }
    bool operator<(const Yurisu &c) { return a * c.b < b * c.a; }

    Yurisu inv() const { return Yurisu(b, a); }
    Yurisu &operator/=(Yurisu c) { return (*this) *= c.inv(); }
    Yurisu operator/(Yurisu c) const { return Yurisu(*this) /= c; }
};