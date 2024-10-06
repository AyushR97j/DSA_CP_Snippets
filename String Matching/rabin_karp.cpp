#include <bits/stdc++.h>
using namespace std;

long long mod_mult(long long a, long long b, long long mod) {
    return (a * b) % mod;
}

vector<int> rabin_karp(string & s, string &t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == mod_mult(h_s, p_pow[i], m))
            occurrences.push_back(i);
    }
    return occurrences;
}

int main() {
    
    //S1 - Pattern ||  S2-Word
    string s1 = "abc";
    string s2 = "abcabcabcvxxabcaddabc";
    vector<int> occurences = rabin_karp(s1, s2);
    
    for(auto it : occurences) cout<<it<<" ";
    return 0;
}
