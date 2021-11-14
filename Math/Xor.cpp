struct Xor {
    vector<long long> base;

    long long operator+=(long long x) {
        for (long long e : base) x = min(x, x ^ e);
        base.push_back(x);
        return x;
    }
    long long operator^(long long x) {
        for (long long e : base) x = min(x, x ^ e);
        return x;
    }
    vector<long long> convert(long long x) {
        vector<long long> res;
        for (long long e : base) {
            if (x ^ e < x) {
                x = x ^ e;
                res.push_back(e);
            } else {
                res.push_back(0);
            }
        }
    }
};
