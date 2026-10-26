#include <bits/stdc++.h>
using namespace std;

// Finds x, y such that a*x + b*y = gcd(a, b). Returns gcd(a, b).  O(log(min(a, b)))
long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// a^(-1) mod m for ANY m (not necessarily prime). Returns -1 if it doesn't exist (gcd(a, m) != 1)
long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extgcd(((a % m) + m) % m, m, x, y);
    if (g != 1) return -1;
    return ((x % m) + m) % m;
}

int main() {
    long long x, y;
    long long g = extgcd(30, 20, x, y);
    cout << g << " " << x << " " << y << "\n"; // 10 1 -1   (30*1 + 20*(-1) = 10)

    cout << modInverse(3, 10) << "\n";  // 7   (3*7 = 21 = 1 mod 10)
    cout << modInverse(4, 10) << "\n";  // -1  (gcd(4, 10) = 2)
    return 0;
}
