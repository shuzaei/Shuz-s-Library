struct f2 {
    bool num;
    f2(bool n = 0) : num(n) {}
    f2 &operator+=(const f2 &a) {
        (*this).num ^= a.num;
        return (*this);
    }
    f2 &operator-=(const f2 &a) {
        (*this).num ^= a.num;
        return (*this);
    }
    f2 &operator*=(const f2 &a) {
        (*this).num &= a.num;
        return (*this);
    }
    f2 &operator/=(const f2 &a) { return (*this); }
    bool operator==(const f2 &a) { return (*this).num == a.num; }
    bool operator!=(const f2 &a) { return (*this).num != a.num; }
    f2 operator+(const f2 &a) const { return f2(*this) += a; }
    f2 operator-(const f2 &a) const { return f2(*this) -= a; }
    f2 operator*(const f2 &a) const { return f2(*this) *= a; }
    f2 operator/(const f2 &a) const { return f2(*this) /= a; }
    friend ostream &operator<<(ostream &os, f2 &a) {
        os << a.num;
        return (os);
    }
};