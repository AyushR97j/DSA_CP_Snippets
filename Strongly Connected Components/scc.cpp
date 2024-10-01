#include <bits/stdc++.h>
using namespace std;

vector<int> temp;
vector<vector<int>> scc;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> adj[], vector<int> &vis, vector<int> &temp) {
    vis[node] = 1; 
    temp.push_back(node);
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs2(it, adj, vis, temp);
        }
    }
}


void getSCC() {
    int n, m;
    cin >> n >> m;

    vector<int> vis(n + 1, 0);
    vector<int> adj[n + 1], tadj[n + 1];
    stack<int> st;
    
    vector<vector<int>> scc;                
    vector<int> temp;

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        tadj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i, adj, vis, st);
        }
    }

    fill(vis.begin(), vis.end(), 0);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (vis[node] == 0) {
            dfs2(node, tadj, vis, temp);
            scc.push_back(temp); 
            temp.clear();
        }
    }
    
    cout<<"count of scc : ";
    cout << scc.size() << endl;
    for (auto &it : scc) {
        for (auto &j : it) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    getSCC();
    return 0;
}
