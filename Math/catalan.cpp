#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// Catalan numbers : 1, 1, 2, 5, 14, 42, 132, ...
// Counts : valid parentheses sequences of n pairs, BSTs with n nodes, full binary trees with n+1 leaves,
//          ways to triangulate a polygon with n+2 sides, monotonic lattice paths not crossing the diagonal

// ---------- Method 1 : DP, O(n^2), works for any MOD ----------
// C(0) = 1, C(n+1) = sum C(i) * C(n-i) for i = 0..n
vector<long long> catalanDP(int n) {
    vector<long long> c(n + 1, 0);
    c[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            c[i] = (c[i] + c[j] * c[i-1-j]) % MOD;
    return c;
}

// ---------- Method 2 : formula C(n) = (2n)! / ((n+1)! * n!), O(n) (MOD prime) ----------
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

long long catalan(int n) {
    long long num = 1, den = 1;
    for (int i = 1; i <= 2 * n; i++) num = num * i % MOD;  // (2n)!
    for (int i = 1; i <= n; i++) den = den * i % MOD;      // n!
    den = den * den % MOD * (n + 1) % MOD;                 // n! * n! * (n+1) = n! * (n+1)!
    return num * modpow(den, MOD - 2) % MOD;
}

int main() {
    vector<long long> c = catalanDP(10);
    for (auto x : c) cout << x << " "; // 1 1 2 5 14 42 132 429 1430 4862 16796
    cout << "\n";
    cout << catalan(10) << "\n";       // 16796
    cout << catalan(1000) << "\n";     // 110961515
    return 0;
}
