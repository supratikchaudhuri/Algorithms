#include <bits/stdc++.h>
using namespace std;

#define V 6 //No of vertices

void printPath(int path[V][V], int i, int j) {
    cout<<i<<" "<<j<<" "<<path[i][j]<<endl;
    if (path[i][j] == i) {
        return;
    }
    printPath(path, i, path[i][j]);
    cout << path[i][j] << ", ";
}

void floyd_warshall(int graph[V][V]) {
    int dist[V][V];
    int path[V][V];

    //Assign all values of graph to allPairs_SP
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = graph[i][j];

            if(i == j) path[i][j] = 0;
            else if(graph[i][j] != INT_MAX) path[i][j] = j;
            else path[i][j] = -1;
        }
    }

    //Find all pairs shortest path by trying all possible paths
    for (int k = 0; k < V; ++k) {         //Try all intermediate nodes
        for (int i = 0; i < V; ++i) {    //Try for all possible starting position
            for (int j = 0; j < V; ++j) {//Try for all possible ending position
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) //SKIP if K is unreachable from i or j is unreachable from k
                    continue;
                else if (dist[i][k] + dist[k][j] < dist[i][j]) { //Check if new distance is shorter via vertex K
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
        // for(int i = 0; i < V; i++) {
        //     for(int j = 0; j < V; j++)
        //         cout<<(j == 0 ? "" : "&")<<(dist[i][j] == INT_MAX ? "\\infty" : to_string(dist[i][j]))<<(j == V-1 ? "\\\\" : " ");
        //     cout<<endl;
        // }
        // cout<<endl<<endl<<endl;
    }

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if (i != j && path[i][j] != -1) {
                cout << "The shortest path from " << i << " —> " << j << " is ["
                    << i << ", ";
                printPath(path, i, j);
                cout << j << "]" << endl;
            }
        }
    }

    // for(int i = 0; i < V; i++) {
    //     for(int j = 0; j < V; j++) {
    //         for(int k = 0; k < V; k++) {
    //             if(dist[i][k] + dist[k][j] == dist[i][j])
    //                 parent[i][j] = k;
    //         }
    //     }
    // }

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++)
            cout<<path[i][j]<<"  ";
        cout<<endl;
    }

    // for(int i = 0; i < V; i++) {
    //     for(int j = 0; j < V; j++) {
    //         cout<<"Path from "<<i+1<<" to "<<j+1<<":  \n";
            
    //         int cur = i;
    //         do (cur != j) {
    //             cout<<cur+1<< " -> ";
    //         } while(cur != j)
    //     }
    //     cout<<endl;
    // }

    // //Check for negative edge weight cycle
    // for (int i = 0; i < V; ++i)
    //     if (dist[i][i] < 0) {
    //         cout << "Negative edge weight cycle is present\n";
    //         return;
    //     }

    //Print Shortest Path Graph
    //(Values printed as INT_MAX defines there is no path)
    // for (int i = 0; i < V; ++i) {
    //     for (int j = 0; j < V; ++j)
    //         cout << i+1 << " to " << j+1 << " distance is " << dist[i][j] << "\n";
    //     cout << "=================================\n";
    // }
}

int main() {
    int graph[V][V] = {{0, INT_MAX, INT_MAX, INT_MAX, -1, INT_MAX},
                       {1, 0, INT_MAX, 2, INT_MAX, INT_MAX},
                       {INT_MAX, 2, 0, INT_MAX, INT_MAX, 1008},
                       {-4, INT_MAX, INT_MAX, 0, 3, INT_MAX},
                       {INT_MAX, 7, INT_MAX, INT_MAX, 0, INT_MAX},
                       {INT_MAX, 5, 10, INT_MAX, INT_MAX, 0}};

    floyd_warshall(graph);
    return 0;
}

//TIME COMPLEXITY: O(V^3) (v for inclusion and v2 for fillig adj matrix)