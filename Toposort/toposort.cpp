#include <bits/stdc++.h>
using namespace std;

//Kahn's Algo(BFS)
void toposort(int node, vector<int> &indeg, vector<int> &topo, vector<vector<int>> &adj, vector<int> &vis) {
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        topo.push_back(x);

        for(auto it: adj[x]) {
            indeg[it]--;
            if(indeg[it] == 0 && vis[it] == 0) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> indeg(n + 1, 0);
    vector<int> vis(n + 1, 0);
    vector<int> topo;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0 && vis[i] == 0) {
            toposort(i, indeg, topo, adj, vis);
        }
    }

    for(auto it: topo) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

//Topological sort :
//1.BFS : Kahn's Algo (BFS)
//2.DFS