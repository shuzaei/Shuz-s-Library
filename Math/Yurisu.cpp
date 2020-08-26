struct Yurisu {
    ll a, b;
    Yurisu(ll x = 0, ll y = 1) : a(x), b(y) {
        ll g = gcd(abs(a), abs(b)) * (b < 0 ? -1 : 1);
        a /= g, b /= g;
        if (b == 0) a = 1;
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

    friend istream &operator>>(istream &is, Yurisu &a) {
        ll x, y;
        is >> x >> y;
        a = Yurisu(x, y);
        return is;
    }
    friend ostream &operator<<(ostream &os, Yurisu a) {
        os << a.a << '/' << a.b;
        return os;
    }
};