#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
typedef vector<vector<long long>> Matrix;

Matrix multiply(const Matrix &A, const Matrix &B) {
    int n = A.size(), m = B[0].size(), k = B.size();
    Matrix C(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++)
        for (int t = 0; t < k; t++) {
            if (A[i][t] == 0) continue;
            for (int j = 0; j < m; j++)
                C[i][j] = (C[i][j] + A[i][t] * B[t][j]) % MOD;
        }
    return C;
}

// M^p for a square matrix, O(k^3 log p)
Matrix matpow(Matrix M, long long p) {
    int k = M.size();
    Matrix res(k, vector<long long>(k, 0));
    for (int i = 0; i < k; i++) res[i][i] = 1; // identity
    while (p > 0) {
        if (p & 1) res = multiply(res, M);
        M = multiply(M, M);
        p >>= 1;
    }
    return res;
}

// n-th Fibonacci (F0 = 0, F1 = 1) in O(log n)
// [F(n+1) F(n)  ]   [1 1]^n
// [F(n)   F(n-1)] = [1 0]
long long fib(long long n) {
    if (n == 0) return 0;
    Matrix M = {{1, 1}, {1, 0}};
    return matpow(M, n)[0][1];
}

// Any linear recurrence f(n) = c1*f(n-1) + c2*f(n-2) + ... + ck*f(n-k) works the same way :
// first row = {c1, c2, ..., ck}, below it a shifted identity.

int main() {
    cout << fib(10) << "\n";                  // 55
    cout << fib(90) % MOD << "\n";            // 2880067194370816120 % MOD = 210345902
    cout << fib(1000000000000000000LL) << "\n"; // 209783453
    return 0;
}
