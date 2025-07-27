#include <bits/stdc++.h>

using namespace std;

bool isCyclicUtil(vector<vector<int>>& adj, vector<bool>& vis,vector<bool>& recStack, int currVer){
    if (recStack[currVer]) return true;
    if (vis[currVer]) return false;
    
    
    vis[currVer] = true;
    recStack[currVer] = true;
    for(auto& i : adj[currVer]){
        if (isCyclicUtil(adj,vis,recStack,i)) return true;
    }
    recStack[currVer] = false;
    return false;
    
}

bool isCyclic(int V, vector<vector<int>>& edges){
    vector<bool> vis(V,false);
    vector<bool> recStack(V,false);
    vector<vector<int>>adj(V);
    for(auto& edge: edges){
        adj[edge[0]].push_back(edge[1]);
    }
    for(int i  =0; i < V; ++i){
        if (!vis[i] && isCyclicUtil(adj,vis,recStack,i)){
            return true;
        }
    }
    return false;
}

int main(){
    
    int V = 4; // Number of vertices

    // Directed edges of the graph
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};

    // Output whether the graph contains a cycle
    cout << (isCyclic(V, edges) ? "true" : "false") << endl;
    
    
    return 0;
}
