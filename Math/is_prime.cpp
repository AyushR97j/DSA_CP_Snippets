#include <bits/stdc++.h>
using namespace std;

// Primality check for a single number in O(sqrt(n))
// For many numbers up to ~1e7, use sieve.cpp instead
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n < 4) return true;           // 2, 3
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) // every prime > 3 is 6k-1 or 6k+1
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int main() {
    for (long long x : {1LL, 2LL, 15LL, 97LL, 1000000007LL})
        cout << x << " : " << isPrime(x) << "\n"; // 0 1 0 1 1
    return 0;
}
