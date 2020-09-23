struct GC {
    int size;
    BIT bit;

    GC(int n) : bit(n), size(n) {
        for (int i = 1; i <= bit.data[0]; i++) { bit.data[i] = i & -i; }
    }

    int group_index(int index) { return bit.sum(index + 1) - 1; }
    int dist(int x, int y) { return abs(group_index(x) - group_index(y)); }

    int begin(int group_index) { return bit.lower_bound(group_index + 1); }
    int end(int group_index) { return bit.lower_bound(group_index + 2); }
    int group_size(int group_index) { return end(group_index) - begin(group_index); }

    void group(int index) {
        int s = -(bit.sum(index + 2) - bit.sum(index + 1));
        bit.add(index + 1, s);
        size += s;
    }
    void cut(int index) {
        int s = !(bit.sum(index + 2) - bit.sum(index + 1));
        bit.add(index + 1, s);
        size += s;
    }
};