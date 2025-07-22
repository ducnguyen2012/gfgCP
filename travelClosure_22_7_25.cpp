// check reach in transitive closure of a graph using DFS (i'm not finish, coding in 10 minutes). 

#include <bits/stdc++.h>

using namespace std;


bool checkReach(vector<vector<int>>& matrix, int src, vector<bool>& vis, int N){
    // this function will check reach from 0 - 3 
    
    vis[src]  = true;
    for(int i = 0; i < N; ++i){
        if (!vis[i] && matrix[src][i] == 1) {
            cout<<"check reach: "<<i<<"\n";
            checkReach(matrix,i,vis,N);
            
        }
    }
    if (src == N-1){
        return true;
    }
    return false;
}
class Graph{
public:
    int V;
    vector<vector<int>>adj;
    vector<vector<bool>>travelClosure;
    Graph(int V){
        this->V = V;
        adj.resize(V);
        travelClosure.resize(V);
        for(auto& row : travelClosure){
            row.resize(V,false);    
        }
        
    }
    void addEdge(int u, int v){
        // this is directed graph
        adj[u].push_back(v);
    }
    void transitiveClosure(){
        for(int i = 0; i < this->V; ++i){
            this->dfs(i,i);
        }
        for(int i = 0; i  < this->V; ++i){
            for(int j = 0; j < V; ++j){
                cout<<travelClosure[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    void dfs(int s, int v){
        // this dfs will check if it can reach from u to v. 
        // if it does, mark as 1.
        travelClosure[s][v] = true;
        for(auto& u : this->adj[v]){
            // remember why we have this condition
            if (!travelClosure[s][u]){
                dfs(s,u);
            }
        }
        
    }
};
int main(){
    
    // vector<vector<int>> matrix = {{0,1,1,0},{0,0,1,0},{0,0,0,1},{0,0,0,0}};
    // int N = 4;
    // vector<bool> vis(N,false);
    // cout<<checkReach(matrix,0,vis,N);
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Transitive closure matrix is \n";
    g.transitiveClosure();
    return 0;
    
}
