#ifndef def
#include "Shuzaei.hpp"
#endif

struct Miller {
    const vector<long long> v = {2, 7, 61}; // < 4,759,123,141
    // x^k (mod m)
    long long modpow(long long x, long long k, long long m) {
        long long res = 1;
        while (k) {
            if (k & 1) {
                res = res * x % m;
            }
            k /= 2;
            x = x * x % m;
        }
        return res;
    }
    // check if n is prime
    bool check(long long n) {
        if (n < 2) {
            return false;
        }
        long long d = n - 1;
        long long s = 0;
        while (d % 2 == 0) {
            d /= 2;
            s++;
        }
        for (long long a : v) {
            if (a == n) {
                return true;
            }
            if (modpow(a, d, n) != 1) {
                bool ok = true;
                for (long long r = 0; r < s; r++) {
                    if (modpow(a, d * (1LL << r), n) == n - 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    return false;
                }
            }
        }
        return true;
    }
};

struct Rho {
    mt19937 mt;
    Miller miller;
    long long c;
    Rho() { mt.seed(clock()); }
    inline long long f(long long x, long long n) { return (x * x + c) % n; }
    long long check(long long n) {
        if (n == 4) {
            return 2;
        }
        c = mt() % n;
        long long x = mt() % n;
        long long y = x;
        long long d = 1;
        while (d == 1) {
            x = f(x, n);
            y = f(f(y, n), n);
            d = __gcd(abs(x - y), n);
        }
        if (d == n) {
            return -1;
        }
        return d;
    }
    vector<long long> factor(long long n) {
        if (n <= 1) {
            return {};
        }
        if (miller.check(n)) {
            return {n};
        }
        long long res = -1;
        while (res == -1) {
            res = check(n);
        }
        vector<long long> fa = factor(res);
        vector<long long> fb = factor(n / res);
        fa.insert(fa.end(), fb.begin(), fb.end());
        return fa;
    }
};
