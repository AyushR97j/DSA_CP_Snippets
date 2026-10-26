#include <bits/stdc++.h>
using namespace std;

// phi(n) = count of 1 <= k <= n with gcd(k, n) = 1
// phi(n) = n * product of (1 - 1/p) over distinct primes p dividing n

// ---------- single number, O(sqrt(n)) ----------
long long phi(long long n) {
    long long res = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p) continue;
        while (n % p == 0) n /= p;
        res -= res / p;
    }
    if (n > 1) res -= res / n;
    return res;
}

// ---------- all numbers up to N, O(N log log N) ----------
const int N = 1e6 + 5;
int phiAll[N];

void phiSieve() {
    for (int i = 0; i < N; i++) phiAll[i] = i;
    for (int i = 2; i < N; i++) {
        if (phiAll[i] != i) continue; // i is not prime
        for (int j = i; j < N; j += i)
            phiAll[j] -= phiAll[j] / i;
    }
}

int main() {
    cout << phi(9) << " " << phi(36) << " " << phi(97) << "\n"; // 6 12 96
    phiSieve();
    cout << phiAll[9] << " " << phiAll[36] << " " << phiAll[97] << "\n"; // 6 12 96
    return 0;
}
