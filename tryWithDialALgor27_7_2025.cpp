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
    vector<Edge> edge;
    Graph(int V){
        this->V = V;
    }
    void addEdge(int src, int dest, int weight){
        edge.push_back(Edge(src,dest,weight));
    }
    void showGraph(){
        cout<<"This is show graph: "<<"\n";
        for(auto& edge : this->edge){
            cout<<edge.src<<"----"<<edge.weight<<"---->"<<edge.dest<<"\n";
        }
    }
    
    int minDistance(vector<int>& dist, vector<bool>& vis){
        int min_idx = -1;
        int min_dist = INT_MAX;
        for(int i = 0; i < this->V; ++i){
            if (!vis[i] && min_dist > dist[i]){
                min_dist = dist[i];
                min_idx = i;
            }
        }
        return min_idx;
    }
    void showDijkstra(vector<int>& dist, int source){
        cout<<"This is function show dijkstra"<<"\n";
        for(int i  =0; i < this->V; ++i){
            cout<<source<<" -----> "<<i<<" with shortest path is: "<<dist[i]<<"\n";
        }
    }
    void dijkstra(int src){
        vector<bool> vis(this->V,false);
        vector<int>dist(this->V,INT_MAX);
        dist[src] = 0;
        
        for(int cnt = 0; cnt < this->V-1; ++cnt){
            int u = minDistance(dist,vis);
            vis[u] = true;
            for(auto& ed : edge){
                int src = ed.src;
                int dest = ed.dest;
                int weight = ed.weight;
                if (src == u && !vis[dest] && dist[u] != INT_MAX && dist[dest] 
                > dist[u] + weight){
                    dist[dest] = dist[u] + weight;
                }
            }
        }
        showDijkstra(dist,src);
        
    }
};



int main(){
    int V = 9; // 0 to 8
    Graph g(V);

    // Add edges from the image
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    
    g.showGraph();
    
    g.dijkstra(0);
    
    
    return 0;
}
