#include <bits/stdc++.h>
using namespace std;

// All divisors of n in O(sqrt(n)), returned in sorted order
vector<long long> getDivisors(long long n) {
    vector<long long> small, large;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i) continue;
        small.push_back(i);
        if (i != n / i) large.push_back(n / i); // pair divisor, avoid adding sqrt twice
    }
    reverse(large.begin(), large.end());
    small.insert(small.end(), large.begin(), large.end());
    return small;
}

// Number of divisors of every number up to N in O(N log N)
const int N = 1e6 + 5;
int divCount[N];

void countAllDivisors() {
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divCount[j]++;
}

int main() {
    for (auto d : getDivisors(36)) cout << d << " "; // 1 2 3 4 6 9 12 18 36
    cout << "\n";

    countAllDivisors();
    cout << divCount[36] << " " << divCount[720720] << "\n"; // 9 240
    return 0;
}
