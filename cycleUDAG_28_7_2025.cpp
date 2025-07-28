#include <bits/stdc++.h>

using namespace std;

class Edge{
public:
    int src, dest, weight;
    Edge(int src, int dest, int w){
        this->src = src;
        this->dest = dest;
        this->weight=w;
    }
};
class Graph{
public:
    int V;
    vector<Edge> edges;
    Graph(int V){
        this->V = V;
    }
    void addEdge(int src, int dest, int w){
        edges.push_back(Edge(src,dest,w));
    }
    void showGraph(){
        for(auto& edge : edges){
            cout<<edge.src<<"----"<<edge.weight<<"---->"<<edge.dest<<"\n";
        }
    }


    bool isCycleUtil(vector<bool>& vis, vector<Edge>& edges, int u, int parent){
        vis[u] = true;
        for(auto& edge: edges){
            if (edge.src == u){
                if (!vis[edge.dest]){
                    if (isCycleUtil(vis,edges,edge.dest,edge.src)) return true;
                } else if(edge.dest != parent) return true;
            }
        }
        return false;
    }
    bool isCycle(){
        vector<bool> vis(this->V,false);
        for(int i = 0; i < this->V; ++i){
            if (!vis[i]){
                if (isCycleUtil(vis,edges,i,-1)) return true;
            }
        }
        return false;
    }
};

int main(){

    ifstream input("input.txt");
    int m, n;
    input>>m>>n;
    Graph g(m);
    for(int i  =0; i < n; ++i){
        int u,v,w;
        input>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    g.showGraph();
    (g.isCycle()) ? cout<<"true" : cout<<"false";
    return 0;
}
