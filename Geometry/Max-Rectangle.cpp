struct max_rectangle {
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
    vector<ll> histgram;
    ll pos_l, pos_r, surface = 0;
    max_rectangle(vector<ll> h) : histgram(h) {}
    void solve() {
        deque<pair<ll, ll>> deq;
        histgram.push_back(0);
        rep(i, histgram.size() + 1) {
            if (deq.empty() || deq.back().first < histgram[i]) {
                deq.push_back({histgram[i], i});
            } else if (deq.back().first == histgram[i]) {
                continue;
            } else {
                ll last = -1;
                while (deq.size() && deq.back().first > histgram[i]) {
                    ll sum = (i - deq.back().second) * deq.back().first;
                    if (surface <= sum) {
                        surface = sum;
                        pos_l = deq.back().second;
                        pos_r = i + 1;
                    }
                    last = deq.back().second;
                    deq.pop_back();
                }
                if (last != -1) deq.push_back({histgram[i], last});
            }
        }
    }
    Range max_range() { return Range(pos_l, pos_r); }
    ll max_surface() { return surface; }
};