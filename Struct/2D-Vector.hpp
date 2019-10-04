#ifndef def
#include "Shuzaei.hpp"
#endif

struct position {
    ll x, y;
    position() {}
    position(ll a, ll b) : x(a), y(b) {}
    position next(ll i) { return {x + dx[i], y + dy[i]}; }
    ll mdist() { return abs(x) + abs(y); }
    double dist() { return sqrt(x * x + y * y); }
    double norm(ll d) {
        if (d == inf) return max(x, y);
        if (d == 1) return mdist();
        if (d == 2) return dist();
        return 0;
    }
    ll num(ll width) { return abs(x) * width + abs(y); }

    bool operator==(position a) { return x == a.x && y == a.y; }
    bool operator!=(position a) { return x != a.x || y != a.y; }
    bool operator<(position a) { return x < a.x && y < a.y; }
    bool operator>(position a) { return x > a.x && y > a.y; }
    bool operator<=(position a) { return x <= a.x && y <= a.y; }
    bool operator>=(position a) { return x >= a.x && y >= a.y; }
    position operator+(position a) { return position(x + a.x, y + a.y); }
    position operator-(position a) { return position(x - a.x, y - a.y); }
    position operator*(position a) { return position(x * a.x, y * a.y); }
    position operator/(position a) { return position(x / a.x, y / a.y); }
    position operator%(position a) { return position(x % a.x, y % a.y); }
    position complex(position a) {
        return position(x * a.x - y * a.y, x * a.y + y * a.x);
    }
    /*
        // for sort:
        bool operator<(position a) { return x ^ a.x ? x < a.x : y < a.y; }
        bool operator>(position a) { return x ^ a.x ? x > a.x : y > a.y; }
        bool operator<=(position a) { return x ^ a.x ? x < a.x : y <= a.y; }
        bool operator>=(position a) { return x ^ a.x ? x > a.x : y >= a.y; }
    */
};
position Origin = position(0, 0);
using pos = position;
using vec = position;
