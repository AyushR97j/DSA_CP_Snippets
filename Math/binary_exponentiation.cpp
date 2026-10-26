#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// a^b without mod (only when the answer fits in long long)
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// (a^b) % mod in O(log b)
long long modpow(long long a, long long b, long long mod = MOD) {
    a %= mod;
    if (a < 0) a += mod;
    long long res = 1 % mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    cout << power(2, 10) << "\n";          // 1024
    cout << modpow(2, 100) << "\n";        // 976371285
    cout << modpow(3, 0, 13) << "\n";      // 1
    return 0;
}
