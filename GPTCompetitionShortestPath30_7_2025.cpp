#! =========================== my original code =============================
#include <bits/stdc++.h>

using namespace std;

int minDistance(vector<int>& dist, vector<bool>& vis, int V){
    int min_idx = -1;
    int min_val = INT_MAX;

    for(int i = 0; i < V; ++i){
        if (!vis[i] && min_val > dist[i]) {
            min_val = dist[i];
            min_idx = i;
        }

    }
    return min_idx;
}
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
    void addEdge(int src, int dest, int weight){
        edges.push_back(Edge(src,dest,weight));
    }
};

vector<int> shortestPath(int n, int src,
                         vector<Edge>& edges, int V){
    vector<int> res;
    vector<int> dist(V, INT_MAX);
    vector<bool> vis(V,false);
    dist[src]  = 0;
    for(int cnt = 0; cnt < V-1; ++cnt){
        int u  = minDistance(dist,vis,V);
        vis[u] = true;
        for(auto& edge : edges){
            if (edge.src == u){
                if(!vis[edge.dest] && dist[edge.src] != INT_MAX
                    && dist[edge.dest] > dist[edge.src] + edge.weight){
                    dist[edge.dest] = dist[edge.src] + edge.weight;
                }
            }
        }
    }
    return dist;

}
int main() {
    int n;
    int src;
    ifstream readfile("input.txt");
    readfile>>n>>src;
    Graph g(n);
    int first, dest, weight;
    int V = INT_MIN;
    for(int i = 0; i < n; ++i){
        readfile>>first>>dest>>weight;
        V = max({V,first,dest});
        g.addEdge(first,dest,weight);
    }
    V = V+1;
    auto start = chrono::high_resolution_clock::now();
    vector<int> res = shortestPath(n,src,g.edges,V);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli>duration = end - start;

    cout<<"time taken: "<<duration.count()<<" ms \n";
    for(int i = 0; i < V; ++i){
        cout<<src<<"----->"<<i<<" with weight = "<<res[i]<<"\n";
    }
    return 0;
}




#! =========================== optimize with priority_queue ====================================
#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(int V, int src
                         , const
                         vector<vector<pair<int, int>>>&adj ){
    vector<int> dist(V,INT_MAX);
    vector<bool> vis(V,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>
                   , greater<>> pq;
    dist[src] = 0;
    pq.push({dist[src],src});
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // purn all edge INT_MAX
        // to optimize
        for(auto& [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){

    ifstream readFile("input.txt");
    int m, src;
    readFile>>m>>src;

    vector<tuple<int,int,int>> rawEdges;
    int u,  v,  w;
    int maxNode = INT_MIN;
    for(int i = 0; i < m; ++i){
        readFile>>u>>v>>w;
        rawEdges.push_back({u,v,w});
        maxNode = max({maxNode,u,v});
    }
    int V = maxNode + 1;
    vector<vector<pair<int,int>>>adj(V);
    for(auto& [u, v, w] : rawEdges){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    auto start = chrono::high_resolution_clock::now();
    vector<int> res = shortestPath(V,src,adj);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double,milli>duration1 = end - start;

    cout<<"Time complexity: "<<duration1.count()<<" ms \n";
    cout<<"result: "<<"\n";
    for(int i = 0; i < V; ++i){
        cout<<src<<"---->"<<i<<" with weight: "<<res[i]<<"\n";
    }
    return 0;
}

#! note: you only see optimization if you test with larger input scale!!!!

