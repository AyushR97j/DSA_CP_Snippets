#include <bits/stdc++.h>
using namespace std;

// z[i] = length of the longest common prefix of s and s[i..n-1] (z[0] = 0 by convention)
vector<int> z_function(string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0; // [l, r) is the rightmost segment matching a prefix of s
    for (int i = 1; i < n; i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]); // reuse already computed values inside the box
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// Returns 0-based starting indices of all occurrences of pattern s in text t. O(S + T)
vector<int> z_search(string &s, string &t) {
    int S = s.size(), T = t.size();
    vector<int> occurrences;
    if (S == 0 || S > T) return occurrences;

    // '#' is a separator that must not appear in s or t
    string concat = s + "#" + t;
    vector<int> z = z_function(concat);
    for (int i = S + 1; i < (int)concat.size(); i++) {
        if (z[i] == S)
            occurrences.push_back(i - S - 1);
    }
    return occurrences;
}

int main() {

    //S1 - Pattern ||  S2-Word
    string s1 = "abc";
    string s2 = "abcabcabcvxxabcaddabc";
    vector<int> occurences = z_search(s1, s2);

    for(auto it : occurences) cout<<it<<" ";
    return 0;
}
