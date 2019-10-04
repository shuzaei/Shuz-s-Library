#ifndef def
#include "Shuzaei.hpp"
#endif

struct Range {
    ll left, right;
    Range() {}
    Range(ll l, ll r) : left(l), right(r) {}
    ll length() { return right - left; }
    bool operator==(Range A) { return left == A.left && right == A.right; }
    bool operator!=(Range A) { return !(Range(left, right) == A); }
    bool operator>(Range A) { return left < A.left && right > A.right; }
    bool operator<(Range A) { return left > A.left && right < A.right; }
    bool operator>=(Range A) { return left <= A.left && right >= A.right; }
    bool operator<=(Range A) { return left >= A.left && right <= A.right; }
};
