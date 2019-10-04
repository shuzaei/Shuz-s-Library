#ifndef def
#include "Shuzaei.hpp"
#endif

template <class T> struct slidemin {
#define __SIGSEGV__ "Segmentation fault: 11"
    ll N, l, r;
    vector<ll> data;
    deque<ll> deq;
    slidemin(ll n, ll start) : N(n), data(n), l(start), r(start) {}
    void setdata(ll itr, ll val) { data[itr] = val; }
    void pop_front() {
        while (deq.size() && deq.front() <= l) {
            deq.pop_front();
        }
        l++;
        if (l >= N) cerr << __SIGSEGV__ << endl;
    }
    void push_back() {
        while (deq.size() && data[deq.back()] > data[r]) {
            deq.pop_back();
        }
        deq.push_back(r);
        if (r > N) cerr << __SIGSEGV__ << endl;
        r++;
    }
    ll min() { return data[deq.front()]; }
};