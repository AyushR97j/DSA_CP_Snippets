#include <bits/stdc++.h>
using namespace std;

// ---------- Method 1 : trial division, O(sqrt(n)) per number ----------
// returns {prime, exponent} pairs, e.g. 360 -> {2,3} {3,2} {5,1}
vector<pair<long long,int>> factorize(long long n) {
    vector<pair<long long,int>> res;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p) continue;
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        res.push_back({p, cnt});
    }
    if (n > 1) res.push_back({n, 1}); // remaining part is a prime > sqrt(original n)
    return res;
}

// ---------- Method 2 : smallest prime factor sieve, O(log n) per number ----------
// Use when : many numbers to factorize, all <= N
const int N = 1e7 + 5;
vector<int> spf(N, 0); // spf[x] = smallest prime factor of x

void buildSPF() {
    for (int i = 2; i < N; i++) {
        if (spf[i] != 0) continue; // i is not prime
        for (long long j = i; j < N; j += i)
            if (spf[j] == 0) spf[j] = i;
    }
}

vector<pair<int,int>> factorizeSPF(int n) {
    vector<pair<int,int>> res;
    while (n > 1) {
        int p = spf[n], cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        res.push_back({p, cnt});
    }
    return res;
}

int main() {
    for (auto [p, e] : factorize(360)) cout << p << "^" << e << " "; // 2^3 3^2 5^1
    cout << "\n";

    buildSPF();
    for (auto [p, e] : factorizeSPF(9699690)) cout << p << "^" << e << " "; // 2^1 3^1 5^1 7^1 11^1 13^1 17^1 19^1
    cout << "\n";
    return 0;
}
