#include <bits/stdc++.h>
using namespace std;

// Euclid's algorithm, O(log(min(a, b)))
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// divide first to avoid overflow
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// Built-ins : std::gcd(a, b) / std::lcm(a, b) (C++17, <numeric>) or __gcd(a, b)

int main() {
    cout << gcd(12, 18) << "\n";   // 6
    cout << lcm(12, 18) << "\n";   // 36
    cout << gcd(17, 0) << "\n";    // 17

    // gcd of an array
    vector<long long> v = {24, 36, 60};
    long long g = 0;
    for (auto x : v) g = gcd(g, x);
    cout << g << "\n";             // 12
    return 0;
}
