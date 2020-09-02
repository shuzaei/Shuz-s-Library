struct BIT {
    vector<int> data;

    BIT() {}
    BIT(int n) : data(n + 1) {
        fill(data.begin(), data.end(), 0);
        data[0] = n;
    }

    void add(int pos, int val) {
        pos++;
        while (pos <= data[0]) {
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    int sum(int pos) {
        if (pos <= 0) return 0;
        int res = 0;
        while (pos > 0) {
            res += data[pos];
            pos -= pos & -pos;
        }
        return res;
    }

    int lower_bound(int val) {
        if (val <= 0) return 0;
        int index = 0;
        for (int d = 1 << int(log2(data[0])); d > 0; d /= 2) {
            if (index + d <= data[0] && data[index + d] < val) {
                val -= data[index + d];
                index += d;
            }
        }
        return index;
    }
};

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