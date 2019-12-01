#include "Shuzaei.hpp"

struct edge {
    ll to;
    edge(ll a) : to(a) {}
};

struct wedge {
    ll to, cost;
    edge(ll a, ll b) : to(a), cost(b) {}
};