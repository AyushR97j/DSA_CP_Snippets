#include <bits/stdc++.h>
using namespace std;

class dsu {
    vector<int> parent, size;
public :
    dsu(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findPar(parent[node]); // Path compression //DP
    }

    void unionSize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv) {
            return;
        }
        //attach smaller to bigger
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main() {
    dsu d(5);
    
    return 0;
}