#include "Shuzaei.hpp"

struct LinearCHT {
    using F = pair<ll, ll>;
    deque<F> deq;
#define a first
#define b second
#define lines deq.size()
    bool invalid_f1(F f0, F f1, F f2) {
        return (f1.a - f0.a) * (f2.b - f1.b) >= (f1.b - f0.b) * (f2.a - f1.a);
    }
    ll f(F f0, ll x) { return f0.a * x + f0.b; }
    void add(F f0) {
        while (lines >= 2 && invalid_f1(deq[lines - 2], deq[lines - 1], f0)) {
            deq.pop_back();
        }
        deq.push_back(f0);
    }
    ll min(ll x) {
        while (lines >= 2 && f(deq[0], x) >= f(deq[1], x)) {
            deq.pop_front();
        }
        return f(deq[0], x);
    }
#undef a
#undef b
#undef lines
};
