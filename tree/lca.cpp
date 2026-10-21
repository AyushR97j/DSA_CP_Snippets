#include <bits/stdc++.h>
using namespace std;

// Lowest Common Ancestor using Binary Lifting (Sparse Table)
// Precomputation : O(n*log(n)) | Each LCA / MoveUp query : O(log(n))
// Nodes are 1-indexed, root = 1

const int LOG = 20;            // 2^20 > 1e6, enough for n <= 1e6

vector<int> adj[200005];
int par[LOG + 1][200005];      // par[j][node] = 2^j-th ancestor of node
int level[200005];             // depth of node, level[root] = 0

// Precomputation in O(n*log(n))
// call DFS(root, root) -> root's parent is root itself, so jumps above root stay at root
void DFS(int node, int immediateParent) {
    par[0][node] = immediateParent;
    if (node != immediateParent)
        level[node] = level[immediateParent] + 1;
    for (int j = 1; j <= LOG; j++)
        par[j][node] = par[j-1][par[j-1][node]]; // 2^j up = 2^(j-1) up, then 2^(j-1) up again
    for (int child : adj[node]) {
        if (child == immediateParent) continue;
        DFS(child, node);
    }
}

// Move node up by val levels (jump on every set bit of val)
int MoveUp(int node, int val) {
    for (int j = LOG; j >= 0; j--) {   // j must go down to 0, else odd jumps are missed
        if (val & (1 << j))
            node = par[j][node];
    }
    return node;
}

int LCA(int x, int y) {
    if (level[x] > level[y]) swap(x, y);
    y = MoveUp(y, level[y] - level[x]);   // bring both nodes to the same level
    if (x == y) return x;                 // x was an ancestor of y
    for (int j = LOG; j >= 0; j--) {
        if (par[j][x] == par[j][y]) continue; // jump only while ancestors differ
        x = par[j][x];
        y = par[j][y];
    }
    return par[0][x];   // x and y are now children of the LCA
}

int main() {
    // Tree :  1 - 2, 1 - 3, 2 - 4, 2 - 5, 3 - 6, 5 - 7  (root = 1)
    vector<pair<int,int>> edges = {{1,2}, {1,3}, {2,4}, {2,5}, {3,6}, {5,7}};
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, 1);

    cout << LCA(4, 7) << "\n"; // 2
    cout << LCA(7, 6) << "\n"; // 1
    cout << LCA(2, 7) << "\n"; // 2
    cout << MoveUp(7, 2) << "\n"; // 2
    return 0;
}
