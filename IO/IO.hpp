#ifndef def
#include "Shuzaei.hpp"
#endif

#define sin(a, b) ifstream a(b);
#define sout(a, b) ofstream a(b);

template <class T> def in() {
    T A;
    cin >> A;
    return A;
}

template <class T>
def out(vector<vector<T>> A, ll H, ll W, char divc = space, char endc = endl) {
    rep(i, H) {
        rep(j, W) {
            if (j)
                cout << divc << A[i][j];
            else
                cout << A[i][j];
        }
        cout << endc;
    }
}