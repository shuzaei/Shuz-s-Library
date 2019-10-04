#ifndef def
#include "Shuzaei.hpp"
#endif

struct msort {
    def merge(vector<ll>::iterator left, vector<ll>::iterator mid,
              vector<ll>::iterator right) {
        vector<ll>::iterator iter = left, i1 = left, i2 = mid;
        vector<ll> v;
        while (i1 != mid && i2 != right) {
            if (*i1 < *i2) {
                v.push_back(*i1), i1++;
            } else {
                v.push_back(*i2), i2++;
                // res += mid - i1;
            }
        }
        while (i1 != mid) v.push_back(*i1), i1++;
        while (i2 != right) v.push_back(*i2), i2++;
        while (iter != right) {
            *iter = v[iter - left];
            iter++;
        }
    }

    def mergesort(vector<ll>::iterator left, vector<ll>::iterator right) {
        if (right - left <= 1) return;
        vector<ll>::iterator mid = left + (right - left) / 2;
        mergesort(left, mid);
        mergesort(mid, right);
        merge(left, mid, right);
    }
};
