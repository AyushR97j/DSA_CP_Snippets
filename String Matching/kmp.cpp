#include <bits/stdc++.h>
using namespace std;

// pi[i] = length of the longest proper prefix of s[0..i] which is also a suffix of s[0..i]
vector<int> prefix_function(string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1]; // fall back to the next shorter border
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// Returns 0-based starting indices of all occurrences of pattern s in text t. O(S + T)
vector<int> kmp(string &s, string &t) {
    int S = s.size(), T = t.size();
    vector<int> occurrences;
    if (S == 0 || S > T) return occurrences;

    vector<int> pi = prefix_function(s);
    int j = 0; // number of characters of s matched so far
    for (int i = 0; i < T; i++) {
        while (j > 0 && t[i] != s[j])
            j = pi[j-1];
        if (t[i] == s[j])
            j++;
        if (j == S) {
            occurrences.push_back(i - S + 1);
            j = pi[j-1]; // continue searching for overlapping matches
        }
    }
    return occurrences;
}

int main() {

    //S1 - Pattern ||  S2-Word
    string s1 = "abc";
    string s2 = "abcabcabcvxxabcaddabc";
    vector<int> occurences = kmp(s1, s2);

    for(auto it : occurences) cout<<it<<" ";
    return 0;
}
