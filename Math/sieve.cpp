#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes : all primes up to n in O(n log log n)
const int N = 1e7 + 5;
vector<bool> isPrime(N, true);
vector<int> primes;

void sieve(int n = N - 1) {
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (!isPrime[i]) continue;
        for (long long j = i * i; j <= n; j += i) // smaller multiples were already marked
            isPrime[j] = false;
    }
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) primes.push_back(i);
}

int main() {
    sieve();
    cout << isPrime[97] << " " << isPrime[100] << "\n"; // 1 0
    cout << primes.size() << "\n";                       // 664579 primes below 1e7
    for (int i = 0; i < 10; i++) cout << primes[i] << " "; // 2 3 5 7 11 13 17 19 23 29
    return 0;
}
