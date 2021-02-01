#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

struct record{
    int cost, to;
};

vector<record> multistage(vector<vector<int>>& graph) {
    int rows = graph.size(), cols = graph[0].size();

    vector<record> res(cols);
    res[cols-1].cost = 0;
    res[cols-1].to = -1;
    
    for(int i = cols-2; i >= 0; i--) {
        res[i].cost = INF;

        for(int j = i; j < cols; j++) {
            if(graph[i][j] == INF) continue;

            if(res[i].cost > graph[i][j] + res[j].cost) {
                res[i].cost = graph[i][j] + res[j].cost;
                res[i].to = j;
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> graph = {{INF, 1, 2, 5, INF, INF, INF, INF}, 
                                {INF, INF, INF, INF, 4, 11, INF, INF}, 
                                {INF, INF, INF, INF, 9, 5, 16, INF}, 
                                {INF, INF, INF, INF, INF, INF, 2, INF}, 
                                {INF, INF, INF, INF, INF, INF, INF, 18}, 
                                {INF, INF, INF, INF, INF, INF, INF, 13}, 
                                {INF, INF, INF, INF, INF, INF, INF, 2}};  

    auto res = multistage(graph);

    // for(auto it : res) {
    //     cout<< it.cost << " " << it.to<<endl;
    // }
    cout<< "Shortest path cost = " << res[0].cost<<endl;

    cout<<"path used : "<<endl;
    int from = 0;
    cout<<from << " -> ";
    while(from != 7) {
        cout<< res[from].to << " -> ";
        from = res[from].to;
    }
    
    return 0;
}