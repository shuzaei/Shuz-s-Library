template <class T = ll> struct SWA {
    using op = function<T(T, T)>;
    vector<T> A, B;
    deque<T> D;
    op f;
    SWA(op f) : f(f) {}
    void flip() {
        if (A.size() == 0) {
            B.clear();
            for (auto i = D.end() - 1; i >= D.begin(); i--) {
                if (i == D.end() - 1) {
                    A.push_back(*i);
                } else {
                    A.push_back(f(A.back(), *i));
                }
            }
        }
    }
    T operator()() {
        flip();
        if (A.size() == 0) {
            raise(SIGSEGV);
        } else if (B.size() == 0) {
            return A.back();
        } else {
            return f(A.back(), B.back());
        }
    }
    void push(T x) {
        D.push_back(x);
        if (B.size() == 0) {
            B.push_back(x);
        } else {
            B.push_back(f(B.back(), x));
        }
    }
    void pop() {
        flip();
        if (A.size() == 0) {
            raise(SIGSEGV);
        } else {
            A.pop_back();
            D.pop_front();
        }
    }
    ll size() { return D.size(); }
};
