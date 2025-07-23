#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
    int V;
    vector<vector<pair<int,int>>>adj;
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }
    void addedge(int u, int v, int w){
        adj[u].push_back({v,w});
    }
    int minDistance(vector<int>&dist, vector<bool>& vis){
        int min_node = -1;
        int min_val = INT_MAX;
        for(int i = 0; i < this->V; ++i){
            if (!vis[i] && dist[i] < min_val){
                min_val = dist[i];
                min_node = i;
            }
        }
        return min_node;
    }
    void printGraph(vector<int>dist,int src){
        cout<<"This is shortestPath from source to dest: "<<"\n";
        for(int i = 0; i < this->V; ++i){
            cout<<src<<" ----> "<<dist[i]<<"\n";
        }
        cout<<"\n";
    }
    void shortestPath(int src){
        vector<bool>vis(this->V,false);
        vector<int>dist(this->V,INT_MAX);
        
        
        dist[src] = 0;
        for(int cnt = 0; cnt < this->V-1; ++cnt){
            int u = minDistance(dist,vis);
            vis[u] = true;
            for(auto& edge : adj[u]){
                int v = edge.first;
                int w = edge.second;
                if (!vis[v] && dist[u] != INT_MAX && dist[v] > dist[u] + w){
                    dist[v]  = dist[u] + w;
                }
            }
        }
        printGraph(dist,src);
    }
};
int main(){
    Graph g(4);
    g.addedge(0, 1, 1);
    g.addedge(0, 2, 10);
    g.addedge(1, 2, 3);
    g.addedge(2, 3, 2);
    g.addedge(3, 1, 0);
    g.addedge(3, 0, 8);
    g.shortestPath(0);
    
    return 0;
}
