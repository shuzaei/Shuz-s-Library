#include "Shuzaei.hpp"

namespace Kika {
using Double = long double;
const Double EPS = 1e-20l;
const Double M_PIL = 3.1415926535897932384626433832795028841971693993751l;
bool equals(Double a, Double b) { return fabsl(a - b) < EPS; }
struct Point {
    Double x, y;
    Point(Double x = 0, Double y = 0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(Double a) { return Point(a * x, a * y); }
    Point operator/(Double a) { return Point(x / a, y / a); }
    Point operator+=(Point p) {
        x += p.x, y += p.y;
        return *this;
    }
    Point operator-=(Point p) {
        x -= p.x, y -= p.y;
        return *this;
    }
    Point operator*=(Double a) {
        x *= a, y *= a;
        return *this;
    }
    Point operator/=(Double a) {
        x /= a, y /= a;
        return *this;
    }
    bool operator<(const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator==(const Point &p) const {
        return fabsl(x - p.x) < EPS and fabsl(y - p.y) < EPS;
    }
    Double abs() { return sqrtl(norm()); }
    Double norm() { return x * x + y * y; }
};
using Vector = Point;
struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};
using Line = Segment;
struct Circle {
    Point c;
    Double r;
    Circle(Point c = Point(), Double r = 0.0l) : c(c), r(r) {}
};
using Polygon = vector<Point>;

enum ccw_status {
    COUNTER_CLOCKWISE = 1,
    CLOCKWISE = -1,
    ONLINE_BACK = 2,
    ONLINE_FRONT = -2,
    ON_SEGMENT = 0
};

enum contains_status { IN = 2, ON = 1, OUT = 0 };

Point operator*(Double a, Point p) { return Point(a * p.x, a * p.y); }
Point operator/(Double a, Point p) { return Point(p.x / a, p.y / a); }
Double norm(Vector a) { return a.x * a.x + a.y * a.y; }
Double abs(Vector a) { return sqrtl(norm(a)); }
Double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
Double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
Double sin(Vector a, Vector b) { return cross(a, b) / a.norm() / b.norm(); }
Double cos(Vector a, Vector b) { return dot(a, b) / a.norm() / b.norm(); }
Double arg(Vector p) { return atan2l(p.y, p.x); }
Double angle(Vector a, Vector b) {
    Double theta = arg(b) - arg(a);
    while (theta < -M_PIL + EPS) theta += 2.0l * M_PIL;
    while (theta > M_PIL + EPS) theta -= 2.0l * M_PIL;
    return theta;
}
Vector polar(Double a, Double r) { return Point(a * cosl(r), a * sinl(r)); }
bool isOrthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0l); }
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
    return isOrthogonal(a2 - a1, b2 - b1);
}
bool isOrthogonal(Segment s1, Segment s2) {
    return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0l);
}
bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0l); }
bool isParallel(Point a1, Point a2, Point b1, Point b2) {
    return isParallel(a2 - a1, b2 - b1);
}
bool isParallel(Segment s1, Segment s2) {
    return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0l);
}
ccw_status ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS) return ONLINE_BACK;
    if (a.norm() > b.norm()) return ONLINE_FRONT;
    return ON_SEGMENT;
}
bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 and
           ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}
bool intersect(Segment s1, Segment s2) {
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    Double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}
Point reflect(Segment s, Point p) { return p + 2.0l * (project(s, p) - p); }
Double distance(Point a, Point b) { return abs(b - a); }
Double distanceLP(Line l, Point p) {
    return cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1);
}
Double distanceSP(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0l) return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0l) return abs(p - s.p2);
    return distanceLP(s, p);
}
Double distance(Segment s1, Segment s2) {
    if (intersect(s1, s2)) return 0.0l;
    return min(min(distanceSP(s1, s2.p1), distanceSP(s1, s2.p2)),
               min(distanceSP(s2, s1.p1), distanceSP(s2, s1.p2)));
}
Point crossPoint(Segment s1, Segment s2) {
    Vector base = s2.p2 - s1.p1;
    Double d1 = abs(cross(base, s1.p1 - s2.p1));
    Double d2 = abs(cross(base, s1.p2 - s2.p1));
    Double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}
bool intersect(Circle c, Line l) { return distanceLP(l, c.c) <= c.r; }
bool intersect(Circle c1, Circle c2) {
    return distance(c1.c, c2.c) <= c1.r + c2.r;
}
pair<Point, Point> crossPoints(Circle c, Line l) {
    assert(intersect(c, l));
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    Double base = sqrtl(c.r * c.r - norm(pr - c.c));
    return make_pair(pr + e * base, pr - e * base);
}
pair<Point, Point> crossPoints(Circle c1, Circle c2) {
    assert(intersect(c1, c2));
    Double d = abs(c2.c - c1.c);
    Double a = acosl((c1.r * c1.r + d * d - c2.r * c2.r) / (2.0l * c1.r * d));
    Double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}
contains_status contains(Polygon g, Point p) {
    ll n = g.size();
    bool x = false;
    rep(i, n) {
        Point a = g[i] - p, b = g[(i + 1) % n] - p;
        if (abs(cross(a, b)) < EPS and dot(a, b) < EPS) return ON;
        if (a.y > b.y) swap(a, b);
        if (a.y < EPS and EPS < b.y and cross(a, b) > EPS) x = !x;
    }
    return x ? OUT : IN;
}
Polygon convexHull(Polygon s) {
    Polygon u, l;
    if (s.size() <= 3) return s;
    all(sort, s);
    u.push_back(s[0]), u.push_back(s[1]);
    l.push_back(s[s.size() - 1]), l.push_back(s[s.size() - 2]);
    inc(i, 2, s.size() - 1) {
        while (u.size() >= 2 and
               ccw(u[s.size() - 2], u[s.size() - 1], s[i]) == CLOCKWISE) {
            u.pop_back();
        }
        u.push_back(s[i]);
    }
    dec(i, s.size() - 3, 0) {
        while (l.size() >= 2 and
               ccw(l[s.size() - 2], l[s.size() - 1], s[i]) == CLOCKWISE) {
            l.pop_back();
        }
        l.push_back(s[i]);
    }
    all(reverse, l);
    move(l.begin(), l.end(), back_inserter(u));
    return u;
}

istream &operator>>(istream &is, Point &p) {
    is >> p.x >> p.y;
    return is;
}
ostream &operator<<(ostream &os, const Point &p) {
    os << '(' << p.x << ", " << p.y << ")";
    return os;
}
} // namespace Kika