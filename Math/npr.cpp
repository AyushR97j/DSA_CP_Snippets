#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// nPr = n! / (n-r)!  -> number of ordered arrangements of r items out of n

// ---------- Method 1 : precomputed factorials, O(1) per query (MOD prime) ----------
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

long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[n-r] % MOD;
}

// ---------- Method 2 : direct product n * (n-1) * ... * (n-r+1), O(r) ----------
// Works for any MOD and any n (even n > 1e6)
long long nPrDirect(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    long long res = 1;
    for (long long i = 0; i < r; i++)
        res = res * ((n - i) % MOD) % MOD;
    return res;
}

int main() {
    precomputeFactorials();
    cout << nPr(5, 2) << "\n";             // 20
    cout << nPr(10, 10) << "\n";           // 3628800
    cout << nPrDirect(5, 2) << "\n";       // 20
    cout << nPrDirect(1e12, 3) << "\n";    // 852988408
    return 0;
}
