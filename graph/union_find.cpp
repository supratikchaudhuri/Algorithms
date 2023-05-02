#include<bits/stdc++.h>
using namespace std;

//uses path compression in find and union based on ranking
class UnionFind {
    int n;
    int components;
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        this->n = n;
        this->components = n;
        parent.resize(n+1);
        rank.resize(n+1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    bool Union(int x, int y) {
        if(find(x) == find(y))
            return 0;   // no union performed

        int px = find(x);
        int py = find(y);

        if(rank[px] >= rank[py]) {
            parent[py] = px;
            rank[px] += rank[py];
        } else {
            parent[px] = py;
            rank[py] += rank[px];
        }
        components--;
        return 1;
    }

    int find(int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool isConnected() {
        return components <= 1;
    }

    int getComponents() {
        for(int i = 0; i < n; i++) {
            cout<<i<<" "<<parent[i]<<endl;
        }
        cout<<endl;
        return components;
    }
};

int main() {

    vector<vector<int>> adj = {{1,3},{0,2},{},{},{5},{6,8},{7},{8,4},{6},{10},{11},{9}};
    
    UnionFind UF(adj.size());

    for(int i = 0; i < adj.size(); i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            UF.Union(i, adj[i][j]);
        }
    }

    cout<<UF.getComponents();
    return 0;
}

