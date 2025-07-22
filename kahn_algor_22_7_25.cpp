#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
    int V;
    vector<vector<int>>adj;
    vector<int> inDegree;
    Graph(int V){
        this->V = V;
        adj.resize(this->V);
        inDegree.resize(this->V);
    }
    
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    
    void topoSort(){
        for(int i  =0; i < this->V; ++i){
            for(auto& v : adj[i]){
                inDegree[v] += 1;
            }
        }
        queue<int>q;
        for(int i  =0; i < this->V; ++i){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node  = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto& i : adj[node]){
                inDegree[i] -= 1;
                if (inDegree[i] == 0){
                    q.push(i);
                }
            }
        }
    }
};

int main(){
    // Number of nodes
    int V = 6;

    // Edges
    vector<vector<int> > edges
        = {{0, 1}, {1, 2}, {2, 3},
           {4, 5}, {5, 1}, {5, 2}};
    Graph g(V);
    for(int i = 0; i < edges.size(); ++i){
        g.addEdge(edges[i][0],edges[i][1]);
    }
    g.topoSort();

    
    return 0;
}
