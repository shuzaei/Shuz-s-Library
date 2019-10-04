#ifndef def
#include "Shuzaei.hpp"
#endif

struct edge {
    ll to;
    edge(ll a) : to(a) {}
};

struct wedge {
    ll to, cost;
    edge(ll a, ll b) : to(a), cost(b) {}
};