namespace Matrix {
using T = long double;
using matrix = vector<vector<T>>;
using elem_v = vector<T>;

matrix E(ll N) {
    matrix A(N, elem_v(N));
    rep(i, N) A[i][i] = 1;
    return A;
}
matrix add(matrix A, matrix B) {
    int m = A.size(), n = A[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] += B[i][j];
        }
    }
    return A;
}
matrix t(matrix A) {
    int m = A.size(), n = A[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) swap(A[i][j], A[j][i]);
        }
    }
    return A;
}
matrix multiple(T A, matrix B) {
    int m = B.size(), n = B[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] *= A;
        }
    }
    return B;
}
matrix product(matrix A, matrix B) {
    int m = A.size(), n = B.size(), l = B[0].size();
    matrix C(m, elem_v(l));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
matrix pow(matrix A, ll N) {
    if (!N) return E(A.size());
    matrix B = pow(A, N >> 1);
    B = product(B, B);
    if (N & 1) B = product(B, A);
    return B;
}
void print(matrix A) {
    int m = A.size(), n = A[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << (j == n - 1 ? '\n' : ' ');
        }
    }
}
} // namespace Matrix
