#ifndef def
#include "Shuzaei.hpp"
#endif

struct ChugokuJoyo {

    ll mumll(ll p, ll q, ll m) {
        ull x = 0, pp = p;
        for (; q; q /= 2)
            q & 1 ? x += pp, x >= m ? x -= m : 0 : 0, pp *= 2,
                pp >= m ? pp -= m : 0;
        return (ll) x;
    }

    def extgcd(ll a, ll b, ll &x, ll &y) {
        if (b == 0) {
            x = 1, y = 0;
            return a;
        }
        ll d = extgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }

    ll crt(ll a, ll p, ll b, ll q) {
        a %= p;
        if (a < 0) a += p;
        b %= q;
        if (b < 0) b += q;
        if (a > b) {
            ll t;
            t = a;
            a = b;
            b = t;
            t = p;
            p = q;
            q = t;
        }
        ll x, y, m, d;
        d = extgcd(p, q, x, y); // px + qy = gcd(p, q)
        if ((a - b) % d) return -1;
        m = p / d * q;
        // px + qy = gcd(p, q) mod lcm(p, q)
        if (x < 0) x += m / p;
        if (m < 11LL << 28) return (a + (b - a) / d * p % m * x) % m;
        return (a + (ull) mumll(mumll((b - a) % q / d, p, m), x, m)) % m;
    }
};
