namespace sorting {
    using itr = vector<ll>::iterator;
    void merge(itr left, itr mid, itr right) {
        itr iter = left, i1 = left, i2 = mid;
        vector<ll> v;
        while (i1 != mid && i2 != right) {
            if (*i1 < *i2) { // 狭義単調増加の場合は <=
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

    void mergesort(itr left, itr right) {
        if (right - left <= 1) return;
        itr mid = left + (right - left) / 2;
        mergesort(left, mid);
        mergesort(mid, right);
        merge(left, mid, right);
    }

    void heapsort(itr left, itr right) {
        auto par = [&](itr x) { return left + (x - left - 1) / 2; };
        auto lch = [&](itr x) { return left + ((x - left) << 1) + 1; };
        auto rch = [&](itr x) { return left + ((x - left) << 1) + 2; };

        for (itr i = right - 1; i != left; i--)
            if (*i > *par(i)) swap(*i, *par(i));
        for (itr i = right - 1; i != left; i--) {
            itr j = left;
            swap(*i, *j);
            while (true) {
                itr l = lch(j), r = rch(j);
                if (*l < *r) swap(l, r);
                if (l < i and *j < *l) {
                    swap(*j, *l), j = l;
                } else if (rch(j) < i and *j < *rch(j)) {
                    swap(*j, *r), j = r;
                } else {
                    break;
                }
            }
        }
    }
}; // namespace sorting
