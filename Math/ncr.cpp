#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// ---------- Method 1 : precomputed factorials, O(N) precompute, O(1) per query ----------
// Use when : many queries, n up to ~1e6, MOD is prime
const int N = 1e6 + 5;
long long fact[N], invFact[N];

long long modpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i-1] * i % MOD;
    invFact[N-1] = modpow(fact[N-1], MOD - 2);
    for (int i = N - 1; i > 0; i--)
        invFact[i-1] = invFact[i] * i % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}

// ---------- Method 2 : Pascal's triangle, O(n^2) ----------
// Use when : n <= ~5000, or MOD is NOT prime. C[n][r] = C[n-1][r-1] + C[n-1][r]
const int MAXN = 1001;
long long C[MAXN][MAXN];

void buildPascal() {
    for (int n = 0; n < MAXN; n++) {
        C[n][0] = 1;
        for (int r = 1; r <= n; r++)
            C[n][r] = (C[n-1][r-1] + C[n-1][r]) % MOD;
    }
}

// ---------- Method 3 : exact value without mod, O(r) ----------
// Use when : the answer itself fits in long long (always true for n <= 66). Each step stays an integer.
// __int128 because res * (n - i) can overflow long long even when the final answer fits
long long nCrExact(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    long long res = 1;
    for (long long i = 0; i < r; i++)
        res = (__int128)res * (n - i) / (i + 1);
    return res;
}

int main() {
    precomputeFactorials();
    buildPascal();
    cout << nCr(5, 2) << "\n";          // 10
    cout << nCr(1000000, 500000) << "\n"; // 996692777
    cout << C[1000][500] << "\n";       // 159835829
    cout << nCrExact(60, 30) << "\n";   // 118264581564861424
    cout << nCrExact(66, 33) << "\n";   // 7219428434016265740
    return 0;
}
