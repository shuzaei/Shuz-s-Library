struct Heap { // max
    vector<ll> heap;
    ll size = 0;
    Heap(ll n = 200000) : heap(n) {}
    void push(ll x) {
        ll i = size++;
        while (i > 0) {
            ll par = (i - 1) / 2;
            if (heap[par] >= x) break; //<=
            heap[i] = heap[par];
            i = par;
        }
        heap[i] = x;
    }
    ll pop() {
        ll root = heap[0];
        ll x = heap[--size];
        ll i = 0;
        while (i * 2 + 1 < size) {
            ll left = i * 2 + 1, right = i * 2 + 2;
            if (right < size && heap[right] > heap[left]) left = right; // heap[right]<heap[left]
            if (heap[left] <= x) break;                                 //>=
            heap[i] = heap[left];
            i = left;
        }
        heap[i] = x;
        return root;
    }
    bool empty() { return size == 0; }
};