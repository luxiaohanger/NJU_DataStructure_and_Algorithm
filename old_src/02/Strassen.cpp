#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#include <vector>
using namespace std;
using ll = long long;

// 矩阵加法
vector<vector<ll>> matrix_add(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// 矩阵减法
vector<vector<ll>> matrix_sub(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// 合并四个子矩阵
vector<vector<ll>> combine_matrix(
    const vector<vector<ll>>& C11, const vector<vector<ll>>& C12,
    const vector<vector<ll>>& C21, const vector<vector<ll>>& C22) {
    int n = C11.size() * 2;
    vector<vector<ll>> C(n, vector<ll>(n));
    int m = n / 2;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }
    return C;
}

// 分治矩阵乘法（Strassen算法）
vector<vector<ll>> work(const vector<vector<ll>>& A, const vector<vector<ll>>& B, int N) {
    // 递归基：1x1矩阵直接相乘
    if (N == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int half = N / 2;
    // 划分矩阵A和B为四个子矩阵
    vector<vector<ll>> A11(half, vector<ll>(half));
    vector<vector<ll>> A12(half, vector<ll>(half));
    vector<vector<ll>> A21(half, vector<ll>(half));
    vector<vector<ll>> A22(half, vector<ll>(half));

    vector<vector<ll>> B11(half, vector<ll>(half));
    vector<vector<ll>> B12(half, vector<ll>(half));
    vector<vector<ll>> B21(half, vector<ll>(half));
    vector<vector<ll>> B22(half, vector<ll>(half));

    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // 计算7个中间矩阵
    vector<vector<ll>> M1 = work(matrix_add(A11, A22), matrix_add(B11, B22), half);
    vector<vector<ll>> M2 = work(matrix_add(A21, A22), B11, half);
    vector<vector<ll>> M3 = work(A11, matrix_sub(B12, B22), half);
    vector<vector<ll>> M4 = work(A22, matrix_sub(B21, B11), half);
    vector<vector<ll>> M5 = work(matrix_add(A11, A12), B22, half);
    vector<vector<ll>> M6 = work(matrix_sub(A21, A11), matrix_add(B11, B12), half);
    vector<vector<ll>> M7 = work(matrix_sub(A12, A22), matrix_add(B21, B22), half);

    // 计算结果矩阵的四个子块
    vector<vector<ll>> C11 = matrix_add(matrix_sub(matrix_add(M1, M4), M5), M7);
    vector<vector<ll>> C12 = matrix_add(M3, M5);
    vector<vector<ll>> C21 = matrix_add(M2, M4);
    vector<vector<ll>> C22 = matrix_add(matrix_sub(matrix_add(M1, M3), M2), M6);

    // 合并子块为最终结果
    return combine_matrix(C11, C12, C21, C22);
}

void solve() {
    int N;
    cin >> N;
    vector<vector<ll> > A(N, vector<ll>(N));
    vector<vector<ll> > B(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> B[i][j];
        }
    }

    vector<vector<ll>> ans = work(A,B,N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
