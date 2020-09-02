template <class T> struct choice {
    ll rank;
    rpriority_queue<T> up;
    priority_queue<T> down;

    choice() : rank(1) {}

    void push(T x) {
        down.push(x);
        up.push(down.top());
        down.pop();
    }
    T top() { return up.top(); }
    T top_down() { return down.top(); }

    T pop() {
        T mem = up.top();
        up.pop();
        return mem;
    }
    T pop_down() {
        T mem = down.top();
        down.pop();
        return mem;
    }

    ll rank_inc() {
        down.push(up.top());
        up.pop();
        return ++rank;
    }
    ll rank_dec() {
        up.push(down.top());
        down.pop();
        return --rank;
    }

    void rank_change(ll to) {
        while (to > rank) rank_inc();
        while (to < rank) rank_dec();
    }

    T operator[](ll to) {
        rank_change(to);
        return top();
    }
};