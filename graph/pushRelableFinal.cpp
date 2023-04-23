
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int flow, capacity, u, v;

    Edge(int flow, int capacity, int u, int v) {
        this->flow = flow;
        this->capacity = capacity;
        this->u = u;
        this->v = v;
    }
};

class Vertex {
public:
    int height, e_flow;

    Vertex(int height, int e_flow) {
        this->height = height;
        this->e_flow = e_flow;
    }
};

class Graph {
public:
    int V;
    vector<Vertex> vertex;
    vector<Edge> edge;

    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; i++)
            vertex.push_back(Vertex(0, 0));
    }


    void printResidualGraph() {
        for (int i = 0; i < edge.size(); i += 1) {
            Edge forward_edge = edge[i];
            //Edge backward_edge = edge[i+1];
            int u = forward_edge.u;
            int v = forward_edge.v;
            int residual_capacity = forward_edge.capacity - forward_edge.flow;
            //int backward_edge_flow = backward_edge.flow;
            cout << "Edge: " << u+1<<" (H:"<<vertex[u].height<<" E:"<<vertex[u].e_flow<<") -> " << v+1<<" (H:"<<vertex[v].height<<" E:"<<vertex[v].e_flow<< ") Residual Capacity: " << residual_capacity << endl;
            // cout << "u: "<<u+1<<" Height: "<<vertex[u].height<<"   v: "<<v+1<<" Height: "<<vertex[v].height<<endl<<endl;
            //cout << "Residual graph edge: " << v+1<<"{Height="<<vertex[v].height<<"} " << " -> " << u+1<<"{Height="<<vertex[u].height<<"} " << " (residual capacity: " << backward_edge_flow << ")" << endl;
        }
    }

    void printResidualGraphForRelabel() {
        for (int i = 0; i < edge.size(); i += 1) {
            Edge forward_edge = edge[i];
            //Edge backward_edge = edge[i+1];
            int u = forward_edge.u;
            int v = forward_edge.v;
            //int backward_edge_flow = backward_edge.flow;
            cout << "Residual graph edge: " << u+1<<"{Height="<<vertex[u].height<<"} " << " -> " << v+1<<"{Height="<<vertex[v].height<<"} " << endl;
            //cout << "Residual graph edge: " << v+1<<"{Height="<<vertex[v].height<<"} " << " -> " << u+1<<"{Height="<<vertex[u].height<<"} " << " (residual capacity: " << backward_edge_flow << ")" << endl;
        }
    }

    void printFlowValue() {
        for (int i = 0; i < edge.size(); i += 1) {
            Edge forward_edge = edge[i];
            //Edge backward_edge = edge[i+1];
            int u = forward_edge.u;
            int v = forward_edge.v;
            int forward_edge_flow = forward_edge.flow;
            //int backward_edge_flow = backward_edge.flow;
            cout << "Edge: " << u+1 << " -> " << v+1 << " Flow : " << forward_edge_flow << endl;
            //cout << "Edge: " << v+1 << " -> " << u+1 << " Flow : " << backward_edge_flow << endl;
        }
    }
    bool push(int u) {
        for (int i = 0; i < edge.size(); i++) {
            if (edge[i].u == u) {
                if (edge[i].flow == edge[i].capacity)   //cannot push as already full
                    continue;
                if (vertex[u].height > vertex[edge[i].v].height) {
                    char key;
                    cout<<"----------------------------------------------------------------------------\n";
                    cout<<"The graph before pushing flow from "<<u+1<<" to "<<edge[i].v+1<<" is:"<<endl<<endl;                    
                    printResidualGraph();
                    //cin>>key;
                    int flow = min(edge[i].capacity - edge[i].flow,
                                   vertex[u].e_flow);
                    vertex[u].e_flow -= flow;
                    vertex[edge[i].v].e_flow += flow;
                    edge[i].flow += flow;
                    ReverseEdgeFlowUpdate(i, flow);
                    cout<<"\nThe graph after pushing flow from "<<u+1<<" to "<<edge[i].v+1<<" is:"<<endl<<endl;
                    printResidualGraph();
                    cout<<"----------------------------------------------------------------------------\n";
                    //cin>>key;
                    return true;
                }
            }
        }
        return false;
    }

    void relabel(int u) {
        int maximum_height = INT_MAX;
        for (int i = 0; i < edge.size(); i++) {
            if (edge[i].u == u) {
                if (edge[i].flow == edge[i].capacity)
                    continue;
                if (vertex[edge[i].v].height < maximum_height) {
                    cout<<"----------------------------------------------------------------------------\n";
                    cout<<"The graph before relabeling "<<edge[i].u+1 <<":-"<<endl<<endl;
                    printResidualGraph();
                    maximum_height = vertex[edge[i].v].height;
                    vertex[u].height = maximum_height + 1;
                    cout<<"\nThe graph after relabeling "<<edge[i].u+1 <<":-"<<endl<<endl;
                    printResidualGraph();
                    cout<<"----------------------------------------------------------------------------\n";
                }
            }
        }
    }

    void preflow(int source) {
        vertex[source].height = vertex.size();
        for (int i = 0; i < edge.size(); i++) {
            if (edge[i].u == source) {
                edge[i].flow = edge[i].capacity;
                vertex[edge[i].v].e_flow += edge[i].flow;
                edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, source));
            }
        }
    }

    void addEdge(int u, int v, int capacity) {
        edge.push_back(Edge(0, capacity, u, v));
    }

    void ReverseEdgeFlowUpdate(int i, int flow) {
        int u = edge[i].v;
        int v = edge[i].u;
        for (int j = 0; j < edge.size(); j++) {
            if (edge[j].v == v && edge[j].u == u) {
                edge[j].flow -= flow;
                return;
            }
        }
        Edge e(0, flow, u, v);
        edge.push_back(e);
    }

    int overFlowVertex(vector<Vertex>& vertex) {
        for (int i = 1; i < vertex.size() - 1; i++)
            if (vertex[i].e_flow > 0)
                return i;
        return -1;
    }

    int getMaximumFlow(int source, int sink) {
        preflow(source);
         // Together these two functions implement the discharge operation in the 
         // generic max-flow algorithm, pushing flow out of overfull vertices and raising their 
         // height if necessary to allow them to push again later.

        while (overFlowVertex(vertex) != -1) {  //atleast 1 vertex that has excess_flow
            int u = overFlowVertex(vertex);
            if (!push(u))
                relabel(u);
        }
        return vertex[sink].e_flow;
    }
};

    int main(){
        ifstream inputFile("input.txt");
        if (!inputFile) {
            cerr << "Error: could not open input file\n";
            return 1;
        }

        int N, v, e;
        inputFile >> v >> e;
        Graph g(v);
        for (int i = 0; i < e; i++) {
            int x, y, cap;
            inputFile >> x >> y >> cap;
            g.addEdge(x - 1, y - 1, cap); // assuming vertices are 1-indexed in the input file
        }
        int source, sink;
        inputFile >> source >> sink;
        int maxFlow = g.getMaximumFlow(source - 1, sink - 1); // assuming vertices are 1-indexed in the input file
        cout<<"Maximum flow: "<<maxFlow<<endl;
        cout<<"Flow value of edges in the residual graph:-"<<endl<<endl;
        g.printFlowValue();
        return 0;
    }

