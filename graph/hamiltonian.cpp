#include<bits/stdc++.h>
using namespace std;

vector<int> dfs(int cur, int n, vector<vector<int>>& adj, vector<int> vis, vector<int> path) {
    path.push_back(cur);
    vis[cur] = true;

    if(path.size() == n) return path;//n shows remaining vertices

    for(auto nei : adj[cur]) {
        if(!vis[nei]){
            auto res = dfs(nei, n, adj, vis, path);
            if(res.size() == n) return res;
        }
    }
    return {};
}

vector<int> hamiltonianPath(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, false);
    vector<int> res = {};

    for(int i = 1; i < n; i++) {
        res = dfs(i, n-1, adj, vis, {});
        if(res.size() == n-1) break;
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto res = hamiltonianPath(adj);
    cout<<"path: ";
    for(auto it : res)
        cout<< it << " ";
    cout<<endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

// //inputs
// 2
// 10 14
// 2 1 10 2 6 3 5 4 10 5 10 6 6 7 6 8 10 9 4 9 3 8 3 7 5 9 6 5 
// 10 14
// 8 1 8 2 1 3 5 4 1 5 8 6 1 7 2 9 5 10 7 8 6 3 3 5 7 9 6 10