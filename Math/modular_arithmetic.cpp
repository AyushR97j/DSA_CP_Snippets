#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7; // must be prime for modinv / moddiv (Fermat's little theorem)

// brings any value (even negative) into [0, MOD)
long long norm(long long a) {
    a %= MOD;
    if (a < 0) a += MOD;
    return a;
}

long long add(long long a, long long b) { return norm(norm(a) + norm(b)); }
long long sub(long long a, long long b) { return norm(norm(a) - norm(b)); }
long long mul(long long a, long long b) { return norm(a) * norm(b) % MOD; }

long long modpow(long long a, long long b) {
    a = norm(a);
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// a^(-1) mod MOD = a^(MOD-2) mod MOD  (MOD prime, a % MOD != 0)
long long modinv(long long a) { return modpow(a, MOD - 2); }

// (a / b) mod MOD
long long moddiv(long long a, long long b) { return mul(a, modinv(b)); }

// Note : (a / b) % MOD != (a % MOD) / (b % MOD). Always use moddiv for division.
// For a non-prime MOD, use modInverse from extended_euclid.cpp (needs gcd(a, MOD) = 1).

int main() {
    cout << add(MOD - 1, 5) << "\n";   // 4
    cout << sub(3, 5) << "\n";         // 1000000005
    cout << mul(1e9, 1e9) << "\n";     // 49
    cout << modinv(2) << "\n";         // 500000004
    cout << moddiv(10, 4) << "\n";     // 500000006  (= 5/2 mod p)
    cout << mul(moddiv(10, 4), 4) << "\n"; // 10
    return 0;
}
