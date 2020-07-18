#include "Shuzaei.hpp"

template <class T> struct slidemin {
    ll top;
    deque<T> data;
    deque<ll> deq;
    slidemin() : top(0) {}
    void pop_front() {
        while (deq.size() and deq.front() <= top) {
            deq.pop_front();
        }
        top++;
        if (top >= data.size()) abort();
    }
    void push_back(T val) {
        data.push_back(val);
        while (deq.size() and data[deq.back()] > data[data.size() - 1]) {
            deq.pop_back();
        }
        deq.push_back(data.size() - 1);
    }
    ll operator() { return data[deq.front()]; }
};