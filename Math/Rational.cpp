struct Rational {
    using Int = long long;
    using Double = long double;
    Int n, d;
    Rational(Int x = 0, Int y = 1) : n(x), d(y) {
        Int g = gcd(abs(n), abs(d));
        if (d < 0) g *= -1;
        n /= g, d /= g;
    }
    Rational operator-() const { return Rational(-n, d); }
    Rational &operator+=(const Rational &a) { return *this = Rational(n * a.d + d * a.n, d * a.d); }
    Rational &operator-=(const Rational &a) { return *this = Rational(n * a.d - d * a.n, d * a.d); }
    Rational &operator*=(const Rational &a) { return *this = Rational(n * a.n, d * a.d); }
    Rational &operator/=(const Rational &a) { return *this = Rational(n * a.d, d * a.n); }
    Rational operator+(const Rational &a) const { return Rational(*this) += a; }
    Rational operator-(const Rational &a) const { return Rational(*this) -= a; }
    Rational operator*(const Rational &a) const { return Rational(*this) *= a; }
    Rational operator/(const Rational &a) const { return Rational(*this) /= a; }
    bool operator==(const Rational &a) const { return n == a.n and d == a.d; }
    bool operator!=(const Rational &a) const { return n != a.n or d != a.d; }
    bool operator<=(const Rational &a) const { return n * a.d <= d * a.n; }
    bool operator<(const Rational &a) const { return n * a.d < d * a.n; }
    friend Rational abs(const Rational &a) { return Rational(abs(a.n), a.d); }
    friend Int rtoi(const Rational &a) { return a.n / a.d; }
    friend Double rtod(const Rational &a) { return Double(a.n) / Double(a.d); }
    friend istream &operator>>(istream &is, Rational &a) {
        string x;
        is >> x;
        Int y = 1;
        auto iter = find(x.begin(), x.end(), '.');
        if (iter != x.end()) {
            Int dig = x.end() - iter - 1;
            for (Int i = 0; i < dig; i++) y *= 10;
            x.erase(iter);
        }
        a = Rational(stol(x), y);
        return is;
    }
    friend ostream &operator<<(ostream &os, const Rational &a) {
        os << a.n << '/' << a.d;
        return os;
    }
};