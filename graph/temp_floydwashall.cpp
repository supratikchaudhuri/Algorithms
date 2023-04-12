#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;
 
// Recursive function to print path of given vertex `u` from source vertex `v`
void printPath(vector<vector<int>> const &path, int v, int u)
{
    if (path[v][u] == v) {
        return;
    }
    printPath(path, v, path[v][u]);
    cout << path[v][u]+1 << ", ";
}
 
// Function to print the shortest cost with path information between
// all pairs of vertices
void printSolution(vector<vector<int>> const &cost, vector<vector<int>> const &path)
{
    int n = cost.size();
    for (int v = 0; v < n; v++) {
        for (int u = 0; u < n; u++) {
            if (u != v && path[v][u] != -1) {
                cout << "The shortest path from " << v+1 << " —> " << u+1 << " is ["
                    << v+1 << ", ";
                printPath(path, v, u);
                cout << u+1 << "]" << endl;
            }
        }
    }
}
 
// Function to run the Floyd–Warshall algorithm
void floydWarshall(vector<vector<int>> const &adjMatrix)
{
    // total number of vertices in the `adjMatrix`
    int n = adjMatrix.size();
 
    // base case
    if (n == 0) {
        return;
    }
 
    // cost[] and path[] stores shortest path
    // (shortest cost/shortest route) information
    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> path(n, vector<int>(n));
 
    // initialize cost[] and path[]
    for (int v = 0; v < n; v++)
    {
        for (int u = 0; u < n; u++)
        {
            // initially, cost would be the same as the weight of the edge
            cost[v][u] = adjMatrix[v][u];
 
            if (v == u) {
                path[v][u] = 0;
            }
            else if (cost[v][u] != INT_MAX) {
                path[v][u] = v;
            }
            else {
                path[v][u] = -1;
            }
        }
    }
 
    // run Floyd–Warshall
    for (int k = 0; k < n; k++) {
        for (int v = 0; v < n; v++) {
            for (int u = 0; u < n; u++) {
                // If vertex `k` is on the shortest path from `v` to `u`,
                // then update the value of cost[v][u] and path[v][u]
 
                if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX
                    && cost[v][k] + cost[k][u] < cost[v][u]) {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }
 
            // if diagonal elements become negative, the
            // graph contains a negative-weight cycle
            if (cost[v][v] < 0) {
                cout << "Negative-weight cycle found!!";
                return;
            }
        }
    }
 
    // Print the shortest path between all pairs of vertices
    printSolution(cost, path);
}
 
int main()
{
    // define infinity
    int I = INT_MAX;
 
    // given adjacency representation of the matrix
    vector<vector<int>> adjMatrix ={{0, INT_MAX, INT_MAX, INT_MAX, -1, INT_MAX},
                       {1, 0, INT_MAX, 2, INT_MAX, INT_MAX},
                       {INT_MAX, 2, 0, INT_MAX, INT_MAX, 1008},
                       {-4, INT_MAX, INT_MAX, 0, 3, INT_MAX},
                       {INT_MAX, 7, INT_MAX, INT_MAX, 0, INT_MAX},
                       {INT_MAX, 5, 10, INT_MAX, INT_MAX, 0}};
 
    // Run Floyd–Warshall algorithm
    floydWarshall(adjMatrix);
 
    return 0;
}