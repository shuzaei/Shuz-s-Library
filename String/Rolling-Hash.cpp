namespace rollinghash {
using u64 = uint_fast64_t;
using u128 = __uint128_t;
const u64 mo = (1LL << 61) - 1;
const u64 bases[64] = {257, 262, 266, 275, 276, 281, 285, 290, 296, 302, 306,
                       310, 311, 313, 323, 333, 344, 345, 350, 357, 367, 370,
                       373, 402, 423, 425, 431, 440, 442, 443, 454, 457, 458,
                       462, 471, 478, 481, 487, 489, 492, 499, 501, 502, 503,
                       506, 514, 524, 532, 535, 541, 550, 552, 557, 559, 562,
                       563, 567, 570, 571, 580, 592, 597, 604, 612};
random_device rd;
u64 base = bases[rd() & 63];

u64 add(u64 a, u64 b) {
    u64 t = a + b;
    return t >= mo ? t - mo : t;
}
u64 minus(u64 a) { return a == 0 ? 0 : mo - a; }
u64 mul(u64 a, u64 b) {
    u128 t = u128(a) * u128(b);
    t = (t >> 61) + (t & mo);
    return t >= mo ? t - mo : t;
}
template <class T> vector<u64> cast(vector<T> v) {
    return vector<u64>(v.begin(), v.end());
}

struct rhash {
    vector<u64> hash_val, base_pow;
    rhash(vector<u64> v) {
        u64 n = v.size();
        hash_val.assign(n + 1, 0);
        base_pow.assign(n + 1, 0);
        base_pow[0] = 1;
        for (u64 i = 0; i < n; i++) {
            hash_val[i + 1] = add(mul(hash_val[i], base), v[i]);
            base_pow[i + 1] = mul(base_pow[i], base);
        }
    }
    u64 operator()(u64 l, u64 r) {
        return add(hash_val[r], minus(mul(hash_val[l], base_pow[r - l])));
    }
    u64 hash_merge(u64 h1, u64 h2, u64 h2len) {
        return add(mul(h1, base_pow[h2len]), h2);
    }

    void push_back(vector<u64> v) {
        u64 n = hash_val.size() - 1, m = v.size();
        hash_val.resize(n + m + 1);
        base_pow.resize(n + m + 1);
        for (u64 i = n; i < n + m; i++) {
            hash_val[i + 1] = add(mul(hash_val[i], base), v[i - n]);
            base_pow[i + 1] = mul(base_pow[i], base);
        }
    }
};

u64 LCP(rhash &a, rhash &b, u64 l1, u64 r1, u64 l2, u64 r2) {
    u64 len = min(r1 - l1, r2 - l2);
    u64 left = -1, right = len + 1;
    while (right - left > 1) {
        u64 mid = (left + right) / 2;
        if (a(l1, l1 + mid) == b(l2, l2 + mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}
} // namespace rollinghash