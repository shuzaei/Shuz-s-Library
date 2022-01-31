template <class T = string> struct kmp {
    vector<ll> next;
    T x;

    kmp(T x) : x(x + '$'), next(x.size() + 1, -1) {
        for (ll i = 1, j = -1; i <= (ll) x.size(); i++) {
            while (j >= 0 && x[i - 1] != x[j]) j = next[j];
            next[i] = x[i] == x[++j] ? next[j] : j;
        }
    }

    vector<ll> search(T x) {
        vector<ll> ans;
        for (ll i = 0, j = 0; j < (ll) x.size(); j++) {
            this->x[i] == x[j] || (i = next[i]) < 0 ? i++ : j--;
            if (i == (ll) this->x.size() - 1) ans.push_back(j - i + 1), i = next[i];
        }
        return ans;
    }
};