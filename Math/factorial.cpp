#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7; // must be prime
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

// fact[i] = i! % MOD, invFact[i] = (i!)^(-1) % MOD, for 0 <= i < N.  O(N)
void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i-1] * i % MOD;
    invFact[N-1] = modpow(fact[N-1], MOD - 2);
    for (int i = N - 1; i > 0; i--)
        invFact[i-1] = invFact[i] * i % MOD; // 1/(i-1)! = i * 1/i!
}

int main() {
    precomputeFactorials(); // call once at the start
    cout << fact[5] << "\n";                       // 120
    cout << fact[20] << "\n";                      // 146326063
    cout << fact[10] * invFact[10] % MOD << "\n";  // 1
    return 0;
}
