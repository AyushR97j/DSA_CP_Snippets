#include <bits/stdc++.h>
using namespace std;

// lps[i] = length of the longest proper prefix of pattern[0..i] which is also a suffix of pattern[0..i]
// Approach 1 : for loop
vector<int> computeLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    for (int i = 1; i < m; i++) {
        int j = lps[i-1];
        while (j > 0 && pattern[i] != pattern[j])
            j = lps[j-1]; // fall back to the next shorter border
        if (pattern[i] == pattern[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

// Approach 2 : while loop (same O(m), more explicit steps)
/*
std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;      // lps[0] is always 0
    
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                // Fall back to the previous longest prefix suffix
                length = lps[length - 1];
            } else {
                // No match found
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
*/

// Returns 0-based starting indices of all occurrences of pattern s in text t. O(S + T)
vector<int> kmp(string &s, string &t) {
    int S = s.size(), T = t.size();
    vector<int> occurrences;
    if (S == 0 || S > T) return occurrences;

    vector<int> lps = computeLPS(s);
    int j = 0; // number of characters of s matched so far
    for (int i = 0; i < T; i++) {
        while (j > 0 && t[i] != s[j])
            j = lps[j-1];
        if (t[i] == s[j])
            j++;
        if (j == S) {
            occurrences.push_back(i - S + 1);
            j = lps[j-1]; // continue searching for overlapping matches
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
