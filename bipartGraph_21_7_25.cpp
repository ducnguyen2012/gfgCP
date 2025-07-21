#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
    int V;
    vector<vector<int>> adj;
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void showGraph(){
        for(int i = 0; i < this->V; ++i){
            for(auto v : adj[i]){
                cout<<"This is edge from ("<<i<<";"<<v<<") \n";
            }
        }
    }
    int getSize(){
        return this->V;
    }
};

void checkBipart(Graph g){
    // bipart if its neighbour not in the same set. 
    // we can achive this with color. source color != neighbour color
    // 0 is source color, -1 isn't colored, 1 is colored
    vector<int> color(g.getSize(),-1);
//    vector<bool> vis(g.getSize(),false);
    // visit like bfs
    queue<int>q;
    for(int i = 0; i < g.getSize(); ++i){
        if (color[i] == -1){
            color[i] = 0;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto& v : g.adj[u]) {
                    if (color[v] == -1){
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u]){
                        cout<<"This is not a bipart graph!"<<"\n";
                        return;
                    }
                }
            }
        }
    }
    
    
}

int main(){
    
    cout<<"This is bipart graph program: "<<"\n";
    Graph g(1000);
    int set1 = 500;
    int set2 = set1*2;
    std::uniform_int_distribution<> dis(0,10);
    for(int u = 0; u < set1; ++u){
        for(int v = set1; v < set2; ++v){
            int x = (int) rand()/RAND_MAX;
            if (x < 5){
                g.addEdge(u,v);
            }
        }
    }
    
    g.showGraph();
    checkBipart(g);
    return 0;
}
