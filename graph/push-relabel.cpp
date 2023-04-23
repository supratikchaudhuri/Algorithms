#include <bits/stdc++.h>
#include <fstream>
using namespace std;
    
struct Edge {
    int flow;
    int capacity;
    int u, v;
   
    Edge(int flow, int capacity, int u, int v) {
        this->flow = flow;
        this->capacity = capacity;
        this->u = u;
        this->v = v;
    }
};
    
struct Vertex {
    int height, excess_flow;
   
    Vertex(int height, int excess_flow) {
        this->height = height;
        this->excess_flow = excess_flow;
    }
};
    
// To represent a flow network
class Graph {
    int V;
    vector<Vertex> vertex;
    vector<Edge> edge;

    bool push(int u) {
        
        for (int i=0; i <edge.size(); i++) {
            if (edge[i].u == u) {
                auto e = edge[i];
                cout<<"Edge: "<<e.u<<"->"<<e.v<<"   "<<e.flow<<"/"<<e.capacity<<endl;
                cout<<"Source Vertex: "<<e.u<<"  Height: "<<vertex[e.u].height<<", Excess Flow: "<<vertex[e.u].excess_flow<<endl;
                cout<<"Destination Vertex: "<<e.v<<"  Height: "<<vertex[e.v].height<<", Excess Flow: "<<vertex[e.v].excess_flow<<endl;
                cout<<"\n\n\n";
                if (edge[i].flow == edge[i].capacity)
                    continue;
        
                if (vertex[u].height > vertex[edge[i].v].height) {
                    int flow = min(edge[i].capacity - edge[i].flow,
                                vertex[u].excess_flow);
        
                    vertex[u].excess_flow -= flow;
                    vertex[edge[i].v].excess_flow += flow;
                    edge[i].flow += flow;
    
                    ReverseEdgeFlowUpdate(i, flow);
    
                    return true;
                }
            }
        }
        return false;
    }

    // function to Relabel vertex u
    void relabel(int u) {
        int maximum_height = INT_MAX;
        int n = edge.size();
        // To Find the adjacent with minimum height
        for (int i = 0; i < n; i++) {
            if (edge[i].u == u) {
                if (edge[i].flow == edge[i].capacity)
                    continue;
    
                // for Updating the minimum height
                if (vertex[edge[i].v].height < maximum_height) {
                    maximum_height = vertex[edge[i].v].height;
                    // updating the height of u
                    vertex[u].height = maximum_height + 1;
                }
            }
        }
    }

    void preflow(int source) {
        vertex[source].height = vertex.size();
        int n = edge.size();
        for (int i = 0; i < n; i++) {
            if (edge[i].u == source) {
                edge[i].flow = edge[i].capacity;
    
                // Initialize excess flow for adjacent v
                vertex[edge[i].v].excess_flow = vertex[edge[i].v].excess_flow + edge[i].flow;
                edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, source));
            }
        }
    }


    // To Update reverse flow for flow added on ith Edge
    void ReverseEdgeFlowUpdate(int i, int flow) {
        int u = edge[i].v;
        int v = edge[i].u;
        int j = 0, n = edge.size();
    
        while (j < n) {
            if (edge[j].v == v && edge[j].u == u) {
                edge[j].flow -= flow;
                return;
            }
            j++;
        }
        
        // adding the reverse Edge in the residual graph, if does not exits
        Edge e = Edge(0, flow, u, v);
        edge.push_back(e);
    }


    //Function to return an index of overflowing Vertex
    int overFlowVertex(vector<Vertex>& vertex) {
        int n = vertex.size();
        for (int i = 1; i < n-1; i++)
        if (vertex[i].excess_flow > 0)
                return i;
        return -1;
    }
   
public:

    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; i++)
            vertex.push_back(Vertex(0, 0));
    }

    void addEdge(int u, int v, int capacity) {
        edge.push_back(Edge(0, capacity, u, v));
    }

    // The main function is to print the maximum flow of the graph
    int getMaximumFlow(int source, int sink) {
        preflow(source);
        
        while (overFlowVertex(vertex) != -1) {
            int u = overFlowVertex(vertex);
            
            if (!push(u))
                relabel(u);
        }
        return vertex.back().excess_flow;
    }

};
  


int main() {
    Graph g(0);
    int V;  

    string filePath, str = "";
    cout<<"Enter destination of input file: ";
    cin >> filePath;

    ifstream file(filePath);
    bool firstLine = true;
    while (getline (file, str)) {
        if(str.length() == 0) continue;
        string w = "";
        int u = -1, v = -1, c = -1;
        for(char c: str) {
            if(c == ' ') {
                if(u == -1)      u = stoi(w);
                else if(v == -1) v = stoi(w);
                w = "";
            }
            else 
                w += c;
        }
        c = stoi(w);
        if(firstLine) {
            V = u;
            g = Graph(V);
            firstLine = false;
            continue;
        }

        g.addEdge(u-1, v-1, c);
    }
    file.close();
    int max_flow = g.getMaximumFlow(0, V-1);

    cout << "\n\n\nMaximum flow is :" << max_flow<<endl;
    return 0;
}