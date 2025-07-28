#include <bits/stdc++.h>

using namespace std;
class Edge{
public:
    int src, dest, weight;
    Edge(int src, int dest, int weight){
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

class Graph{
public:
    int V;
    vector<Edge> edges;
    Graph(int V){
        this->V = V;
    }

    void addEdge(int u, int v, int w){
        edges.push_back(Edge(u,v,w));
    }
    void showGraph(){
        for(auto& edge : edges){
            cout<<edge.src<<"----"<<edge.weight<<"---->"<<edge.dest<<"\n";
        }
    }
};

int main(){
    ifstream myReadFile("input.txt");
    int m,n;
    myReadFile>>m>>n;
    Graph g(m);
    int u,v,w;
    for(int i = 0; i < n; ++i){
        myReadFile>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    g.showGraph();
    myReadFile.close();
    return 0;
}
