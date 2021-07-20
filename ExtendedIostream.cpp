#include <Template.cpp>

namespace extended_iostream {
    template <class T, size_t n> istream &operator>>(istream &is, array<T, n> &v) {
        for_each(v.begin(), v.end(), [&](T &x) { is >> x; });
        return is;
    }
    template <class T> istream &operator>>(istream &is, vector<T> &v) {
        for_each(v.begin(), v.end(), [&](T &x) { is >> x; });
        return is;
    }
    template <class T> istream &operator>>(istream &is, deque<T> &v) {
        for_each(v.begin(), v.end(), [&](T &x) { is >> x; });
        return is;
    }
    template <class T> istream &operator>>(istream &is, stack<T> &v) {
        for_each(v.begin(), v.end(), [&](T &x) { is >> x; });
        return is;
    }
    template <class T> istream &operator>>(istream &is, queue<T> &v) {
        for_each(v.begin(), v.end(), [&](T &x) { is >> x; });
        return is;
    }
    template <class T> istream &operator>>(istream &is, list<T> &v) {
        for_each(v.begin(), v.end(), [&](T &x) { is >> x; });
        return is;
    }
    template <class T> istream &operator>>(istream &is, pair<T> &v) {
        is >> v.first >> v.second;
        return is;
    }
}; // namespace extended_iostream

int main() {
    using namespace extended_iostream;
    vector<int> v(10);
    cin >> v;
}